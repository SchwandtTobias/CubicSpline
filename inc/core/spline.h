
#pragma once

#include "core/vector2.h"

#include <vector>


namespace Core
{
namespace Math
{
	class CSpline
	{
	public:

		void AddPoint(Float2& _rNewPoint);
        float CubicInterpolation(float _XPos);

    private:

        typedef std::vector<Float2>     CPoints;
        typedef CPoints::const_iterator CPointInterator;

    private:

        CPoints m_Points;

    private:
        float CalculateCubic(float _XPos);
	};
} // namespace Math
} // namespace Core