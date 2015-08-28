#include "V8CanvasContext2D.h"
#include "CanvasContext2D.h"
#include "gl/GrGLInterface.h"
#include "SkGpuDevice.h"
#include "JSCore.h"
#include "V8CanvasGradient.h"
#include "V8CanvasPattern.h"

extern SkCanvas *gCanvas;

CanvasContext2D* UnwrapCanvasContext2D(Local<Object> obj)
{
	Local<External> field = Local<External>::Cast(obj->GetInternalField(0));
	void* ptr = field->Value();
	return static_cast<CanvasContext2D*>(ptr);
}

static v8::Handle<v8::Value> toV8Object(CanvasStyle* style, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
	if (style->canvasGradient())
		return toV8(style->canvasGradient(), creationContext, isolate);

	if (style->canvasPattern())
		return toV8(style->canvasPattern(), creationContext, isolate);

	return v8String(isolate, style->color());
}

static PassRefPtr<CanvasStyle> toCanvasStyle(v8::Handle<v8::Value> value, v8::Isolate* isolate)
{
	RefPtr<CanvasStyle> canvasStyle = CanvasStyle::createFromGradient(V8CanvasGradient::toNative( value));
	if (canvasStyle)
		return canvasStyle;
	return CanvasStyle::createFromPattern(V8CanvasPattern::toNative(value));
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
	BEGIN_SCOPE_WHITH_ARGS(6);
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float x0 = static_cast<float>(args[0]->NumberValue());
	float y0 = static_cast<float>(args[1]->NumberValue());
	float r0 = static_cast<float>(args[2]->NumberValue());
	float x1 = static_cast<float>(args[3]->NumberValue());
	float y1 = static_cast<float>(args[4]->NumberValue());
	float r1 = static_cast<float>(args[5]->NumberValue());
	RefPtr<CanvasGradient> result = imp->createRadialGradient(x0, y0, r0, x1, y1, r1);
	v8SetReturnValue(args, result.release());
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


//////////////////////////////////////////////////////////////////////////
static void v8_CanvasContext2D_canvas_get(Local<String> str, const PropertyCallbackInfo<Value> &args )
{
	//todo
}

static void v8_CanvasContext2D_canvas_set( )
{
	//todo
}

static void v8_CanvasContext2D_globalAlpha_get(Local<String> str, const PropertyCallbackInfo<Value> &args )
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8SetReturnValue(args, imp->globalAlpha());
}

static void v8_CanvasContext2D_globalAlpha_set(Local<Value> jsValue, PropertyCallbackInfo<void> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cppValue = static_cast<float>(jsValue->NumberValue());
	imp->setGlobalAlpha(cppValue);
}

static void v8_CanvasContext2D_globalCompositeOperation_get(Local<String> val, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	Local<String> newString = String::NewFromUtf8(args.GetReturnValue().GetIsolate(), imp->globalCompositeOperation().c_str());
	args.GetReturnValue().Set(newString);
}

static void v8_CanvasContext2D_globalCompositeOperation_set(Local<Value> jsValue, const v8::PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(jsValue);
	const char* cstr = ToCString(str);
	imp->setGlobalCompositeOperation(cstr);
}

static void v8_CanvasContext2D_lineWidth_get(Local<String> val, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	args.GetReturnValue().Set(imp->lineWidth());
}

static void v8_CanvasContext2D_lineWidth_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cppValue = static_cast<float>(jsValue->NumberValue());
	imp->setLineWidth(cppValue);
}

static void v8_CanvasContext2D_lineCap_get(Local<String> val, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	Local<String> strVal = String::NewFromUtf8(args.GetReturnValue().GetIsolate(), imp->lineCap().c_str());
	args.GetReturnValue().Set(strVal);
}

static void v8_CanvasContext2D_lineCap_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(jsValue);
	const char* cstr = ToCString(str);
	imp->setLineCap(cstr);
}

static void v8_CanvasContext2D_lineJoin_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	Local<String> strVal = String::NewFromUtf8(args.GetReturnValue().GetIsolate(), imp->lineJoin().c_str());
	args.GetReturnValue().Set(strVal);
}

