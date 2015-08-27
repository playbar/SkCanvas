#include "V8PerContextData.h"
#include "V8Binding.h"
#include "RefPtr.h"
#include "JSCore.h"
#include "V8ObjectConstructor.h"

#include <stdlib.h>

namespace Canvas2D {

template<typename Map>
static void disposeMapWithUnsafePersistentValues(Map* map)
{
    typename Map::iterator it = map->begin();
    for (; it != map->end(); ++it)
        it->second.Reset();
    map->clear();
}

class V8PerContextDataHolder {
    WTF_MAKE_NONCOPYABLE(V8PerContextDataHolder);
public:
    static void install(v8::Handle<v8::Context> context)
    {
        new V8PerContextDataHolder(context);
    }

    static V8PerContextDataHolder* from(v8::Handle<v8::Context> context)
    {
        V8PerContextDataHolder* holder = static_cast<V8PerContextDataHolder*>(context->GetAlignedPointerFromEmbedderData(v8ContextPerContextDataIndex));
        // V8PerContextDataHolder::from() must not be called for a context that does not have
        // valid embedder data in the embedder field.
        //RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(holder);
        //RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(holder->context() == context);
        return holder;
    }

    V8PerContextData* perContextData() const { return m_perContextData; }
    void setPerContextData(V8PerContextData* data) { m_perContextData = data; }
    //DOMWrapperWorld* world() const { return m_world.get(); }
    v8::Handle<v8::Context> context() const { return m_context.newLocal(m_isolate); }

private:
    V8PerContextDataHolder(v8::Handle<v8::Context> context)
        : m_isolate(context->GetIsolate())
        , m_context(m_isolate, context)
        , m_perContextData(0)
        //, m_world(world)
    {
        m_context.setWeak(this, &V8PerContextDataHolder::weakCallback);
        context->SetAlignedPointerInEmbedderData(v8ContextPerContextDataIndex, this);
    }

    ~V8PerContextDataHolder() { }

    static void weakCallback(const v8::WeakCallbackData<v8::Context, V8PerContextDataHolder>& data)
    {
        data.GetValue()->SetAlignedPointerInEmbedderData(v8ContextPerContextDataIndex, 0);
        delete data.GetParameter();
    }

