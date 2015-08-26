#include "V8CanvasContext2D.h"
#include "CanvasContext2D.h"
#include "gl/GrGLInterface.h"
#include "SkGpuDevice.h"
#include "JSCore.h"
#include "V8CanvasGradient.h"

extern SkCanvas *gCanvas;

CanvasContext2D* UnwrapCanvasContext2D(Local<Object> obj)
{
	Local<External> field = Local<External>::Cast(obj->GetInternalField(0));
	void* ptr = field->Value();
	return static_cast<CanvasContext2D*>(ptr);
}

void v8_CanvasContext2D_sava(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	imp->save();
}

void v8_CanvasContext2D_restore(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	imp->restore();
}

void v8_CanvasContext2D_scale(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(2);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float sx = static_cast<float>(args[0]->NumberValue());
	float sy = static_cast<float>(args[1]->NumberValue());
	imp->scale(sx, sy);
}

void v8_CanvasContext2D_rotate(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(1);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float angle = static_cast<float>(args[0]->NumberValue());
	imp->rotate(angle);
}

void v8_CanvasContext2D_translate(const v8::FunctionCallbackInfo<v8::Value> & args)
{
	BEGIN_SCOPE_WHITH_ARGS(2);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float dx = static_cast<float>(args[0]->NumberValue());
	float dy = static_cast<float>(args[1]->NumberValue());
	imp->translate(dx, dy);
}

void v8_CanvasContext2D_transform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(6);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float m11 = static_cast<float>(args[0]->NumberValue());
	float m12 = static_cast<float>(args[1]->NumberValue());
	float m21 = static_cast<float>(args[2]->NumberValue());
	float m22 = static_cast<float>(args[3]->NumberValue());
	float dx = static_cast<float>(args[4]->NumberValue());
	float dy = static_cast<float>(args[5]->NumberValue());
	imp->transform(m11, m12, m21, m22, dx, dy);
}

void v8_CanvasContext2D_setTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(6);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float m11 = static_cast<float>(args[0]->NumberValue());
	float m12 = static_cast<float>(args[1]->NumberValue());
	float m21 = static_cast<float>(args[2]->NumberValue());
	float m22 = static_cast<float>(args[3]->NumberValue());
	float dx = static_cast<float>(args[4]->NumberValue());
	float dy = static_cast<float>(args[5]->NumberValue());
	imp->setTransform(m11, m12, m21, m22, dx, dy);
}

void v8_CanvasContext2D_resetTransform(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	imp->resetTransform();
}

void v8_CanvasContext2D_createLinearGradient(const v8::FunctionCallbackInfo<v8::Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(4);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x0 = static_cast<float>(args[0]->NumberValue());
	float y0 = static_cast<float>(args[1]->NumberValue());
	float x1 = static_cast<float>(args[2]->NumberValue());
	float y1 = static_cast<float>(args[3]->NumberValue());
	RefPtr<CanvasGradient> result = imp->createLinearGradient(x0, y0, x1, y1);
	v8SetReturnValue(args, result.release());
}

void v8_CanvasContext2D_createRadialGradient(const v8::FunctionCallbackInfo<v8::Value> &args)
{

}

void v8_CanvasContext2D_setLineDash(const FunctionCallbackInfo<Value> &args)
{
	//todo
}

void v8_CanvasContext2D_getLineDash(const FunctionCallbackInfo<Value> &args)
{
	//todo
}

void v8_CanvasContext2D_clearRect(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(4);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	float w = static_cast<float>(args[2]->NumberValue());
	float h = static_cast<float>(args[3]->NumberValue());
	imp->clearRect(x, y, w, h);
}

void v8_CanvasContext2D_fillRect(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(4);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	float w = static_cast<float>(args[2]->NumberValue());
	float h = static_cast<float>(args[3]->NumberValue());
	imp->fillRect(x, y, w, h);
}

void v8_CanvasContext2D_beginPath(const FunctionCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	imp->beginPath();
}

void v8_CanvasContext2D_closePath(const FunctionCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	imp->closePath();
}

void v8_CanvasContext2D_moveTo(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(2);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	imp->moveTo(x, y);
}

