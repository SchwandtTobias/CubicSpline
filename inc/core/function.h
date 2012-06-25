//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#pragma once

namespace Core
{
namespace Math
{
    
    class IFunction1Base
    {
    public:
        static const int s_NumberOfBases = 1;
        
    public:
        virtual float func(float _Value0) = 0;
        
    public:
        float func1(float _Value0);
        float func2(float _Value0);
        float funcx(float _Value0, float (*_pFunc)(const float));
        
        float Area(float _Start, float _End);
        
    private:
        static const float s_Interval = 0.5f;
        static const float s_H        = 0.00001f;
    };    
}// namespace Math
}// namespace Core