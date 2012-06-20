
#pragma once

#include "vector2.h"

#include <vector>


namespace Core
{
	namespace Math
	{
        template<typename T>
		class CCubicSpline
		{
		public:

			CCubicSpline();
			~CCubicSpline();

        public:

            typedef Base::CVector2<T> Point;

		public:

			AddPoint(Point& _rNewPoint);
            T CubicInterpolation(T _XPos);

        private:

            std::vector<Point> m_Points;

        private:
            T CalculateCubic(T _XPos);
		};
	} // namespace Math
} // namespace Core



float cubic_interpolate( float y0, float y1, float y2, float y3, float mu ) {

    float a0, a1, a2, a3, mu2;

    mu2 = mu*mu;
    a0 = y3 - y2 - y0 + y1; //p
    a1 = y0 - y1 - a0;
    a2 = y2 - y0;
    a3 = y1;

    return ( a0*mu*mu2 + a1*mu2 + a2*mu + a3 );
}