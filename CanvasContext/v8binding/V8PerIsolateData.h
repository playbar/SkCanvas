#ifndef V8PerIsolateData_h
#define V8PerIsolateData_h

//#include "bindings/v8/ScopedPersistent.h"
//#include "bindings/v8/V8HiddenValue.h"
#include "WrapperTypeInfo.h"
#include "DOMDataStore.h"
//#include "gin/public/gin_embedders.h"
//#include "gin/public/isolate_holder.h"
#include <include/v8.h>
#include "OwnPtr.h"
#include "vector"


namespace Canvas2D
{

typedef std::vector<DOMDataStore*> DOMDataStoreList;

class V8PerIsolateData {
public:
    static void ensureInitialized(v8::Isolate*);
    static V8PerIsolateData* current()
    {
        return from(v8::Isolate::GetCurrent());
    }
    static V8PerIsolateData* from(v8::Isolate* isolate)
    {
        SkASSERT(isolate);
        SkASSERT(isolate->GetData(kEmbedderBlink));
        return static_cast<V8PerIsolateData*>(isolate->GetData(kEmbedderBlink));
    }
    static void dispose(v8::Isolate*);
    static v8::Isolate* mainThreadIsolate();

    v8::Isolate* isolate() { return m_isolate; }

    v8::Handle<v8::FunctionTemplate> toStringTemplate();

    //StringCache* stringCache() { return m_stringCache.get(); }

    v8::Persistent<v8::Value>& ensureLiveRoot();

    int recursionLevel() const { return m_recursionLevel; }
    int incrementRecursionLevel() { return ++m_recursionLevel; }
    int decrementRecursionLevel() { return --m_recursionLevel; }

    bool performingMicrotaskCheckpoint() const { return m_performingMicrotaskCheckpoint; }
    void setPerformingMicrotaskCheckpoint(bool performingMicrotaskCheckpoint) { m_performingMicrotaskCheckpoint = performingMicrotaskCheckpoint; }

    //GCEventData* gcEventData() { return m_gcEventData.get(); }
    //V8HiddenValue* hiddenValue() { return m_hiddenValue.get(); }

    v8::Handle<v8::FunctionTemplate> domTemplate(void* domTemplateKey, v8::FunctionCallback = 0, v8::Handle<v8::Value> data = v8::Handle<v8::Value>(), v8::Handle<v8::Signature> = v8::Handle<v8::Signature>(), int length = 0);
    v8::Handle<v8::FunctionTemplate> existingDOMTemplate(void* domTemplateKey);
    void setDOMTemplate(void* domTemplateKey, v8::Handle<v8::FunctionTemplate>);

    //bool hasInstance(const WrapperTypeInfo*, v8::Handle<v8::Value>);
    //v8::Handle<v8::Object> findInstanceInPrototypeChain(const WrapperTypeInfo*, v8::Handle<v8::Value>);

    v8::Local<v8::Context> ensureRegexContext();

    const char* previousSamplingState() const { return m_previousSamplingState; }
    void setPreviousSamplingState(const char* name) { m_previousSamplingState = name; }

private:
    explicit V8PerIsolateData(v8::Isolate*);
    ~V8PerIsolateData();

    typedef std::map<const void*, v8::Global<v8::FunctionTemplate> > DOMTemplateMap;
    DOMTemplateMap& currentDOMTemplateMap();
    //bool hasInstance(const WrapperTypeInfo*, v8::Handle<v8::Value>, DOMTemplateMap&);
    //v8::Handle<v8::Object> findInstanceInPrototypeChain(const WrapperTypeInfo*, v8::Handle<v8::Value>, DOMTemplateMap&);

    v8::Isolate* m_isolate;
    //OwnPtr<gin::IsolateHolder> m_isolateHolder;
    DOMTemplateMap m_domTemplateMapForMainWorld;
    DOMTemplateMap m_domTemplateMapForNonMainWorld;
    //ScopedPersistent<v8::FunctionTemplate> m_toStringTemplate;
    //OwnPtr<StringCache> m_stringCache;
    //OwnPtr<V8HiddenValue> m_hiddenValue;
    //ScopedPersistent<v8::Value> m_liveRoot;
    //OwnPtr<V8PerContextData> m_perContextDataForRegex;

    const char* m_previousSamplingState;

    bool m_constructorMode;
    friend class ConstructorMode;

    int m_recursionLevel;

    //OwnPtr<GCEventData> m_gcEventData;
    bool m_performingMicrotaskCheckpoint;
};

} // namespace WebCore

#endif // V8PerIsolateData_h
