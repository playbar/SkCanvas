/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkTInternalLList_DEFINED
#define SkTInternalLList_DEFINED

#include "SkTypes.h"

/**
 * Helper class to automatically initialize the doubly linked list created pointers.
 */
template <typename T> class SkPtrWrapper {
  public:
      SkPtrWrapper() : fPtr(NULL) {}
      SkPtrWrapper& operator =(T* ptr) { fPtr = ptr; return *this; }
      operator T*() const { return fPtr; }
      T* operator->() { return fPtr; }
  private:
      T* fPtr;
};


/**
 * This macro creates the member variables required by the SkTInternalLList class. It should be
 * placed in the private section of any class that will be stored in a double linked list.
 */
#define SK_DECLARE_INTERNAL_LLIST_INTERFACE(ClassName)              \
    friend class SkTInternalLList<ClassName>;                       \
    /* back pointer to the owning list - for debugging */           \
    SkDEBUGCODE(SkPtrWrapper<SkTInternalLList<ClassName> > fList;)  \
    SkPtrWrapper<ClassName> fPrev;                                  \
    SkPtrWrapper<ClassName> fNext

/**
 * This class implements a templated internal doubly linked list data structure.
 */
template <class T> class SkTInternalLList : public SkNoncopyable {
public:
    SkTInternalLList()
        : fHead(NULL)
        , fTail(NULL) {
    }

    void remove(T* entry) {

        T* prev = entry->fPrev;
        T* next = entry->fNext;

        if (NULL != prev) {
            prev->fNext = next;
        } else {
            fHead = next;
        }
        if (NULL != next) {
            next->fPrev = prev;
        } else {
            fTail = prev;
        }

        entry->fPrev = NULL;
        entry->fNext = NULL;
    }

    void addToHead(T* entry) {

        entry->fPrev = NULL;
        entry->fNext = fHead;
        if (NULL != fHead) {
            fHead->fPrev = entry;
        }
        fHead = entry;
        if (NULL == fTail) {
            fTail = entry;
        }
    }

    void addToTail(T* entry) {

        entry->fPrev = fTail;
        entry->fNext = NULL;
        if (NULL != fTail) {
            fTail->fNext = entry;
        }
        fTail = entry;
        if (NULL == fHead) {
            fHead = entry;
        }
    }

    /**
     * Inserts a new list entry before an existing list entry. The new entry must not already be
     * a member of this or any other list. If existingEntry is NULL then the new entry is added
     * at the tail.
     */
    void addBefore(T* newEntry, T* existingEntry) {

        if (NULL == existingEntry) {
            this->addToTail(newEntry);
            return;
        }

        newEntry->fNext = existingEntry;
        T* prev = existingEntry->fPrev;
        existingEntry->fPrev = newEntry;
        newEntry->fPrev = prev;
        if (NULL == prev) {
            fHead = newEntry;
        } else {
            prev->fNext = newEntry;
        }
#ifdef SK_DEBUG
        newEntry->fList = this;
#endif
    }

    /**
     * Inserts a new list entry after an existing list entry. The new entry must not already be
     * a member of this or any other list. If existingEntry is NULL then the new entry is added
     * at the head.
     */
    void addAfter(T* newEntry, T* existingEntry) {
        if (NULL == existingEntry) {
            this->addToHead(newEntry);
            return;
        }

        newEntry->fPrev = existingEntry;
        T* next = existingEntry->fNext;
        existingEntry->fNext = newEntry;
        newEntry->fNext = next;
        if (NULL == next) {
            fTail = newEntry;
        } else {
            next->fPrev = newEntry;
        }
    }

    bool isEmpty() const {
        return NULL == fHead && NULL == fTail;
    }

    T* head() { return fHead; }
    T* tail() { return fTail; }

    class Iter {
    public:
        enum IterStart {
            kHead_IterStart,
            kTail_IterStart
        };

        Iter() : fCurr(NULL) {}
        Iter(const Iter& iter) : fCurr(iter.fCurr) {}
        Iter& operator= (const Iter& iter) { fCurr = iter.fCurr; return *this; }

        T* init(const SkTInternalLList& list, IterStart startLoc) {
            if (kHead_IterStart == startLoc) {
                fCurr = list.fHead;
            } else {
                fCurr = list.fTail;
            }

            return fCurr;
        }

        T* get() { return fCurr; }

        /**
         * Return the next/previous element in the list or NULL if at the end.
         */
        T* next() {
            if (NULL == fCurr) {
                return NULL;
            }

            fCurr = fCurr->fNext;
            return fCurr;
        }

        T* prev() {
            if (NULL == fCurr) {
                return NULL;
            }

            fCurr = fCurr->fPrev;
            return fCurr;
        }

    private:
        T* fCurr;
    };

private:
    T* fHead;
    T* fTail;

    typedef SkNoncopyable INHERITED;
};

#endif