    v8::Isolate* m_isolate;
    ScopedPersistent<v8::Context> m_context;
    V8PerContextData* m_perContextData;
    //RefPtr<DOMWrapperWorld> m_world;
};

V8PerContextData::V8PerContextData(v8::Handle<v8::Context> context)
    : m_isolate(context->GetIsolate())
    , m_context(m_isolate, context)
    , m_customElementBindings(adoptPtr(new CustomElementBindingMap()))
{
    m_contextHolder.Reset(context->GetIsolate(), context);
    V8PerContextDataHolder::install(context);
    V8PerContextDataHolder::from(context)->setPerContextData(this);

    v8::Context::Scope contextScope(context);
    SkASSERT(m_errorPrototype.isEmpty());
    v8::Handle<v8::Object> object = v8::Handle<v8::Object>::Cast(context->Global()->Get(v8AtomicString(m_isolate, "Error")));
    SkASSERT(!object.IsEmpty());
    v8::Handle<v8::Value> prototypeValue = object->Get(v8AtomicString(m_isolate, "prototype"));
    SkASSERT(!prototypeValue.IsEmpty());
    m_errorPrototype.set(m_isolate, prototypeValue);
}

V8PerContextData::~V8PerContextData()
{
    v8::HandleScope handleScope(m_isolate);
    V8PerContextDataHolder::from(m_context.newLocal(m_isolate))->setPerContextData(0);

    disposeMapWithUnsafePersistentValues(&m_wrapperBoilerplates);
    disposeMapWithUnsafePersistentValues(&m_constructorMap);
}

V8PerContextData* V8PerContextData::from(v8::Handle<v8::Context> context)
{
    return V8PerContextDataHolder::from(context)->perContextData();
}

//DOMWrapperWorld* V8PerContextData::world(v8::Handle<v8::Context> context)
//{
//    DOMWrapperWorld* world = V8PerContextDataHolder::from(context)->world();
//    SkASSERT(world);
//    return world;
//}

v8::Local<v8::Object> V8PerContextData::createWrapperFromCacheSlowCase(const WrapperTypeInfo* type)
{
	SkASSERT(!m_errorPrototype.isEmpty());

	v8::Context::Scope scope(context());
	v8::Local<v8::Function> function = constructorForType(type);
	v8::Local<v8::Object> instanceTemplate = V8ObjectConstructor::newInstance(function);
	if (!instanceTemplate.IsEmpty()) {
		m_wrapperBoilerplates[type] = v8::Global<v8::Object>(m_isolate, instanceTemplate);
		return instanceTemplate->Clone();
	}
	return v8::Local<v8::Object>();
}

v8::Local<v8::Function> V8PerContextData::constructorForTypeSlowCase(const WrapperTypeInfo* type)
{
    SkASSERT(!m_errorPrototype.isEmpty());

    v8::Context::Scope scope(context());
    v8::Handle<v8::FunctionTemplate> functionTemplate = type->domTemplate(m_isolate);
    // Getting the function might fail if we're running out of stack or memory.
    v8::TryCatch tryCatch;
    v8::Local<v8::Function> function = functionTemplate->GetFunction();
    if (function.IsEmpty())
        return v8::Local<v8::Function>();

    if (type->parentClass) {
        v8::Local<v8::Object> prototypeTemplate = constructorForType(type->parentClass);
        if (prototypeTemplate.IsEmpty())
            return v8::Local<v8::Function>();
        function->SetPrototype(prototypeTemplate);
    }

    v8::Local<v8::Value> prototypeValue = function->Get(v8AtomicString(m_isolate, "prototype"));
    if (!prototypeValue.IsEmpty() && prototypeValue->IsObject()) {
        v8::Local<v8::Object> prototypeObject = v8::Local<v8::Object>::Cast(prototypeValue);
        if (prototypeObject->InternalFieldCount() == v8PrototypeInternalFieldcount
            && type->wrapperTypePrototype == WrapperTypeObjectPrototype)
            prototypeObject->SetAlignedPointerInInternalField(v8PrototypeTypeIndex, const_cast<WrapperTypeInfo*>(type));
        type->installPerContextEnabledMethods(prototypeObject, m_isolate);
        if (type->wrapperTypePrototype == WrapperTypeExceptionPrototype)
            prototypeObject->SetPrototype(m_errorPrototype.newLocal(m_isolate));
    }

    m_constructorMap[type] = v8::Global<v8::Function>(m_isolate, function);

    return function;
}

//v8::Local<v8::Object> V8PerContextData::prototypeForType(const WrapperTypeInfo* type)
//{
//    v8::Local<v8::Object> constructor = constructorForType(type);
//    if (constructor.IsEmpty())
//        return v8::Local<v8::Object>();
//    return constructor->Get(v8String(m_isolate, "prototype")).As<v8::Object>();
//}

//void V8PerContextData::addCustomElementBinding(CustomElementDefinition* definition, PassOwnPtr<CustomElementBinding> binding)
//{
//    ASSERT(!m_customElementBindings->contains(definition));
//    m_customElementBindings->add(definition, binding);
//}

//void V8PerContextData::clearCustomElementBinding(CustomElementDefinition* definition)
//{
//    CustomElementBindingMap::iterator it = m_customElementBindings->find(definition);
//    ASSERT_WITH_SECURITY_IMPLICATION(it != m_customElementBindings->end());
//    m_customElementBindings->remove(it);
//}

//CustomElementBinding* V8PerContextData::customElementBinding(CustomElementDefinition* definition)
//{
//    CustomElementBindingMap::const_iterator it = m_customElementBindings->find(definition);
//    ASSERT_WITH_SECURITY_IMPLICATION(it != m_customElementBindings->end());
//    return it->value.get();
//}
//

static v8::Handle<v8::Value> createDebugData(const char* worldName, int debugId, v8::Isolate* isolate)
{
    char buffer[32];
    unsigned wanted;
    if (debugId == -1)
        wanted = snprintf(buffer, sizeof(buffer), "%s", worldName);
    else
        wanted = snprintf(buffer, sizeof(buffer), "%s,%d", worldName, debugId);

    if (wanted < sizeof(buffer))
        return v8AtomicString(isolate, buffer);

    return v8::Undefined(isolate);
}

static v8::Handle<v8::Value> debugData(v8::Handle<v8::Context> context)
{
    v8::Context::Scope contextScope(context);
    return context->GetEmbedderData(v8ContextDebugIdIndex);
}

static void setDebugData(v8::Handle<v8::Context> context, v8::Handle<v8::Value> value)
{
    v8::Context::Scope contextScope(context);
    context->SetEmbedderData(v8ContextDebugIdIndex, value);
}

bool V8PerContextDebugData::setContextDebugData(v8::Handle<v8::Context> context, const char* worldName, int debugId)
{
    if (!debugData(context)->IsUndefined())
        return false;
    v8::HandleScope scope(context->GetIsolate());
    v8::Handle<v8::Value> debugData = createDebugData(worldName, debugId, context->GetIsolate());
    setDebugData(context, debugData);
    return true;
}

int V8PerContextDebugData::contextDebugId(v8::Handle<v8::Context> context)
{
    v8::HandleScope scope(context->GetIsolate());
    v8::Handle<v8::Value> data = debugData(context);

    if (!data->IsString())
        return -1;
    v8::String::Utf8Value utf8(data);
    char* comma = strnstr(*utf8, ",", utf8.length());
    if (!comma)
        return -1;
    return atoi(comma + 1);
}

} // namespace WebCore
