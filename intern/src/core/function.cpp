//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#include "core/function.h"

namespace Core
{
namespace Math
{

    const float IFunction1Base::s_Interval = 0.5f;
    const float IFunction1Base::s_H        = 0.00001f;


    float IFunction1Base::func1(float _Value0)
    {
        return ((func(_Value0 + s_H) - func(_Value0)) / s_H);
    }
    
    // -----------------------------------------------------------------------------
    
    float IFunction1Base::funcx(float _Value0, float (*_pFunc)(const float))
    {
        return ((_pFunc(_Value0 + s_H) - _pFunc(_Value0)) / s_H);
    }
    
    // -----------------------------------------------------------------------------
    
    float IFunction1Base::Area(float _Start, float _End)
    {
        // -----------------------------------------------------------------------------
        // Trapezverfahren
        // -----------------------------------------------------------------------------
        
        float Result1;
        Result1 = 0.0f;
        
        float ValueX;
        ValueX = s_Interval;
        
        for (int StepsToCalculate = 0; StepsToCalculate < 3; ++StepsToCalculate) 
        {
            Result1 += func(ValueX);
            ValueX  += s_Interval;
        }
        
        float Result2;
        Result2 = (_Start * _Start + _End * _End) / 2;
        
        float Result = (Result1 + Result2) * s_Interval;
        
        if (Result < 0) 
        {
            Result *= -1;
        }
        
        return Result;
    }
}
}