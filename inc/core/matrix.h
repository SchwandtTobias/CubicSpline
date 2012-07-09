//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//


#pragma once

#include <vector>

namespace Core
{
namespace Math
{
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    class CMatrix
    {

    public:

        static const unsigned int s_MaxNumberOfRows = TMaxNumberOfRows;
        static const unsigned int s_MaxNumberOfColumns = TMaxNumberOfColumns;
        static const unsigned int s_MaxNumberOfElements = s_MaxNumberOfColumns * s_MaxNumberOfRows;

    public:
        
        bool BreathFistSearch(float _Start, float _Knot);
        bool DepthFirstSearch(float _Start, float _Knot);

    public:

        struct SLine 
        {
                TDataTypeOfData m_Elements[s_MaxNumberOfColumns];
                TDataTypeOfData& operator [](unsigned int _Index);
        };

    public:

        SLine& operator [](unsigned int _Index);

    private:

        SLine  m_Lines[s_MaxNumberOfRows];

    };
} // namespace Math
} // namespace Core


namespace Core
{
namespace Math
{
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    bool CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::BreathFistSearch(float _Start, float _Knot)
    {
        std::vector<int> Warteliste;
        std::vector<bool> Markiert;
        int Aktuell;
        
        for (int IndexOfMarkedElement = 0; IndexOfMarkedElement < s_MaxNumberOfColumns; ++IndexOfMarkedElement) 
        {
            Markiert.push_back(false);
        }
        Markiert[_Start] = true;
        Warteliste.push_back(_Start);
        
        while (Warteliste.size() != 0) 
        {
            Aktuell = Warteliste[0];
            Warteliste.erase(Warteliste.begin());
            
            if (Aktuell == _Knot) 
            {
                return true;
            }
            
            for (int IndexOfElementInColomn = 0; IndexOfElementInColomn < s_MaxNumberOfColumns; ++IndexOfElementInColomn) 
            {
                if (m_Lines[Aktuell][IndexOfElementInColomn] == 1) 
                {
                    if (Markiert[IndexOfElementInColomn] == 0) 
                    {
                        Warteliste.push_back(IndexOfElementInColomn);
                        Markiert[IndexOfElementInColomn] = 1;
                    }
                }
            }
        }
        
        return false;
    }
    
    // -----------------------------------------------------------------------------
    
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    bool CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::DepthFirstSearch(float _Start, float _Knot)
    {
        std::vector<bool> Markiert;  
        for (int IndexOfMarkedElement = 0; IndexOfMarkedElement < s_MaxNumberOfColumns; ++IndexOfMarkedElement) 
        {
            Markiert.push_back(false);
        }
        Markiert[_Start] = true;
        
        std::vector<float> Stack;
        Stack.push_back(_Start);
        
        int Aktuell;
        
        while (Stack.size() != 0) 
        {
            Aktuell = Stack[Stack.size() - 1];
            Markiert[Aktuell] = 1;
            
            if (Aktuell == _Knot) 
            {
                return true;
            }
            
            bool NeighborsInside = false;
            
            for (int IndexOfElementInColomn = 0; IndexOfElementInColomn < s_MaxNumberOfColumns; ++IndexOfElementInColomn) 
            {
                if (m_Lines[Aktuell][IndexOfElementInColomn] == 1) 
                {
                    if (Markiert[IndexOfElementInColomn] == 0) 
                    {
                        Stack.push_back(IndexOfElementInColomn);
                        
                        NeighborsInside = true;
                        
                        break;
                    }
                }
            }
            
            if (NeighborsInside == 0) 
            {
                Stack.pop_back();
            }
        }
        
        return false;
    }

    // -----------------------------------------------------------------------------
    
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    typename CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::SLine& CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::operator [](unsigned int _Index)
    {
        return m_Lines[_Index];
    }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    TDataTypeOfData& CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::SLine::operator [](unsigned int _Index)
    {
        return m_Elements[_Index];
    }
} // namespace Math
} // namespace Core