
/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */



#include "GrResourceCache.h"
#include "GrResource.h"


GrResourceKey::ResourceType GrResourceKey::GenerateResourceType() {
    static int32_t gNextType = 0;

    int32_t type = sk_atomic_inc(&gNextType);
    if (type >= (1 << 8 * sizeof(ResourceType))) {
        GrCrash("Too many Resource Types");
    }

    return static_cast<ResourceType>(type);
}

///////////////////////////////////////////////////////////////////////////////

GrResourceEntry::GrResourceEntry(const GrResourceKey& key, GrResource* resource)
        : fKey(key), fResource(resource) {
    // we assume ownership of the resource, and will unref it when we die
    resource->ref();
}

GrResourceEntry::~GrResourceEntry() {
    fResource->setCacheEntry(NULL);
    fResource->unref();
}


///////////////////////////////////////////////////////////////////////////////

GrResourceCache::GrResourceCache(int maxCount, size_t maxBytes) :
        fMaxCount(maxCount),
        fMaxBytes(maxBytes) {

    fEntryCount                   = 0;
    fEntryBytes                   = 0;
    fClientDetachedCount          = 0;
    fClientDetachedBytes          = 0;

    fPurging                      = false;

    fOverbudgetCB                 = NULL;
    fOverbudgetData               = NULL;
}

GrResourceCache::~GrResourceCache() {

    EntryList::Iter iter;

    // Unlike the removeAll, here we really remove everything, including locked resources.
    while (GrResourceEntry* entry = fList.head()) {

        // remove from our cache
        fCache.remove(entry->fKey, entry);

        // remove from our llist
        this->internalDetach(entry);

        delete entry;
    }
}

void GrResourceCache::getLimits(int* maxResources, size_t* maxResourceBytes) const{
    if (NULL != maxResources) {
        *maxResources = fMaxCount;
    }
    if (NULL != maxResourceBytes) {
        *maxResourceBytes = fMaxBytes;
    }
}

void GrResourceCache::setLimits(int maxResources, size_t maxResourceBytes) {
    bool smaller = (maxResources < fMaxCount) || (maxResourceBytes < fMaxBytes);

    fMaxCount = maxResources;
    fMaxBytes = maxResourceBytes;

    if (smaller) {
        this->purgeAsNeeded();
    }
}

void GrResourceCache::internalDetach(GrResourceEntry* entry,
                                     BudgetBehaviors behavior) {
    fList.remove(entry);

    // update our stats
    if (kIgnore_BudgetBehavior == behavior) {
        fClientDetachedCount += 1;
        fClientDetachedBytes += entry->resource()->sizeInBytes();

    } else {

        fEntryCount -= 1;
        fEntryBytes -= entry->resource()->sizeInBytes();
    }
}

void GrResourceCache::attachToHead(GrResourceEntry* entry,
                                   BudgetBehaviors behavior) {
    fList.addToHead(entry);

    // update our stats
    if (kIgnore_BudgetBehavior == behavior) {
        fClientDetachedCount -= 1;
        fClientDetachedBytes -= entry->resource()->sizeInBytes();
    } else {

        fEntryCount += 1;
        fEntryBytes += entry->resource()->sizeInBytes();
    }
}

// This functor just searches for an entry with only a single ref (from
// the texture cache itself). Presumably in this situation no one else
// is relying on the texture.
class GrTFindUnreffedFunctor {
public:
    bool operator()(const GrResourceEntry* entry) const {
        return entry->resource()->unique();
    }
};

GrResource* GrResourceCache::find(const GrResourceKey& key, uint32_t ownershipFlags) {
    GrResourceEntry* entry = NULL;

    if (ownershipFlags & kNoOtherOwners_OwnershipFlag) {
        GrTFindUnreffedFunctor functor;

        entry = fCache.find<GrTFindUnreffedFunctor>(key, functor);
    } else {
        entry = fCache.find(key);
    }

    if (NULL == entry) {
        return NULL;
    }

    if (ownershipFlags & kHide_OwnershipFlag) {
        this->makeExclusive(entry);
    } else {
        // Make this resource MRU
        this->internalDetach(entry);
        this->attachToHead(entry);
    }

    return entry->fResource;
}

void GrResourceCache::addResource(const GrResourceKey& key,
                                  GrResource* resource,
                                  uint32_t ownershipFlags) {
    // we don't expect to create new resources during a purge. In theory
    // this could cause purgeAsNeeded() into an infinite loop (e.g.
    // each resource destroyed creates and locks 2 resources and
    // unlocks 1 thereby causing a new purge).

    GrResourceEntry* entry = SkNEW_ARGS(GrResourceEntry, (key, resource));
    resource->setCacheEntry(entry);

    this->attachToHead(entry);
    fCache.insert(key, entry);

    if (ownershipFlags & kHide_OwnershipFlag) {
        this->makeExclusive(entry);
    }

}

