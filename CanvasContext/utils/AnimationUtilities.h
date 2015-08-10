#ifndef AnimationUtilities_h
#define AnimationUtilities_h

#include "LayoutUnit.h"
#include "SkPoint.h"
#include "IntPoint.h"

namespace WebCore {

inline int blend(int from, int to, double progress)
{
    return lround(from + (to - from) * progress);
}

// For unsigned types.
template <typename T>
inline T blend(T from, T to, double progress)
{
    return clampTo<T>(round(to > from ? from + (to - from) * progress : from - (from - to) * progress));
}

inline double blend(double from, double to, double progress)
{
    return from + (to - from) * progress;
}

inline float blend(float from, float to, double progress)
{
    return static_cast<float>(from + (to - from) * progress);
}

inline LayoutUnit blend(LayoutUnit from, LayoutUnit to, double progress)
{
    return from + (to - from) * progress;
}

inline IntPoint blend(const IntPoint& from, const IntPoint& to, double progress)
{
    return IntPoint(blend(from.x(), to.x(), progress), blend(from.y(), to.y(), progress));
}

inline SkPoint blend(const SkPoint& from, const SkPoint& to, double progress)
{
    return SkPoint::Make(blend(from.x(), to.x(), progress), blend(from.y(), to.y(), progress));
}

// Calculates the accuracy for evaluating a timing function for an animation with the specified duration.
inline double accuracyForDuration(double duration)
{
    return 1.0 / (200.0 * duration);
}

} // namespace WebCore

#endif // AnimationUtilities_h
