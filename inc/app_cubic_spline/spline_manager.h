//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#pragma once

#include "Spline.h"

#include "core/vector2.h"

#include <cliext/vector>

ref class CSplineManager
{

public:

    static const int s_MAXSPLINES = 3;

public:

    CSplineManager();
    ~CSplineManager();

public:

    CSpline^ GetSpline(const int _Index);
    std::vector<Core::Math::Float2> GetPoints(const int _Index);
    void RemovePoint(const int _IndexOfSpline, const int _IndexOfPoint);

private:

    cliext::vector<CSpline^>  m_Splines;
};

