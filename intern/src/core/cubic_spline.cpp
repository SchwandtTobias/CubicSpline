
#include "core/cubic_spline.h"

#include <algorithm>

namespace Core
{
namespace Math
{
    void CCubicSpline::AddPoint(Float2& _rNewPoint)
    {
        // -----------------------------------------------------------------------------
        // add point to list
        // -----------------------------------------------------------------------------        
        m_Points.push_back(_rNewPoint);
        m_Z.push_back(0.0f);
        
        if (m_MinX > _rNewPoint[0]) {
            m_MinX = _rNewPoint[0];
        }
        else if (m_MaxX < _rNewPoint[0]) {
            m_MaxX = _rNewPoint[0];
        }

        BuildCoef();
    }

    // -----------------------------------------------------------------------------

    float CCubicSpline::Interpolate(float _XPos)
    {
        return Interp(_XPos);
    }
    
    // -----------------------------------------------------------------------------
    
    float CCubicSpline::MinX()
    {
        return m_MinX;
    }
    
    // -----------------------------------------------------------------------------
    
    float CCubicSpline::MaxX()
    {
        return m_MaxX;
    }

    // -----------------------------------------------------------------------------

    void CCubicSpline::BuildCoef()
    {
        // -----------------------------------------------------------------------------
        // build coef
        // -----------------------------------------------------------------------------
        int n = m_Points.size();
        if (n <= 1) return;

        float* pH = new float[n];
        float* pB = new float[n];
        float* pU = new float[n];
        float* pV = new float[n];

        for (int i = 0; i < n - 1; ++i)
        {
            pH[i] = m_Points[i + 1][0] - m_Points[i][0];
            pB[i] = (m_Points[i + 1][1] - m_Points[i][1]) / pH[i];
        }

        pU[1] = 2 * (pH[0] + pH[1]);
        pV[1] = 6 * (pB[1] - pB[0]);

        for (int i = 2; i < n - 1; ++i)
        {
            pU[i] = 2 * (pH[i] + pH[i - 1]) - (pH[i - 1] * pH[i - 1] / pU[i - 1]);
            pV[i] = 6 * (pB[i] - pB[i - 1]) - (pH[i - 1] * pV[i - 1] / pU[i - 1]);
        }

        m_Z[n - 1] = 0;

        for (int i = n - 1 - 1; i >= 1; --i)
        {
            m_Z[i] = (pV[i] - pH[i] * m_Z[i + 1]) / pU[i];
        }

        m_Z[0] = 0;


        // -----------------------------------------------------------------------------
        // delete temporary arrays
        // -----------------------------------------------------------------------------
        delete[] pV;
        delete[] pU;
        delete[] pB;
        delete[] pH;
    }

    // -----------------------------------------------------------------------------

    float CCubicSpline::Interp(float _XPos)
    {
        // -----------------------------------------------------------------------------
        // evaluate spline
        // -----------------------------------------------------------------------------
        int n = m_Points.size();
        if (n <= 1) return 0.0f;

        int i;
        float h;
        float tmp;

        for (i = 0; i < n - 1; ++i)
        {
            if (_XPos - m_Points[i][0] >= 0)
            {
                break;
            }
        }

        h = m_Points[i + 1][0] - m_Points[i][0];

        tmp = (m_Z[i] / 2) + ( ( (_XPos - m_Points[i][0]) * (m_Z[i + 1] - m_Z[i]) ) / (6 * h) );
        tmp = -(h / 6) * (m_Z[i + 1] + 2 * m_Z[i]) + ((m_Points[i + 1][1] - m_Points[i][1]) / h) + ((_XPos - m_Points[i][0]) * tmp);

        return m_Points[i][1] + (_XPos - m_Points[i][0]) * tmp;
    }
}
}