#ifndef V8DOMWrapper_h
#define V8DOMWrapper_h

#include "DOMDataStore.h"
#include <include/v8.h>
#include "PassRefPtr.h"
#include "RawPtr.h"

namespace Canvas2D {

struct WrapperTypeInfo;

    class V8DOMWrapper 
	{
    public:
        static v8::Local<v8::Object> createWrapper(v8::Handle<v8::Object> creationContext, const WrapperTypeInfo*, void*, v8::Isolate*);

        template<typename V8T, typename T>
        static inline v8::Handle<v8::Object> associateObjectWithWrapper(PassRefPtr<T>, const WrapperTypeInfo*, v8::Handle<v8::Object>, v8::Isolate*, WrapperConfiguration::Lifetime);
        template<typename V8T, typename T>
        static inline v8::Handle<v8::Object> associateObjectWithWrapper(RawPtr<T> object, const WrapperTypeInfo* type, v8::Handle<v8::Object> wrapper, v8::Isolate* isolate, WrapperConfiguration::Lifetime lifetime) { return associateObjectWithWrapper<V8T, T>(object.get(), type, wrapper, isolate, lifetime); }
        template<typename V8T, typename T>
        static inline v8::Handle<v8::Object> associateObjectWithWrapper(T*, const WrapperTypeInfo*, v8::Handle<v8::Object>, v8::Isolate*, WrapperConfiguration::Lifetime);
        static inline void setNativeInfo(v8::Handle<v8::Object>, const WrapperTypeInfo*, void*);
        static inline void setNativeInfoWithPersistentHandle(v8::Handle<v8::Object>, const WrapperTypeInfo*, void* );
        static inline void clearNativeInfo(v8::Handle<v8::Object>, const WrapperTypeInfo*);

        static bool isDOMWrapper(v8::Handle<v8::Value>);
    };

    inline void V8DOMWrapper::setNativeInfo(v8::Handle<v8::Object> wrapper, const WrapperTypeInfo* type, void* object)
    {
        wrapper->SetAlignedPointerInInternalField(v8DOMWrapperObjectIndex, object);
        wrapper->SetAlignedPointerInInternalField(v8DOMWrapperTypeIndex, const_cast<WrapperTypeInfo*>(type));
    }

    inline void V8DOMWrapper::setNativeInfoWithPersistentHandle(v8::Handle<v8::Object> wrapper, const WrapperTypeInfo* type, void* object)
    {
        wrapper->SetAlignedPointerInInternalField(v8DOMWrapperObjectIndex, object);
        wrapper->SetAlignedPointerInInternalField(v8DOMWrapperTypeIndex, const_cast<WrapperTypeInfo*>(type));
        // Persistent handle is stored in the last internal field.
        wrapper->SetAlignedPointerInInternalField(wrapper->InternalFieldCount() - 1, NULL);
    }

    inline void V8DOMWrapper::clearNativeInfo(v8::Handle<v8::Object> wrapper, const WrapperTypeInfo* type)
    {
        wrapper->SetAlignedPointerInInternalField(v8DOMWrapperTypeIndex, const_cast<WrapperTypeInfo*>(type));
        wrapper->SetAlignedPointerInInternalField(v8DOMWrapperObjectIndex, 0);
    }

    template<typename V8T, typename T>
    inline v8::Handle<v8::Object> V8DOMWrapper::associateObjectWithWrapper(PassRefPtr<T> object, const WrapperTypeInfo* type, v8::Handle<v8::Object> wrapper, v8::Isolate* isolate, WrapperConfiguration::Lifetime lifetime)
    {
        setNativeInfo(wrapper, type, V8T::toInternalPointer(object.get()));
        SkASSERT(isDOMWrapper(wrapper));
        WrapperConfiguration configuration = buildWrapperConfiguration(object.get(), lifetime);
        DOMDataStore::setWrapper<V8T>(object.leakRef(), wrapper, isolate, configuration);
        return wrapper;
    }

    template<typename V8T, typename T>
    inline v8::Handle<v8::Object> V8DOMWrapper::associateObjectWithWrapper(T* object, const WrapperTypeInfo* type, v8::Handle<v8::Object> wrapper, v8::Isolate* isolate, WrapperConfiguration::Lifetime lifetime)
    {
        setNativeInfoWithPersistentHandle(wrapper, type, V8T::toInternalPointer(object), new Persistent<T>(object));
        SkASSERT(isDOMWrapper(wrapper));
        WrapperConfiguration configuration = buildWrapperConfiguration(object, lifetime);
        DOMDataStore::setWrapper<V8T>(object, wrapper, isolate, configuration);
        return wrapper;
    }

    class V8WrapperInstantiationScope 
	{
    public:
        V8WrapperInstantiationScope(v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
            : m_didEnterContext(false)
            , m_context(isolate->GetCurrentContext())
        {
            // FIXME: Remove all empty creationContexts from caller sites.
            // If a creationContext is empty, we will end up creating a new object
            // in the context currently entered. This is wrong.
            if (creationContext.IsEmpty())
                return;
            v8::Handle<v8::Context> contextForWrapper = creationContext->CreationContext();
            // For performance, we enter the context only if the currently running context
            // is different from the context that we are about to enter.
            if (contextForWrapper == m_context)
                return;
            m_context = v8::Local<v8::Context>::New(isolate, contextForWrapper);
            m_didEnterContext = true;
            m_context->Enter();
        }

        ~V8WrapperInstantiationScope()
        {
            if (!m_didEnterContext)
                return;
            m_context->Exit();
        }

        v8::Handle<v8::Context> context() const { return m_context; }

    private:
        bool m_didEnterContext;
        v8::Handle<v8::Context> m_context;
    };

}

#endif // V8DOMWrapper_h
