
#pragma once

#include "core/vector2.h"

#include <vector>


namespace Core
{
namespace Math
{
	class CCubicSpline
	{
	public:

		void AddPoint(Float2& _rNewPoint);
        float Interpolate(float _XPos);
        
        float MinX();
        float MaxX();

    private:

        typedef std::vector<Float2>     CPoints;
        typedef CPoints::const_iterator CPointInterator;

        typedef std::vector<float>      CZ;

    private:

        CPoints m_Points;
        CZ      m_Z;
        
        float   m_MinX;
        float   m_MaxX;

    private:
        void BuildCoef();
        float Interp(float _XPos);
	};
} // namespace Math
} // namespace Core