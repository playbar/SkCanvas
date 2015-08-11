#ifndef NullPtr_h
#define NullPtr_h

#ifndef __WIN32

namespace std{
class nullptr_t{};
}
#endif


#define WTF_DISALLOW_CONSTRUCTION_FROM_ZERO(ClassName) \
    private: \
        ClassName(int)
#define WTF_DISALLOW_ZERO_ASSIGNMENT(ClassName) \
    private: \
        ClassName& operator=(int)

#endif
