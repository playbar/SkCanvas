

#ifndef V8PerContextData_h
#define V8PerContextData_h

#include "CustomElementBinding.h"
#include "ScopedPersistent.h"
//#include "bindings/v8/V8DOMActivityLogger.h"
#include "WrapperTypeInfo.h"
//#include "gin/public/context_holder.h"
//#include "gin/public/gin_embedders.h"
#include <include/v8.h>
#include "PassOwnPtr.h"
#include "PassRefPtr.h"
#include "OwnPtr.h"
#include "map"
#include "vector"
//#include "wtf/text/AtomicString.h"
//#include "wtf/text/AtomicStringHash.h"

namespace Canvas2D
{

class CustomElementDefinition;
class V8PerContextData;
struct V8NPObject;
typedef std::vector<V8NPObject*> V8NPObjectVector;
typedef std::map<int, V8NPObjectVector> V8NPObjectMap;

enum V8ContextEmbedderDataField
{
    v8ContextDebugIdIndex = static_cast<int>(kDebugIdIndex),
    v8ContextPerContextDataIndex = static_cast<int>(kPerContextDataStartIndex + kEmbedderBlink),
};

class V8PerContextData 
{
public:
    static PassOwnPtr<V8PerContextData> create(v8::Handle<v8::Context> context)
    {
        return adoptPtr(new V8PerContextData(context));
    }

    static V8PerContextData* from(v8::Handle<v8::Context>);
    //static DOMWrapperWorld* world(v8::Handle<v8::Context>);

    ~V8PerContextData();

    v8::Handle<v8::Context> context() { return m_context.newLocal(m_isolate); }

    // To create JS Wrapper objects, we create a cache of a 'boiler plate'
    // object, and then simply Clone that object each time we need a new one.
    // This is faster than going through the full object creation process.
    v8::Local<v8::Object> createWrapperFromCache(const WrapperTypeInfo* type)
    {
		WrapperBoilerplateMap::iterator it = m_wrapperBoilerplates.find(type);
		if ( it != m_wrapperBoilerplates.end() && !it->second.IsEmpty())
		{
			return v8::Local<v8::Object>::New(v8::Isolate::GetCurrent(), it->second)->Clone();
		}
		else
		{
			return createWrapperFromCacheSlowCase(type);
		}
		
    }

    v8::Local<v8::Function> constructorForType(const WrapperTypeInfo* type)
    {
		ConstructorMap::iterator it = m_constructorMap.find(type);
		if ( it != m_constructorMap.end() && !it->second.IsEmpty() )
		{
			return v8::Local<v8::Function>::New(v8::Isolate::GetCurrent(), it->second );
		}
        return constructorForTypeSlowCase(type);
    }

    v8::Local<v8::Object> prototypeForType(const WrapperTypeInfo*);

    V8NPObjectMap* v8NPObjectMap() { return &m_v8NPObjectMap; }
    //V8DOMActivityLogger* activityLogger() { return m_activityLogger; }
    //void setActivityLogger(V8DOMActivityLogger* logger) { m_activityLogger = logger; }

    //void addCustomElementBinding(CustomElementDefinition*, PassOwnPtr<CustomElementBinding>);
    //void clearCustomElementBinding(CustomElementDefinition*);
    //CustomElementBinding* customElementBinding(CustomElementDefinition*);

private:
    V8PerContextData(v8::Handle<v8::Context>);

    v8::Local<v8::Object> createWrapperFromCacheSlowCase(const WrapperTypeInfo*);
    v8::Local<v8::Function> constructorForTypeSlowCase(const WrapperTypeInfo*);

    // For each possible type of wrapper, we keep a boilerplate object.
    // The boilerplate is used to create additional wrappers of the same type.
    typedef std::map<const WrapperTypeInfo*, v8::Global<v8::Object> > WrapperBoilerplateMap;
    WrapperBoilerplateMap m_wrapperBoilerplates;

    typedef std::map<const WrapperTypeInfo*, v8::Global<v8::Function> > ConstructorMap;
    ConstructorMap m_constructorMap;

    V8NPObjectMap m_v8NPObjectMap;
    // We cache a pointer to the V8DOMActivityLogger associated with the world
    // corresponding to this context. The ownership of the pointer is retained
    // by the DOMActivityLoggerMap in DOMWrapperWorld.
    //V8DOMActivityLogger* m_activityLogger;

    v8::Isolate* m_isolate;
    //OwnPtr<gin::ContextHolder> m_contextHolder;
	v8::UniquePersistent<v8::Context> m_contextHolder;


    ScopedPersistent<v8::Context> m_context;
    ScopedPersistent<v8::Value> m_errorPrototype;

    typedef std::map<CustomElementDefinition*, OwnPtr<CustomElementBinding> > CustomElementBindingMap;
    OwnPtr<CustomElementBindingMap> m_customElementBindings;
};

class V8PerContextDebugData {
public:
    static bool setContextDebugData(v8::Handle<v8::Context>, const char* worldName, int debugId);
    static int contextDebugId(v8::Handle<v8::Context>);
};

} // namespace WebCore

#endif // V8PerContextData_h
