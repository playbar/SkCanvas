#ifndef ScopedPersistent_h
#define ScopedPersistent_h

#include <include/v8.h>
#include "Noncopyable.h"

namespace Canvas2D
{

template<typename T>
class ScopedPersistent
{
    WTF_MAKE_NONCOPYABLE(ScopedPersistent);
public:
    ScopedPersistent() { }

    ScopedPersistent(v8::Isolate* isolate, v8::Handle<T> handle)
        : m_handle(isolate, handle)
    {
    }

    ~ScopedPersistent()
    {
        clear();
    }

    v8::Local<T> newLocal(v8::Isolate* isolate) const
    {
        return v8::Local<T>::New(isolate, m_handle);
    }

    template<typename P>
    void setWeak(P* parameters, void (*callback)(const v8::WeakCallbackData<T, P>&))
    {
        m_handle.SetWeak(parameters, callback);
    }

    bool isEmpty() const { return m_handle.IsEmpty(); }
    bool isWeak() const { return m_handle.IsWeak(); }

    void set(v8::Isolate* isolate, v8::Handle<T> handle)
    {
        m_handle.Reset(isolate, handle);
    }

    // Note: This is clear in the OwnPtr sense, not the v8::Handle sense.
    void clear()
    {
        m_handle.Reset();
    }

    bool operator==(const ScopedPersistent<T>& other)
    {
        return m_handle == other.m_handle;
    }

    template <class S>
    bool operator==(const v8::Handle<S> other) const
    {
        return m_handle == other;
    }

private:
    // FIXME: This function does an unsafe handle access. Remove it.
    friend class V8AbstractEventListener;
    friend class V8PerIsolateData;
    v8::Persistent<T>& getUnsafe()
    {
        return m_handle;
    }

    v8::Persistent<T> m_handle;
};

} // namespace WebCore

#endif // ScopedPersistent_h
