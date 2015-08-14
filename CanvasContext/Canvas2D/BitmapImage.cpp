#include "BitmapImage.h"
#include "SkStream.h"
#include "SkImageDecoder.h"

BitmapImage::BitmapImage()
{

}

BitmapImage::~BitmapImage()
{

}

void BitmapImage::src( std::string src )
{
	m_imagesrc = src;
	SkFILEStream stream( src.c_str());
	SkImageDecoder * code = SkImageDecoder::Factory(&stream);
	code->decode(&stream, &m_bitmap, SkColorType::kRGBA_8888_SkColorType, SkImageDecoder::kDecodePixels_Mode);
	return;
}
