//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#include "core/function.h"

#include "core/math_defines.h"

#include <assert.h>
#include <cmath>

namespace Core
{
namespace Math
{

    const float IFunction1Base::s_Interval = 0.5f;
    const float IFunction1Base::s_H        = 0.00001f;

    // -----------------------------------------------------------------------------

    float IFunction1Base::func1(float _Value0)
    {
        return ((func(_Value0 + s_H) - func(_Value0)) / s_H);
    }
    
    // -----------------------------------------------------------------------------
    
    float IFunction1Base::func2(float _Value0)
    {
        return (func(_Value0 + s_H) + func(_Value0 - s_H) - 2 * func(_Value0)) / (s_H * s_H);
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
    
    // -----------------------------------------------------------------------------
    
    float IFunction1Base::Root(float _Start)
    {
        // -----------------------------------------------------------------------------
        // newton algorithm
        // -----------------------------------------------------------------------------
        float xi = _Start;
        
        for (;;) 
        {
            if (std::abs(func(xi)) < EPSILON) 
            {
                break;
            }
            
            xi = xi - (func(xi) / func1(xi));
        }
        
        return xi;
    }

    // -----------------------------------------------------------------------------

    float IFunction1Base::Root(float _Start, float _End)
    {
        // -----------------------------------------------------------------------------
        // bisection
        // -----------------------------------------------------------------------------
        float a;
        float b;

        a = _Start;
        b = _End;

        float x = (a + b) / 2.0f;

        for(;;)
        {
            if (std::abs(func(x)) < EPSILON)
            {
                break;
            }

            x = (a + b) / 2.0f;

            if (func(a) * func(x) < 0)
            {
                b = x;
            }
            else
            {
                a = x;
            }
        }

        return x;
    }

    // -----------------------------------------------------------------------------

    float IFunction1Base::RootRegula(float _Start, float _End)
    {
        // -----------------------------------------------------------------------------
        // regula falsi
        // -----------------------------------------------------------------------------
        float a;
        float b;

        a = _Start;
        b = _End;

        float x = (b * func(a) - a * func(b)) / (func(a) - func(b));

        int Counter = 0;

        for(;;)
        {
            if (std::abs(func(x)) < EPSILON)
            {
                break;
            }

            x = (b * func(a) - a * func(b)) / (func(a) - func(b));

            if (func(a) * func(x) < 0)
            {
                b = x;
            }
            else
            {
                a = x;
            }
        }

        return x;
    }
    
    // -----------------------------------------------------------------------------
    
    float IFunction1Base::Minima(float _Start, float _End)
    {
        assert(_Start < _End);
        
        // -----------------------------------------------------------------------------
        // golden section
        // -----------------------------------------------------------------------------
        float s;
        
        float xa;
        float fa;
        
        float xb;
        float fb;
        
        float a;
        float b;
        
        a = _Start;
        b = _End;
        
        s = 0.38196f;
        
        xa = a + s * (b - a);
        fa = func(xa);
        xb = b - s * (b - a);
        fb = func(xb);
        
        for (;;) 
        {
            if (b - a < EPSILON) 
            {
                break;
            }
            
            if (fa > fb) 
            {
                a  = xa;
                xa = xb;
                fa = fb;
                xb = b - s * (b - a);
                fb = func(xb);
            }
            else 
            {
                b  = xb;
                xb = xa;
                fb = fa;
                xa = a + s * (b - a);
                fa = func(xa);
            }
        }
        
        if (func(a) > func(b)) 
        {
            return b;
        }
        else 
        {
            return a;
        }
    }
}
}