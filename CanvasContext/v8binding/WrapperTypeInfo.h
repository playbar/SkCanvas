#ifndef WrapperTypeInfo_h
#define WrapperTypeInfo_h

#include "include/v8.h"

enum InternalFields
{
	kWrapperInfoIndex,
	kEncodedValueIndex,
	kNumberOfInternalFields,
};

enum GinEmbedder {
	kEmbedderNativeGin,
	kEmbedderBlink,
};

namespace Canvas2D
{

    class ActiveDOMObject;
    class EventTarget;
    class Node;

    static const int v8DOMWrapperTypeIndex = static_cast<int>(kWrapperInfoIndex);
    static const int v8DOMWrapperObjectIndex = static_cast<int>(kEncodedValueIndex);
    static const int v8DefaultWrapperInternalFieldCount = static_cast<int>(kNumberOfInternalFields);
    static const int v8PrototypeTypeIndex = 0;
    static const int v8PrototypeInternalFieldcount = 1;

	static const unsigned short v8DOMNodeClassId = 1;
	static const unsigned short v8DOMObjectClassId = 2;

    typedef v8::Handle<v8::FunctionTemplate> (*DomTemplateFunction)(v8::Isolate*);
    typedef void (*DerefObjectFunction)(void*);
    typedef ActiveDOMObject* (*ToActiveDOMObjectFunction)(v8::Handle<v8::Object>);
    typedef EventTarget* (*ToEventTargetFunction)(v8::Handle<v8::Object>);
    typedef void (*ResolveWrapperReachabilityFunction)(void*, const v8::Persistent<v8::Object>&, v8::Isolate*);
    typedef void (*InstallPerContextEnabledPrototypePropertiesFunction)(v8::Handle<v8::Object>, v8::Isolate*);

    enum WrapperTypePrototype {
        WrapperTypeObjectPrototype,
        WrapperTypeExceptionPrototype
    };

    inline void setObjectGroup(void* object, const v8::Persistent<v8::Object>& wrapper, v8::Isolate* isolate)
    {
        isolate->SetObjectGroupId(wrapper, v8::UniqueId(reinterpret_cast<intptr_t>(object)));
    }

    // This struct provides a way to store a bunch of information that is helpful when unwrapping
    // v8 objects. Each v8 bindings class has exactly one static WrapperTypeInfo member, so
    // comparing pointers is a safe way to determine if types match.
    struct WrapperTypeInfo {

        static const WrapperTypeInfo* unwrap(v8::Handle<v8::Value> typeInfoWrapper)
        {
            return reinterpret_cast<const WrapperTypeInfo*>(v8::External::Cast(*typeInfoWrapper)->Value());
        }


        bool equals(const WrapperTypeInfo* that) const
        {
            return this == that;
        }

        bool isSubclass(const WrapperTypeInfo* that) const
        {
            for (const WrapperTypeInfo* current = this; current; current = current->parentClass) {
                if (current == that)
                    return true;
            }

            return false;
        }

        v8::Handle<v8::FunctionTemplate> domTemplate(v8::Isolate* isolate) const
        {
            return domTemplateFunction(isolate);
        }

        void installPerContextEnabledMethods(v8::Handle<v8::Object> prototypeTemplate, v8::Isolate* isolate) const
        {
            if (installPerContextEnabledMethodsFunction)
                installPerContextEnabledMethodsFunction(prototypeTemplate, isolate);
        }

        ActiveDOMObject* toActiveDOMObject(v8::Handle<v8::Object> object) const
        {
            if (!toActiveDOMObjectFunction)
                return 0;
            return toActiveDOMObjectFunction(object);
        }

        EventTarget* toEventTarget(v8::Handle<v8::Object> object) const
        {
            if (!toEventTargetFunction)
                return 0;
            return toEventTargetFunction(object);
        }

        void visitDOMWrapper(void* object, const v8::Persistent<v8::Object>& wrapper, v8::Isolate* isolate) const
        {
            if (!visitDOMWrapperFunction)
                setObjectGroup(object, wrapper, isolate);
            else
                visitDOMWrapperFunction(object, wrapper, isolate);
        }

