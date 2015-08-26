#ifndef V8ScriptRunner_h
#define V8ScriptRunner_h

//#include "core/fetch/CrossOriginAccessControl.h"
#include "PassOwnPtr.h"
//#include "wtf/text/TextPosition.h"
#include <include/v8.h>

namespace Canvas2D
{

class ScriptResource;
class ExecutionContext;

class V8ScriptRunner {
public:
    // For the following methods, the caller sites have to hold
    // a HandleScope and a ContextScope.
    //static PassOwnPtr<v8::ScriptData> precompileScript(v8::Handle<v8::String>, ScriptResource*);
    //static v8::Local<v8::Script> compileScript(v8::Handle<v8::String>, const String&, const TextPosition&, v8::ScriptData*, v8::Isolate*, AccessControlStatus = SharableCrossOrigin);
    //static v8::Local<v8::Value> runCompiledScript(v8::Handle<v8::Script>, ExecutionContext*, v8::Isolate*);
    //static v8::Local<v8::Value> compileAndRunInternalScript(v8::Handle<v8::String>, v8::Isolate*, const String& = String(), const TextPosition& = TextPosition(), v8::ScriptData* = 0);
    //static v8::Local<v8::Value> callInternalFunction(v8::Handle<v8::Function>, v8::Handle<v8::Value> receiver, int argc, v8::Handle<v8::Value> info[], v8::Isolate*);
    //static v8::Local<v8::Value> callFunction(v8::Handle<v8::Function>, ExecutionContext*, v8::Handle<v8::Value> receiver, int argc, v8::Handle<v8::Value> info[], v8::Isolate*);
    //static v8::Local<v8::Value> callAsFunction(v8::Handle<v8::Object>, v8::Handle<v8::Value> receiver, int argc, v8::Handle<v8::Value> info[]);
    //static v8::Local<v8::Value> callAsConstructor(v8::Handle<v8::Object>, int argc, v8::Handle<v8::Value> info[]);
    static v8::Local<v8::Object> instantiateObject(v8::Handle<v8::ObjectTemplate>);
    static v8::Local<v8::Object> instantiateObject(v8::Handle<v8::Function>, int argc = 0, v8::Handle<v8::Value> argv[] = 0);
    //static v8::Local<v8::Object> instantiateObjectInDocument(v8::Handle<v8::Function>, ExecutionContext*, int argc = 0, v8::Handle<v8::Value> argv[] = 0);

};

} // namespace WebCore

#endif // V8ScriptRunner_h
