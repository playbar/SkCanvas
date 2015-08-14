#ifndef ImageData_h
#define ImageData_h

#include "RefCounted.h"
#include "RefPtr.h"

namespace WebCore {

class ImageData : public RefCounted<ImageData> 
{
public:
    static PassRefPtr<ImageData> create(int w, int h);

	int width() const	{ return m_width; }
    int height() const	{ return m_height; }
	int length() const	{ return m_width * m_height * 4; }
    unsigned char* data()const { return m_data; }
	void zeroFill(){ memset(m_data, 0, m_width * m_height * 4); };
	~ImageData();
private:
	ImageData(int w, int h);

    int m_width;
	int m_height;
    unsigned char *m_data;
};

} // namespace WebCore

#endif // ImageData_h