        // This field must be the first member of the struct WrapperTypeInfo. This is also checked by a COMPILE_ASSERT() below.
        const GinEmbedder ginEmbedder;

        const DomTemplateFunction domTemplateFunction;
        const DerefObjectFunction derefObjectFunction;
        const ToActiveDOMObjectFunction toActiveDOMObjectFunction;
        const ToEventTargetFunction toEventTargetFunction;
        const ResolveWrapperReachabilityFunction visitDOMWrapperFunction;
        const InstallPerContextEnabledPrototypePropertiesFunction installPerContextEnabledMethodsFunction;
        const WrapperTypeInfo* parentClass;
        const WrapperTypePrototype wrapperTypePrototype;
        const bool isGarbageCollected;
    };


    template<typename T, int offset>
    inline T* getInternalField(const v8::Persistent<v8::Object>& persistent)
    {
        // This would be unsafe, but InternalFieldCount and GetAlignedPointerFromInternalField are guaranteed not to allocate
        const v8::Handle<v8::Object>& object = reinterpret_cast<const v8::Handle<v8::Object>&>(persistent);
        ASSERT(offset < object->InternalFieldCount());
        return static_cast<T*>(object->GetAlignedPointerFromInternalField(offset));
    }

    template<typename T, int offset>
    inline T* getInternalField(v8::Handle<v8::Object> wrapper)
    {
        ASSERT(offset < wrapper->InternalFieldCount());
        return static_cast<T*>(wrapper->GetAlignedPointerFromInternalField(offset));
    }

    inline void* toNative(const v8::Persistent<v8::Object>& wrapper)
    {
        return getInternalField<void, v8DOMWrapperObjectIndex>(wrapper);
    }

    inline void* toNative(v8::Handle<v8::Object> wrapper)
    {
        return getInternalField<void, v8DOMWrapperObjectIndex>(wrapper);
    }

    inline const WrapperTypeInfo* toWrapperTypeInfo(const v8::Persistent<v8::Object>& wrapper)
    {
        return getInternalField<WrapperTypeInfo, v8DOMWrapperTypeIndex>(wrapper);
    }

    inline const WrapperTypeInfo* toWrapperTypeInfo(v8::Handle<v8::Object> wrapper)
    {
        return getInternalField<WrapperTypeInfo, v8DOMWrapperTypeIndex>(wrapper);
    }

    //inline const PersistentNode* toPersistentHandle(const v8::Handle<v8::Object>& wrapper)
    //{
    //    // Persistent handle is stored in the last internal field.
    //    return static_cast<PersistentNode*>(wrapper->GetAlignedPointerFromInternalField(wrapper->InternalFieldCount() - 1));
    //}

    inline void releaseObject(v8::Handle<v8::Object> wrapper)
    {
        const WrapperTypeInfo* typeInfo = toWrapperTypeInfo(wrapper);
        typeInfo->derefObjectFunction(toNative(wrapper));
    }

    struct WrapperConfiguration 
	{

        enum Lifetime {
            Dependent, Independent
        };

        void configureWrapper(v8::Persistent<v8::Object>* wrapper) const
        {
            wrapper->SetWrapperClassId(classId);
            if (lifetime == Independent)
                wrapper->MarkIndependent();
        }

        const uint16_t classId;
        const Lifetime lifetime;
    };

    inline WrapperConfiguration buildWrapperConfiguration(void*, WrapperConfiguration::Lifetime lifetime)
    {
        WrapperConfiguration configuration = {v8DOMObjectClassId, lifetime};
        return configuration;
    }

    inline WrapperConfiguration buildWrapperConfiguration(Node*, WrapperConfiguration::Lifetime lifetime)
    {
        WrapperConfiguration configuration = {v8DOMNodeClassId, lifetime};
        return configuration;
    }
}

#endif // WrapperTypeInfo_h
