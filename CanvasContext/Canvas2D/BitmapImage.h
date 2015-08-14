#ifndef __BITMAPIMAGE_H__
#define __BITMAPIMAGE_H__

#include "SkBitmap.h"
#include "string"
#include "RefCounted.h"
#include "passrefptr.h"

class BitmapImage : public RefCounted<BitmapImage >
{
public:
	BitmapImage();
	~BitmapImage();	
	static PassRefPtr<BitmapImage> create()
	{
		return adoptRef(new BitmapImage());
	}
	void src(std::string src);
	SkBitmap &bitmap() { return m_bitmap; }
private:
	std::string m_imagesrc;
	SkBitmap m_bitmap;
	SkImageInfo m_bitmapInfo;
};


#endif