static void v8_CanvasContext2D_lineJoin_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(jsValue);
	const char *cstr = ToCString(str);
	imp->setLineJoin(cstr);
}

static void v8_CanvasContext2D_miterLimit_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	args.GetReturnValue().Set(imp->miterLimit());
}

static void v8_CanvasContext2D_miterLimit_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cppValue = static_cast<float>(jsValue->NumberValue());
	imp->setMiterLimit(cppValue);
}

static void v8_CanvasContext2D_shadowOffsetX_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	args.GetReturnValue().Set(imp->shadowOffsetX());
}

static void v8_CanvasContext2D_shadowOffsetX_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cppValue = static_cast<float>(jsValue->NumberValue());
	imp->setShadowOffsetX(cppValue);
}

static void v8_CanvasContext2D_shadowOffsetY_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	args.GetReturnValue().Set(imp->shadowOffsetY());
}

static void v8_CanvasContext2D_shadowOffsetY_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cppValue = static_cast<float>(jsValue->NumberValue());
	imp->setShadowOffsetY(cppValue);
}

static void v8_CanvasContext2D_shadowBlur_get(Local<String> strVa, PropertyCallbackInfo<Value>&args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	args.GetReturnValue.Set(imp->shadowBlur());
}

static void v8_CanvasContext2D_shadowBlur_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cppValue = static_cast<float>(jsValue->NumberValue());
	imp->setShadowBlur(cppValue);
}

static void v8_CanvasContext2D_shadowColor_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	Local<String> strVal = String::NewFromUtf8(args.GetReturnValue().GetIsolate(), imp->shadowColor().c_str());
	args.GetReturnValue().Set(strVal);
}

static void v8_CanvasContext2D_shadowColor_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(jsValue);
	const char *cstr = ToCString(str);
	imp->setShadowColor(cstr);
}

static void v8_CanvasContext2D_lineDashOffset_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	args.GetReturnValue().Set(strVal->NumberValue());
}

static void v8_CanvasContext2D_lineDashOffset_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	float cppValue = static_cast<float>(jsValue->NumberValue());
	imp->setLineDashOffset(cppValue);
}

static void v8_CanvasContext2D_currentPath_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	// todo
}

static void v8_CanvasContext2D_currentPath_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	// todo
}

static void v8_CanvasContext2D_font_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	Local<String> strVal = String::NewFromUtf8(args.GetReturnValue().GetIsolate(), imp->font().c_str());
	args.GetReturnValue().Set(strVal);
}

static void v8_CanvasContext2D_font_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(jsValue);
	const char *cstr = ToCString(str);
	imp->setFont(cstr);
}

static void v8_CanvasContext2D_textAlign_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	Local<String> strVal = String::NewFromUtf8(args.GetReturnValue().GetIsolate(), imp->textAlign.c_str());
	args.GetReturnValue().Set(strVal);
}

static void v8_CanvasContext2D_textAlign_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(jsValue);
	const char *cstr = ToCString(str);
	imp->setTextAlign(cstr);
}

static void v8_CanvasContext2D_textBaseline_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	Local<String> strVal = String::NewFromUtf8(args.GetReturnValue().GetIsolate(), imp->textBaseline().c_str());
	args.GetReturnValue().Set(strVal);
}

static void v8_CanvasContext2D_textBaseline_set(Local<Value> jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::String::Utf8Value str(jsValue);
	const char *cstr = ToCString(str);
	imp->setTextBaseline(cstr);
}

static void v8_CanvasContext2D_strokeStyle_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::Handle<v8::Value> strVal = toV8Object(imp->strokeStyle(), args.Holder(), args.GetIsolate());
	args.GetReturnValue().Set(strVal);
}

static void v8_CanvasContext2D_strokeStyle_set(Local<Value>jsValue, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	if ( jsValue->IsString() )
	{
		v8::String::Utf8Value str(jsValue);
		const char *cstr = ToCString(str);
		imp->setStrokeColor(cstr);
	}
	else
	{
		imp->setStrokeStyle(toCanvasStyle(jsValue, args.GetIsolate()));
	}
}

