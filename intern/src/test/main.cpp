

#include "core/vector2.h"
#include "core/spline.h"


int main()
{
    Core::Math::CSpline MyCubicSpline;

    Core::Float2 P1(-1, 2);
    Core::Float2 P2( 0, 1);
    Core::Float2 P3( 1, 2);
    Core::Float2 P4( 2, 1);

    MyCubicSpline.AddPoint(P1);
    MyCubicSpline.AddPoint(P2);
    MyCubicSpline.AddPoint(P3);
    MyCubicSpline.AddPoint(P4);

    float Ret = MyCubicSpline.CubicInterpolation(0.8f);

	return 0;
}

