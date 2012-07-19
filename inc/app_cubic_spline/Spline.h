//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#pragma once

#include "core/cubic_spline.h"

#include <cliext/vector>

ref class CSpline
{
public:

    CSpline();
    ~CSpline();

public:

    void AddPoint(int _X, int _Y);
    void RemovePoint(const int _Index);

    float  MinX();
    float  MaxX();

    float Interpolate(float _X);

    std::vector<Core::Math::Float2> GetPoints();

private:

    Core::Math::CCubicSpline* m_pCubicSpline;
    std::vector<Core::Math::Float2>* m_pPoints;
};

