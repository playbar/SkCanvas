#ifndef DOMWrapperMap_h
#define DOMWrapperMap_h

#include "UnsafePersistent.h"
#include "WrapperTypeInfo.h"
#include <include/v8.h>
#include "SkTypes.h"
#include "map"

namespace WebCore {

template<class KeyType>
class DOMWrapperMap {
public:
    typedef std::map<KeyType*, UnsafePersistent<v8::Object> > MapType;

    explicit DOMWrapperMap(v8::Isolate* isolate)
        : m_isolate(isolate)
    {
    }

    v8::Handle<v8::Object> newLocal(KeyType* key, v8::Isolate* isolate)
    {
        return m_map.get(key).newLocal(isolate);
    }

    bool setReturnValueFrom(v8::ReturnValue<v8::Value> returnValue, KeyType* key)
    {
        typename MapType::iterator it = m_map.find(key);
        if (it == m_map.end())
            return false;
        returnValue.Set(*(it->value.persistent()));
        return true;
    }

    void setReference(const v8::Persistent<v8::Object>& parent, KeyType* key, v8::Isolate* isolate)
    {
        m_map.get(key).setReferenceFrom(parent, isolate);
    }

    bool containsKey(KeyType* key)
    {
        return m_map.find(key) != m_map.end();
    }

    bool containsKeyAndValue(KeyType* key, v8::Handle<v8::Object> value)
    {
        typename MapType::iterator it = m_map.find(key);
        if (it == m_map.end())
            return false;
        return *(it->value.persistent()) == value;
    }

    void set(KeyType* key, v8::Handle<v8::Object> wrapper, const WrapperConfiguration& configuration)
    {
        ASSERT(static_cast<KeyType*>(toNative(wrapper)) == key);
        v8::Persistent<v8::Object> persistent(m_isolate, wrapper);
        configuration.configureWrapper(&persistent);
        persistent.SetWeak(this, &setWeakCallback);
        typename MapType::AddResult result = m_map.add(key, UnsafePersistent<v8::Object>());
        ASSERT(result.isNewEntry);
        // FIXME: Stop handling this case once duplicate wrappers are guaranteed not to be created.
        if (!result.isNewEntry)
            result.storedValue->value.dispose();
        result.storedValue->value = UnsafePersistent<v8::Object>(persistent);
    }

    void clear()
    {
        v8::HandleScope scope(m_isolate);
        while (!m_map.isEmpty()) {
            // Swap out m_map on each iteration to ensure any wrappers added due to side effects of the loop are cleared.
            MapType map;
            map.swap(m_map);
            for (typename MapType::iterator it = map.begin(); it != map.end(); ++it) {
                releaseObject(it->value.newLocal(m_isolate));
                it->value.dispose();
            }
        }
    }

    void removeAndDispose(KeyType* key)
    {
        typename MapType::iterator it = m_map.find(key);
        ASSERT_WITH_SECURITY_IMPLICATION(it != m_map.end());
        it->value.dispose();
        m_map.remove(it);
    }

private:
    static void setWeakCallback(const v8::WeakCallbackData<v8::Object, DOMWrapperMap<KeyType> >&);

    v8::Isolate* m_isolate;
    MapType m_map;
};

template<>
inline void DOMWrapperMap<void>::setWeakCallback(const v8::WeakCallbackData<v8::Object, DOMWrapperMap<void> >& data)
{
    void* key = static_cast<void*>(toNative(data.GetValue()));
    SkASSERT(*data.GetParameter()->m_map.get(key).persistent() == data.GetValue());
    data.GetParameter()->removeAndDispose(key);
    releaseObject(data.GetValue());
}

} // namespace WebCore

#endif // DOMWrapperMap_h
