#include "stdafx.h"
#include "app_cubic_spline/Spline.h"

#include "core/vector2.h"

#include <algorithm>

CSpline::CSpline()
{
    m_pCubicSpline = new Core::Math::CCubicSpline();
    m_pPoints = new std::vector<Core::Math::Float2>;
}

// -----------------------------------------------------------------------------

CSpline::~CSpline()
{

}

// -----------------------------------------------------------------------------

void CSpline::AddPoint(int _X, int _Y)
{
    Core::Math::Float2 NewPoint;
    NewPoint[0] = _X;
    NewPoint[1] = _Y;

    bool PointCanBeAdded;

    PointCanBeAdded = m_pCubicSpline->AddPoint(NewPoint);

    if (PointCanBeAdded)
    {
        m_pPoints->push_back(NewPoint);

        std::sort(m_pPoints->begin(), m_pPoints->end());
    }
}

// -----------------------------------------------------------------------------

void CSpline::RemovePoint(const int _Index)
{
    bool ValueCanBeRemoved;

    // -----------------------------------------------------------------------------
    // remove point @ index
    // -----------------------------------------------------------------------------
    ValueCanBeRemoved = m_pCubicSpline->RemovePointOnIndex(_Index);

    if (ValueCanBeRemoved)
    {
        // -----------------------------------------------------------------------------
        // remove point from internal list
        // -----------------------------------------------------------------------------
        m_pPoints->erase(m_pPoints->begin() + _Index);
    }
}

// -----------------------------------------------------------------------------

std::vector<Core::Math::Float2> CSpline::GetPoints()
{
    return *m_pPoints;
}

// -----------------------------------------------------------------------------

float CSpline::MaxX()
{
    return m_pCubicSpline->MaxX();
}

// -----------------------------------------------------------------------------

float CSpline::MinX()
{
    return m_pCubicSpline->MinX();
}

// -----------------------------------------------------------------------------

float CSpline::Interpolate(float _X)
{
    return m_pCubicSpline->Interpolate(_X);
}