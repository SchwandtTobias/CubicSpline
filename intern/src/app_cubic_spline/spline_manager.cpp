
#include "StdAfx.h"
#include "app_cubic_spline/spline_manager.h"

CSplineManager::CSplineManager()
    : m_Splines(s_MAXSPLINES)
{
    for (int IndexOfSpline = 0; IndexOfSpline < s_MAXSPLINES; ++IndexOfSpline)
    {
        m_Splines[IndexOfSpline] = gcnew CSpline();
    }
}

// -----------------------------------------------------------------------------
CSplineManager::~CSplineManager()
{

}

// -----------------------------------------------------------------------------

CSpline^ CSplineManager::GetSpline(const int _Index)
{
    return m_Splines[_Index];
}

// -----------------------------------------------------------------------------

std::vector<Core::Math::Float2> CSplineManager::GetPoints(const int _Index)
{
    return m_Splines[_Index]->GetPoints();
}

// -----------------------------------------------------------------------------

void CSplineManager::RemovePoint(const int _IndexOfSpline, const int _IndexOfPoint)
{
    m_Splines[_IndexOfSpline]->RemovePoint(_IndexOfPoint);
}