void v8_CanvasContext2D_lineTo(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(2);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	imp->lineTo(x, y);
}

void v8_CanvasContext2D_quadraticCurveTo(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(4);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cpx = static_cast<float>(args[0]->NumberValue());
	float cpy = static_cast<float>(args[1]->NumberValue());
	float x = static_cast<float>(args[2]->NumberValue());
	float y = static_cast<float>(args[3]->NumberValue());
	imp->quadraticCurveTo(cpx, cpy, x, y);
}

void v8_CanvasContext2D_bezierCurveTo(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(6);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cp1x = static_cast<float>(args[0]->NumberValue());
	float cp1y = static_cast<float>(args[1]->NumberValue());
	float cp2x = static_cast<float>(args[2]->NumberValue());
	float cp2y = static_cast<float>(args[3]->NumberValue());
	float x = static_cast<float>(args[4]->NumberValue());
	float y = static_cast<float>(args[5]->NumberValue());
	imp->bezierCurveTo(cp1x, cp1y, cp2x, cp2y, x, y);
}

void v8_CanvasContext2D_arcTo(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(5);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x1 = static_cast<float>(args[0]->NumberValue());
	float y1 = static_cast<float>(args[1]->NumberValue());
	float x2 = static_cast<float>(args[2]->NumberValue());
	float y2 = static_cast<float>(args[3]->NumberValue());
	float radius = static_cast<float>(args[4]->NumberValue());
	imp->arcTo(x1, y1, x2, y2, radius);
}

void v8_CanvasContext2D_rect(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(4);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	float width = static_cast<float>(args[2]->NumberValue());
	float height = static_cast<float>(args[3]->NumberValue());
	imp->rect(x, y, width, height);
}

void v8_CanvasContext2D_arc(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(5);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	float radius = static_cast<float>(args[2]->NumberValue());
	float startAngle = static_cast<float>(args[3]->NumberValue());
	float endAngle = static_cast<float>(args[4]->NumberValue());
	bool anticlockwise = args[5]->BooleanValue();
	imp->arc(x, y, radius, startAngle, endAngle, anticlockwise);
}

void v8_CanvasContext2D_ellipse(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(7);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	float radiusX = static_cast<float>(args[2]->NumberValue());
	float radiusY = static_cast<float>(args[3]->NumberValue());
	float rotation = static_cast<float>(args[4]->NumberValue());
	float startAngle = static_cast<float>(args[5]->NumberValue());
	float endAngle = static_cast<float>(args[6]->NumberValue());
	bool anticlockwise = args[7]->BooleanValue();
	imp->ellipse(x, y, radiusX, radiusY, rotation, startAngle, endAngle, anticlockwise);
}

void v8_CanvasContext2D_fill(const FunctionCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	imp->fill();
}

void v8_CanvasContext2D_stroke(const FunctionCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	imp->stroke();
}

void v8_CanvasContext2D_clip(const FunctionCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	imp->clip();
}

void v8_CanvasContext2D_isPointInPath(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(2);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	args.GetReturnValue().Set(imp->isPointInPath(x, y));
}

void v8_CanvasContext2D_isPointInStroke(const FunctionCallbackInfo<Value> &args)
{
	//todo
}

void v8_CanvasContext2D_measureText(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(1);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(args[0]);
	const char* cstr = ToCString(str);
	imp->measureText(cstr);
}

void v8_CanvasContext2D_setAlpha(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(1);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float alpha = static_cast<float>(args[0]->NumberValue());
	imp->setGlobalAlpha(alpha);
}

void v8_CanvasContext2D_setCompositeOperation(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(1);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(args[0]);
	const char* cstr = ToCString(str);
	imp->setGlobalCompositeOperation(cstr);
}

void v8_CanvasContext2D_setLineWidth(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(1);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float w = static_cast<float>(args[0]->NumberValue());
	imp->setLineWidth(w);
}

void v8_CanvasContext2D_setLineCap(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(1);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(args[0]);
	const char* cstr = ToCString(str);
	imp->setLineCap(cstr);
}

void v8_CanvasContext2D_setLineJoin(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(1);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(args[0]);
	const char* cstr = ToCString(str);
	imp->setLineJoin(cstr);
}

