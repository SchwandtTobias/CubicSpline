
#include "core/spline.h"

namespace Core
{
namespace Math
{
    void CSpline::AddPoint(Float2& _rNewPoint)
    {
        m_Points.push_back(_rNewPoint);
    }

    // -----------------------------------------------------------------------------

    float CSpline::CubicInterpolation(float _XPos)
    {
        float a0, a1, a2, a3, mu1, mu2;

        mu1 = _XPos;
        mu2 = _XPos * _XPos;
        a0 = m_Points[3][1] - m_Points[2][1] - m_Points[0][1] + m_Points[1][1]; //p
        a1 = m_Points[0][1] - m_Points[1][1] - a0;
        a2 = m_Points[2][1] - m_Points[0][1];
        a3 = m_Points[1][1];

        return ( a0*mu1*mu2 + a1*mu2 + a2*mu1 + a3 );
    }

    // -----------------------------------------------------------------------------

    float CSpline::CalculateCubic(float _XPos)
    {
        return 0;
    }
}
}