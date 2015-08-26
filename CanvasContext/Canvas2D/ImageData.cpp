#include "ImageData.h"

namespace Canvas2D {

PassRefPtr<ImageData> ImageData::create(int w, int h)
{
    return adoptRef(new ImageData(w, h));
}

ImageData::~ImageData()
{
	delete[]m_data;
}

ImageData::ImageData(int w, int h)
    : m_width(w)
	, m_height( h)
{
	m_data = new unsigned char[m_width * m_height * 4];
}

}

