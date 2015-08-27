#ifndef UnsafePersistent_h
#define UnsafePersistent_h

#include "WrapperTypeInfo.h"

#include <include/v8.h>

namespace Canvas2D 
{

template<class KeyType> class DOMWrapperMap;

// An unsafe way to pass Persistent handles around. Do not use unless you know
// what you're doing. UnsafePersistent is only safe to use when we know that the
// memory pointed by the it is not going away: 1) When GC cannot happen while
// the UnsafePersistent is alive or 2) when there is a strong Persistent keeping
// the memory alive while the UnsafePersistent is alive.
template<typename T> class UnsafePersistent
{
public:
    UnsafePersistent() : m_value(0) { }
    explicit UnsafePersistent(T* value) : m_value(value) { }
    explicit UnsafePersistent(v8::Persistent<T>& handle)
    {
		m_value = handle.ClearWeak<T>();
    }

    UnsafePersistent(v8::Isolate* isolate, v8::Handle<T>& handle)
    {
        v8::Persistent<T> persistent(isolate, handle);
		m_value = *handle;
    }

    T* value() const
    {
        return m_value;
    }

    template<typename V8T, typename U>
    inline bool setReturnValueWithSecurityCheck(v8::ReturnValue<v8::Value> returnValue, U* object)
    {
        // Security: always guard against malicious tampering.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(isEmpty() || value()->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex) == V8T::toInternalPointer(object));
        returnValue.Set(*persistent());
        return !isEmpty();
    }

    inline bool setReturnValue(v8::ReturnValue<v8::Value> returnValue)
    {
        returnValue.Set(*persistent());
        return !isEmpty();
    }

    // This is incredibly unsafe: the handle is valid only when this
    // UnsafePersistent is alive and valid (see class level comment).
    v8::Persistent<T>* persistent()
    {
        v8::Persistent<T>* handle = reinterpret_cast<v8::Persistent<T>*>(&m_value);
        return handle;
    }

    void setReferenceFrom(const v8::Persistent<v8::Object>& parent, v8::Isolate* isolate)
    {
        isolate->SetReference(parent, *persistent());
    }

    void dispose()
    {
        persistent()->Reset();
        m_value = 0;
    }

    void clear()
    {
        m_value = 0;
    }

    v8::Local<T> newLocal(v8::Isolate* isolate)
    {
        return v8::Local<T>::New(isolate, *persistent());
    }

    bool isEmpty() const
    {
        return !m_value;
    }

private:
    T* m_value;
};

} // namespace WebCore

#endif // UnsafePersistent_h