void GrResourceCache::makeExclusive(GrResourceEntry* entry) {

    // When scratch textures are detached (to hide them from future finds) they
    // still count against the resource budget
    this->internalDetach(entry, kIgnore_BudgetBehavior);
    fCache.remove(entry->key(), entry);

#ifdef SK_DEBUG
    fExclusiveList.addToHead(entry);
#endif
}

void GrResourceCache::removeInvalidResource(GrResourceEntry* entry) {
    // If the resource went invalid while it was detached then purge it
    // This can happen when a 3D context was lost,
    // the client called GrContext::contextDestroyed() to notify Gr,
    // and then later an SkGpuDevice's destructor releases its backing
    // texture (which was invalidated at contextDestroyed time).
    fClientDetachedCount -= 1;
    fEntryCount -= 1;
    size_t size = entry->resource()->sizeInBytes();
    fClientDetachedBytes -= size;
    fEntryBytes -= size;
}

void GrResourceCache::makeNonExclusive(GrResourceEntry* entry) {

#ifdef SK_DEBUG
    fExclusiveList.remove(entry);
#endif

    if (entry->resource()->isValid()) {
        // Since scratch textures still count against the cache budget even
        // when they have been removed from the cache, re-adding them doesn't
        // alter the budget information.
        attachToHead(entry, kIgnore_BudgetBehavior);
        fCache.insert(entry->key(), entry);
    } else {
        this->removeInvalidResource(entry);
    }
}

/**
 * Destroying a resource may potentially trigger the unlock of additional
 * resources which in turn will trigger a nested purge. We block the nested
 * purge using the fPurging variable. However, the initial purge will keep
 * looping until either all resources in the cache are unlocked or we've met
 * the budget. There is an assertion in createAndLock to check against a
 * resource's destructor inserting new resources into the cache. If these
 * new resources were unlocked before purgeAsNeeded completed it could
 * potentially make purgeAsNeeded loop infinitely.
 *
 * extraCount and extraBytes are added to the current resource totals to account
 * for incoming resources (e.g., GrContext is about to add 10MB split between
 * 10 textures).
 */
void GrResourceCache::purgeAsNeeded(int extraCount, size_t extraBytes) {
    if (fPurging) {
        return;
    }

    fPurging = true;

    this->purgeInvalidated();

    this->internalPurge(extraCount, extraBytes);
    if (((fEntryCount+extraCount) > fMaxCount ||
        (fEntryBytes+extraBytes) > fMaxBytes) &&
        NULL != fOverbudgetCB) {
        // Despite the purge we're still over budget. See if Ganesh can
        // release some resources and purge again.
        if ((*fOverbudgetCB)(fOverbudgetData)) {
            this->internalPurge(extraCount, extraBytes);
        }
    }

    fPurging = false;
}

void GrResourceCache::purgeInvalidated() {
    SkTDArray<GrResourceInvalidatedMessage> invalidated;
    fInvalidationInbox.poll(&invalidated);

    for (int i = 0; i < invalidated.count(); i++) {
        // We're somewhat missing an opportunity here.  We could use the
        // default find functor that gives us back resources whether we own
        // them exclusively or not, and when they're not exclusively owned mark
        // them for purging later when they do become exclusively owned.
        //
        // This is complicated and confusing.  May try this in the future.  For
        // now, these resources are just LRU'd as if we never got the message.
        GrResourceEntry* entry = fCache.find(invalidated[i].key, GrTFindUnreffedFunctor());
        if (entry) {
            this->deleteResource(entry);
        }
    }
}

void GrResourceCache::deleteResource(GrResourceEntry* entry) {

    // remove from our cache
    fCache.remove(entry->key(), entry);

    // remove from our llist
    this->internalDetach(entry);
    delete entry;
}

void GrResourceCache::internalPurge(int extraCount, size_t extraBytes) {

    bool withinBudget = false;
    bool changed = false;

    // The purging process is repeated several times since one pass
    // may free up other resources
    do {
        EntryList::Iter iter;

        changed = false;

        // Note: the following code relies on the fact that the
        // doubly linked list doesn't invalidate its data/pointers
        // outside of the specific area where a deletion occurs (e.g.,
        // in internalDetach)
        GrResourceEntry* entry = iter.init(fList, EntryList::Iter::kTail_IterStart);

        while (NULL != entry) {
            if ((fEntryCount+extraCount) <= fMaxCount &&
                (fEntryBytes+extraBytes) <= fMaxBytes) {
                withinBudget = true;
                break;
            }

            GrResourceEntry* prev = iter.prev();
            if (entry->fResource->unique()) {
                changed = true;
                this->deleteResource(entry);
            }
            entry = prev;
        }
    } while (!withinBudget && changed);
}

void GrResourceCache::purgeAllUnlocked() {
    // we can have one GrResource holding a lock on another
    // so we don't want to just do a simple loop kicking each
    // entry out. Instead change the budget and purge.

    size_t savedMaxBytes = fMaxBytes;
    int savedMaxCount = fMaxCount;
    fMaxBytes = (size_t) -1;
    fMaxCount = 0;
    this->purgeAsNeeded();


    fMaxBytes = savedMaxBytes;
    fMaxCount = savedMaxCount;
}

