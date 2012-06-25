//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#pragma once

namespace Core 
{
namespace Math
{
    
    CMatrix2x2
    {
    public:
        CMatrix2x2();
        CMatrix2x2(float _Value);
        CMatrix2x2(float _Value0, float _Value1, float _Value2, float _Value3);
        
    public:
        
        
        
        
    private:
        struct
        {
            union
            {
                struct
                {
                    float m_V0;
                    float m_V1;
                    float m_V2;
                    float m_V3;
                };
                float[4]    m_V;
                float[2][2] m_M;
            };
        };
    }
        
}
}