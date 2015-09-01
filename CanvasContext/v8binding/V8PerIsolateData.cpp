#include "V8PerIsolateData.h"
#include "DOMDataStore.h"
#include "V8Binding.h"

namespace Canvas2D 
{

static V8PerIsolateData* mainThreadPerIsolateData = 0;

V8PerIsolateData::V8PerIsolateData(v8::Isolate* isolate)
    : m_isolate(isolate)
    , m_constructorMode(false)
    , m_recursionLevel(0)
    , m_performingMicrotaskCheckpoint(false)
{
	mainThreadPerIsolateData = this;
}

V8PerIsolateData::~V8PerIsolateData()
{
	mainThreadPerIsolateData = 0;
}

v8::Isolate* V8PerIsolateData::mainThreadIsolate()
{
    SkASSERT(mainThreadPerIsolateData);
    return mainThreadPerIsolateData->isolate();
}

void V8PerIsolateData::ensureInitialized(v8::Isolate* isolate)
{
    SkASSERT(isolate);
    if (!isolate->GetData(kEmbedderBlink))
	{
        V8PerIsolateData* data = new V8PerIsolateData(isolate);
        isolate->SetData(kEmbedderBlink, data);
    }
}

void V8PerIsolateData::dispose(v8::Isolate* isolate)
{
    void* data = isolate->GetData(kEmbedderBlink);
    delete static_cast<V8PerIsolateData*>(data);
    isolate->SetData(kEmbedderBlink, 0);
}

V8PerIsolateData::DOMTemplateMap& V8PerIsolateData::currentDOMTemplateMap()
{
	return m_domTemplateMapForMainWorld;
}

//v8::Handle<v8::FunctionTemplate> V8PerIsolateData::domTemplate(void* domTemplateKey, v8::FunctionCallback callback, v8::Handle<v8::Value> data, v8::Handle<v8::Signature> signature, int length)
//{
//    DOMTemplateMap& domTemplateMap = currentDOMTemplateMap();
//    DOMTemplateMap::iterator result = domTemplateMap.find(domTemplateKey);
//	if (result != domTemplateMap.end())
//		return v8::Local<v8::FunctionTemplate>::New(m_isolate, result->second);
//    v8::Local<v8::FunctionTemplate> templ = v8::FunctionTemplate::New(m_isolate, callback, data, signature, length);
//	domTemplateMap[domTemplateKey] = v8::Global<v8::FunctionTemplate>(m_isolate, templ);
//    return templ;
//}

v8::Handle<v8::FunctionTemplate> V8PerIsolateData::existingDOMTemplate(void* domTemplateKey)
{
    DOMTemplateMap& domTemplateMap = currentDOMTemplateMap();
    DOMTemplateMap::iterator result = domTemplateMap.find(domTemplateKey);
	if (result != domTemplateMap.end())
		return v8::Local<v8::FunctionTemplate>::New(m_isolate, result->second);
    return v8::Local<v8::FunctionTemplate>();
}

void V8PerIsolateData::setDOMTemplate(void* domTemplateKey, v8::Handle<v8::FunctionTemplate> templ)
{
    currentDOMTemplateMap()[domTemplateKey] = v8::Global<v8::FunctionTemplate>(m_isolate, templ);
}

} // namespace WebCore