void v8_CanvasContext2D_setMiterLimit(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(1);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float limit = static_cast<float>(args[0]->NumberValue());
	imp->setMiterLimit(limit);
}

void v8_CanvasContext2D_clearShadow(const FunctionCallbackInfo<Value> &args)
{
	//todo
}

void v8_CanvasContext2D_fillText(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(3);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(args[0]);
	const char* cstr = ToCString(str);
	float x = static_cast<float>(args[1]->NumberValue());
	float y = static_cast<float>(args[2]->NumberValue());
	imp->fillText(cstr, x, y);
}

void v8_CanvasContext2D_strokeText(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(3);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(args[0]);
	const char* cstr = ToCString(str);
	float x = static_cast<float>(args[1]->NumberValue());
	float y = static_cast<float>(args[2]->NumberValue());
	imp->strokeText(cstr, x, y);
}

void v8_CanvasContext2D_setStrokeColor(const FunctionCallbackInfo<Value> &args)
{
	//todo
}

void v8_CanvasContext2D_strokeRect(const FunctionCallbackInfo<Value> &args)
{
	BEGIN_SCOPE_WHITH_ARGS(3);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x = static_cast<float>(args[0]->NumberValue());
	float y = static_cast<float>(args[1]->NumberValue());
	float w = static_cast<float>(args[2]->NumberValue());
	float h = static_cast<float>(args[3]->NumberValue());
	imp->strokeRect(x, y, w, h);
}

void v8_CanvasContext2D_drawImage(const FunctionCallbackInfo<Value> &args)
{

}

void v8_CanvasContext2D_drawImageFromRect(const FunctionCallbackInfo<Value> &args)
{

}

void v8_CanvasContext2D_setShadow(const FunctionCallbackInfo<Value> &args)
{

}

void v8_CanvasContext2D_putImageData(const FunctionCallbackInfo<Value> &args)
{

}

void v8_CanvasContext2D_createPattern(const FunctionCallbackInfo<Value> &args)
{

}

void v8_CanvasContext2D_createImageData(const FunctionCallbackInfo<Value> &args)
{

}

void v8_CanvasContext2D_getImageData(const FunctionCallbackInfo<Value> &args)
{

}

void CanvasContext2DCallBack(const FunctionCallbackInfo<Value>& info)
{
	CanvasContext2D* pCanvas = new CanvasContext2D(gCanvas);
	
	Local<Object> object = info.This();
	Local<External> map_ptr = External::New(Isolate::GetCurrent(), pCanvas);
	object->SetInternalField(0, map_ptr);
}