static void v8_CanvasContext2D_fillStyle_get(Local<String> strVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	v8::Handle<v8::Value> strVal = toV8Object(imp->fillStyle(), args.Holder(), args.GetIsolate());
	args.GetReturnValue().Set(strVal);
}

static void v8_CanvasContext2D_fillStyle_set(Local<Value> jsVal, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D *imp = UnwrapCanvasContext2D(args.Holder());
	if (jsVal->IsString())
	{
		v8::String::Utf8Value str(jsVal);
		const char *cstr = ToCString(str);
		imp->setFillColor(cstr);
	}
	else
	{
		imp->setFillStyle(toCanvasStyle(jsVal, args.GetIsolate()));
	}
}

static void v8_CanvasContext2D_imageSmoothingEnable_get(Local<String> jsStr, PropertyCallbackInfo<Value> &args)
{
	CanvasContext2D * imp = UnwrapCanvasContext2D(args.Holder());
}

static void v8_CanvasContext2D_imageSmoothingEnable_set(Local<Value> jsVal, PropertyCallbackInfo<Value> &args)
{

}

//////////////////////////////////////////////////////////////////////////
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
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "canvas"), v8_CanvasContext2D_canvas_get, v8_CanvasContext2D_canvas_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "globalAlpha"), v8_CanvasContext2D_globalAlpha_get, v8_CanvasContext2D_globalAlpha_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "globalCompositeOperation"), v8_CanvasContext2D_globalCompositeOperation_get, v8_CanvasContext2D_globalCompositeOperation_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "lineWidth"), v8_CanvasContext2D_lineWidth_get, v8_CanvasContext2D_lineWidth_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "lineCap"), v8_CanvasContext2D_lineCap_get, v8_CanvasContext2D_lineCap_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "lineJoin"), v8_CanvasContext2D_lineJoin_get, v8_CanvasContext2D_lineJoin_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "miterLimit"), v8_CanvasContext2D_miterLimit_get, v8_CanvasContext2D_miterLimit_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "shadowOffsetX"), v8_CanvasContext2D_shadowOffsetX_get, v8_CanvasContext2D_shadowOffsetX_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "shadowOffsetY"), v8_CanvasContext2D_shadowOffsetY_get, v8_CanvasContext2D_shadowOffsetY_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "shadowBlur"), v8_CanvasContext2D_shadowBlur_get, v8_CanvasContext2D_shadowBlur_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "shadowColor"), v8_CanvasContext2D_shadowColor_get, v8_CanvasContext2D_shadowColor_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "lineDashOffset"), v8_CanvasContext2D_lineDashOffset_get, v8_CanvasContext2D_lineDashOffset_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "currentPath"), v8_CanvasContext2D_currentPath_get, v8_CanvasContext2D_currentPath_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "font"), v8_CanvasContext2D_font_get, v8_CanvasContext2D_font_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "textAlign"), v8_CanvasContext2D_textAlign_get, v8_CanvasContext2D_textAlign_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "textBaseline"), v8_CanvasContext2D_textBaseline_get, v8_CanvasContext2D_textBaseline_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "strokeStyle"), v8_CanvasContext2D_strokeStyle_get, v8_CanvasContext2D_strokeStyle_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "fillStyle"), v8_CanvasContext2D_fillStyle_get, v8_CanvasContext2D_fillStyle_set);
	temp_inst->SetAccessor(String::NewFromUtf8(isolate, "imageSmoothingEnaled"), v8_CanvasContext2D_imageSmoothingEnable_get, v8_CanvasContext2D_imageSmoothingEnable_set);

	temp_inst->SetInternalFieldCount(1);
	return temp_class;
}

void setCanvasContext2DClass(Local<Object> parent, Isolate *isolate )
{
	v8::Handle<FunctionTemplate> temp_class = CanvasContext2D_Class(isolate);

	
	parent->Set(String::NewFromUtf8(isolate, "canvas"), temp_class->GetFunction());
}
