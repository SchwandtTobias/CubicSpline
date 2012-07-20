//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

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

		bool AddPoint(Float2& _rNewPoint);
        bool RemovePointWithPosition(float _XPos);
        bool RemovePointOnIndex(unsigned int _Index);

        float Interpolate(float _XPos);
        
        float MinX();
        float MaxX();
        
        int SizeOfPoints();

    private:

        typedef std::vector<Float2>     CPoints;
        typedef CPoints::const_iterator CPointInterator;

        typedef std::vector<float>      CZ;

    private:

        CPoints m_Points;
        CZ      m_Z;
        
        float   m_MinX;
        float   m_MaxX;
        
        bool    m_Dirty;

    private:
        void BuildCoef();
        float Interp(float _XPos);
	};
} // namespace Math
} // namespace Core