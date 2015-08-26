

#include "DOMDataStore.h"

#include "DOMWrapperMap.h"
#include "V8Binding.h"

namespace Canvas2D
{

DOMDataStore::DOMDataStore(bool isMainWorld)
    : m_isMainWorld(isMainWorld)
    , m_wrapperMap(v8::Isolate::GetCurrent()) // FIXME Don't call GetCurrent twice.
{
}

DOMDataStore::~DOMDataStore()
{
    SkASSERT(!m_isMainWorld); // We never actually destruct the main world's DOMDataStore.
    m_wrapperMap.clear();
}

//DOMDataStore& DOMDataStore::current(v8::Isolate* isolate)
//{
//    return DOMWrapperWorld::world(isolate->GetCurrentContext())->domDataStore();
//}

} // namespace WebCore
