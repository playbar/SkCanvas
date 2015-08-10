#include "CanvasContext2D.h"

CanvasStyle *CanvasContext2D::strokeStyle() const
{
	return NULL;
}

void CanvasContext2D::setStrokeStyle(PassRefPtr<CanvasStyle>)
{

}

CanvasStyle* CanvasContext2D::fillStyle() const
{
	return NULL;
}
void CanvasContext2D::setFillStyle(PassRefPtr<CanvasStyle>)
{

}

float CanvasContext2D::lineWidth() const
{
	return 0.0f;
}
void CanvasContext2D::setLineWidth(float)
{
	
}

std::string CanvasContext2D::lineCap() const
{
	return "";
}
void CanvasContext2D::setLineCap(const std::string&)
{

}

std::string CanvasContext2D::lineJoin() const
{
	return "";
}
void CanvasContext2D::setLineJoin(const std::string&)
{

}

float CanvasContext2D::miterLimit() const
{
	return 0.0f;
}
void CanvasContext2D::setMiterLimit(float)
{

}

const std::vector<float>& CanvasContext2D::getLineDash() const
{
	std::vector<float> temp;
	return temp;
}
void CanvasContext2D::setLineDash(const std::vector<float>&)
{

}

float CanvasContext2D::lineDashOffset() const
{
	return 0.0f;
}
void CanvasContext2D::setLineDashOffset(float)
{

}

float CanvasContext2D::shadowOffsetX() const
{
	return 0.0f;
}
void CanvasContext2D::setShadowOffsetX(float)
{

}

float CanvasContext2D::shadowOffsetY() const
{
	return 0.0f;
}

void CanvasContext2D::setShadowOffsetY(float)
{

}

float CanvasContext2D::shadowBlur() const
{
	return 0.0f;
}

void CanvasContext2D::setShadowBlur(float)
{

}

std::string CanvasContext2D::shadowColor() const
{
	return "";
}
void CanvasContext2D::setShadowColor(const std::string&)
{

}

float CanvasContext2D::globalAlpha() const
{
	return 0.0f;
}
void CanvasContext2D::setGlobalAlpha(float)
{

}

std::string CanvasContext2D::globalCompositeOperation() const
{
	return "";
}
void CanvasContext2D::setGlobalCompositeOperation(const std::string&)
{

}

void CanvasContext2D::save()
{
}
void CanvasContext2D::restore()
{

}


void CanvasContext2D::setCurrentTransform(PassRefPtr<AffineTransform>)
{

}

void CanvasContext2D::scale(float sx, float sy)
{

}

void CanvasContext2D::rotate(float angleInRadians)
{}

void CanvasContext2D::translate(float tx, float ty)
{

}
void CanvasContext2D::transform(float m11, float m12, float m21, float m22, float dx, float dy)
{

}
void CanvasContext2D::setTransform(float m11, float m12, float m21, float m22, float dx, float dy)
{

}
void CanvasContext2D::resetTransform()
{

}

void CanvasContext2D::setStrokeColor(const std::string& color)
{

}
void CanvasContext2D::setStrokeColor(float grayLevel)
{

}
void CanvasContext2D::setStrokeColor(const std::string& color, float alpha)
{

}
void CanvasContext2D::setStrokeColor(float grayLevel, float alpha)
{

}
void CanvasContext2D::setStrokeColor(float r, float g, float b, float a)
{

}
void CanvasContext2D::setStrokeColor(float c, float m, float y, float k, float a)
{

}

void CanvasContext2D::setFillColor(const std::string &color)
{

}
void CanvasContext2D::setFillColor(float grayLevel)
{

}
void CanvasContext2D::setFillColor(const std::string& color, float alpha)
{

}
void CanvasContext2D::setFillColor(float grayLevel, float alpha)
{

}
void CanvasContext2D::setFillColor(float r, float g, float b, float a)
{

}
void CanvasContext2D::setFillColor(float c, float m, float y, float k, float a)
{

}


