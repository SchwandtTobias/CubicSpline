#include "stdafx.h"
#include "app_cubic_spline/Spline.h"

#include "core/vector2.h"

CSpline::CSpline()
{
    m_pCubicSpline = new Core::Math::CCubicSpline();
    m_pPoints = new std::vector<Core::Math::Float2*>;
}

// -----------------------------------------------------------------------------

CSpline::~CSpline()
{

}

// -----------------------------------------------------------------------------

void CSpline::AddPoint(int _X, int _Y)
{
    Core::Math::Float2* NewPoint = new Core::Math::Float2();
    (*NewPoint)[0] = _X;
    (*NewPoint)[1] = _Y;

    m_pPoints->push_back(NewPoint);

    m_pCubicSpline->AddPoint(*NewPoint);
}

// -----------------------------------------------------------------------------

std::vector<Core::Math::Float2*> CSpline::GetPoints()
{
    return *m_pPoints;
}

// -----------------------------------------------------------------------------

int CSpline::MaxX()
{
    return m_pCubicSpline->MaxX();
}

// -----------------------------------------------------------------------------

int CSpline::MinX()
{
    return m_pCubicSpline->MinX();
}

// -----------------------------------------------------------------------------

int CSpline::Interpolate(int _X)
{
    return m_pCubicSpline->Interpolate(_X);
}