Handle<FunctionTemplate> CanvasContext2D_Class(Isolate *isolate )
{
	Handle<FunctionTemplate> temp_class = FunctionTemplate::New(isolate, CanvasContext2DCallBack);
	temp_class->SetClassName(String::NewFromUtf8(isolate, "canvas"));
	Handle<ObjectTemplate> temp_proto = temp_class->PrototypeTemplate();
	temp_proto->Set(String::NewFromUtf8(isolate, "save", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_sava));
	temp_proto->Set(String::NewFromUtf8(isolate, "restore", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_restore));
	temp_proto->Set(String::NewFromUtf8(isolate, "scale", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_scale));
	temp_proto->Set(String::NewFromUtf8(isolate, "rotate", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_rotate));
	temp_proto->Set(String::NewFromUtf8(isolate, "translate", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_translate));
	temp_proto->Set(String::NewFromUtf8(isolate, "transform", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_transform));
	temp_proto->Set(String::NewFromUtf8(isolate, "setTransform", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setTransform));
	temp_proto->Set(String::NewFromUtf8(isolate, "resetTransform", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_resetTransform));
	temp_proto->Set(String::NewFromUtf8(isolate, "createLinearGradient", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_createLinearGradient));
	temp_proto->Set(String::NewFromUtf8(isolate, "createRadialGradient", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_createRadialGradient));
	temp_proto->Set(String::NewFromUtf8(isolate, "setLineDash", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setLineDash));
	temp_proto->Set(String::NewFromUtf8(isolate, "getLineDash", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_getLineDash));
	temp_proto->Set(String::NewFromUtf8(isolate, "clearRect", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_clearRect));
	temp_proto->Set(String::NewFromUtf8(isolate, "fillRect", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_fillRect));
	temp_proto->Set(String::NewFromUtf8(isolate, "beginPath", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_beginPath));
	temp_proto->Set(String::NewFromUtf8(isolate, "closePath", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_closePath));
	temp_proto->Set(String::NewFromUtf8(isolate, "moveTo", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_moveTo));
	temp_proto->Set(String::NewFromUtf8(isolate, "lineTo", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_lineTo));
	temp_proto->Set(String::NewFromUtf8(isolate, "quadraticCurveTo", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_quadraticCurveTo));
	temp_proto->Set(String::NewFromUtf8(isolate, "bezierCurveTo", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_bezierCurveTo));
	temp_proto->Set(String::NewFromUtf8(isolate, "arcTo", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_arcTo));
	temp_proto->Set(String::NewFromUtf8(isolate, "rect", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_rect));
	temp_proto->Set(String::NewFromUtf8(isolate, "arc", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_arc));
	temp_proto->Set(String::NewFromUtf8(isolate, "ellipse", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_ellipse));
	temp_proto->Set(String::NewFromUtf8(isolate, "fill", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_fill));
	temp_proto->Set(String::NewFromUtf8(isolate, "stroke", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_stroke));
	temp_proto->Set(String::NewFromUtf8(isolate, "clip", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_clip));
	temp_proto->Set(String::NewFromUtf8(isolate, "isPointInPath", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_isPointInPath));
	temp_proto->Set(String::NewFromUtf8(isolate, "isPointInStroke", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_isPointInStroke));
	temp_proto->Set(String::NewFromUtf8(isolate, "measureText", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_measureText));
	temp_proto->Set(String::NewFromUtf8(isolate, "setAlpha", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setAlpha));
	temp_proto->Set(String::NewFromUtf8(isolate, "setCompositeOperation", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setCompositeOperation));
	temp_proto->Set(String::NewFromUtf8(isolate, "setLineWidth", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setLineWidth));
	temp_proto->Set(String::NewFromUtf8(isolate, "setLineCap", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setLineCap));
	temp_proto->Set(String::NewFromUtf8(isolate, "setLineJoin", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setLineJoin));
	temp_proto->Set(String::NewFromUtf8(isolate, "setMiterLimit", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setMiterLimit));
	temp_proto->Set(String::NewFromUtf8(isolate, "clearShadow", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_clearShadow));
	temp_proto->Set(String::NewFromUtf8(isolate, "fillText", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_fillText));
	temp_proto->Set(String::NewFromUtf8(isolate, "strokeText", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_strokeText));
	temp_proto->Set(String::NewFromUtf8(isolate, "setStrokeColor", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setStrokeColor));
	temp_proto->Set(String::NewFromUtf8(isolate, "strokeRect", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_strokeRect));
	temp_proto->Set(String::NewFromUtf8(isolate, "drawImage", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_drawImage));
	temp_proto->Set(String::NewFromUtf8(isolate, "drawImageFromRect", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_drawImageFromRect));
	temp_proto->Set(String::NewFromUtf8(isolate, "setShadow", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_setShadow));
	temp_proto->Set(String::NewFromUtf8(isolate, "putImageData", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_putImageData));
	temp_proto->Set(String::NewFromUtf8(isolate, "createPattern", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_createPattern));
	temp_proto->Set(String::NewFromUtf8(isolate, "createImageData", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_createImageData));
	temp_proto->Set(String::NewFromUtf8(isolate, "getImageData", v8::NewStringType::kNormal).ToLocalChecked(), v8::FunctionTemplate::New(isolate, v8_CanvasContext2D_getImageData));

	Handle<ObjectTemplate> temp_inst = temp_class->InstanceTemplate();
	temp_inst->SetInternalFieldCount(1);
	return temp_class;
}

void setCanvasContext2DClass(Local<Object> parent, Isolate *isolate )
{
	v8::Handle<FunctionTemplate> temp_class = CanvasContext2D_Class(isolate);

	
	parent->Set(String::NewFromUtf8(isolate, "canvas"), temp_class->GetFunction());
}
