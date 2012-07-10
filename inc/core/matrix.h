//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#pragma once

#include <assert.h>
#include <string.h>
#include <vector>

namespace Core
{
namespace Math
{
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    class CMatrix
    {
    public:
        
        typedef CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns> CThis;

    public:

        static const unsigned int s_MaxNumberOfRows     = TMaxNumberOfRows;
        static const unsigned int s_MaxNumberOfColumns  = TMaxNumberOfColumns;
        static const unsigned int s_MaxNumberOfElements = s_MaxNumberOfColumns * s_MaxNumberOfRows;

    public:
        
        CMatrix();
        CMatrix(const CThis& _Instance);
        ~CMatrix(); 

    public:
        
        bool BreathFistSearch(float _Start, float _Knot);
        bool DepthFirstSearch(float _Start, float _Knot);

    public:

        void TriangularDecomposition(CThis& _rLowerMatrix, CThis& _rUpperMatrix);
        TDataTypeOfData Determinate();
        int Rang();

    public:

        struct SLine 
        {
            TDataTypeOfData m_Elements[s_MaxNumberOfColumns];
            
            TDataTypeOfData& operator [](const unsigned int _Index);
            const TDataTypeOfData& operator [](const unsigned int _Index) const;
        };
        
    public:
        
        bool operator == (const CThis& _rRight) const;
        bool operator != (const CThis& _rRight) const;

    public:

        SLine& operator [] (const unsigned int _Index);
        const SLine& operator [] (const unsigned int _Index) const;

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
    CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::CMatrix()
    { }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::CMatrix(const CThis& _Instance)
    {
        for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
        {
            for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
            {
                m_Lines[IndexOfRowElement][IndexOfColomnElement] = _Instance[IndexOfRowElement][IndexOfColomnElement];
                m_Lines[IndexOfRowElement][IndexOfColomnElement] = _Instance[IndexOfRowElement][IndexOfColomnElement];
            }
        }
    }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::~CMatrix()
    { }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    bool CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::BreathFistSearch(float _Start, float _Knot)
    {
        std::vector<int> WaitingQueue;
        std::vector<bool> MarkedKnots;
        int ActualElement;
        
        for (int IndexOfMarkedElement = 0; IndexOfMarkedElement < s_MaxNumberOfColumns; ++IndexOfMarkedElement) 
        {
            MarkedKnots.push_back(false);
        }
        MarkedKnots[_Start] = true;
        WaitingQueue.push_back(_Start);
        
        while (WaitingQueue.size() != 0) 
        {
            ActualElement = WaitingQueue[0];
            WaitingQueue.erase(WaitingQueue.begin());
            
            if (ActualElement == _Knot) 
            {
                return true;
            }
            
            for (int IndexOfElementInColomn = 0; IndexOfElementInColomn < s_MaxNumberOfColumns; ++IndexOfElementInColomn) 
            {
                if (m_Lines[ActualElement][IndexOfElementInColomn] == 1) 
                {
                    if (MarkedKnots[IndexOfElementInColomn] == 0) 
                    {
                        WaitingQueue.push_back(IndexOfElementInColomn);
                        MarkedKnots[IndexOfElementInColomn] = 1;
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
        std::vector<bool> MarkedKnots;  
        for (int IndexOfMarkedElement = 0; IndexOfMarkedElement < s_MaxNumberOfColumns; ++IndexOfMarkedElement) 
        {
            MarkedKnots.push_back(false);
        }
        MarkedKnots[_Start] = true;
        
        std::vector<float> Stack;
        Stack.push_back(_Start);
        
        int ActualElement;
        
        while (Stack.size() != 0) 
        {
            ActualElement = Stack[Stack.size() - 1];
            MarkedKnots[ActualElement] = 1;
            
            if (ActualElement == _Knot) 
            {
                return true;
            }
            
            bool NeighborsInside = false;
            
            for (int IndexOfElementInColomn = 0; IndexOfElementInColomn < s_MaxNumberOfColumns; ++IndexOfElementInColomn) 
            {
                if (m_Lines[ActualElement][IndexOfElementInColomn] == 1) 
                {
                    if (MarkedKnots[IndexOfElementInColomn] == 0) 
                    {
                        Stack.push_back(IndexOfElementInColomn);
                        
                        NeighborsInside = true;
                        
                        break;
                    }
                }
            }
            
            if (NeighborsInside == false) 
            {
                Stack.pop_back();
            }
        }
        
        return false;
    }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    void CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::TriangularDecomposition(CThis& _rLowerMatrix, CThis& _rUpperMatrix)
    {
        // -----------------------------------------------------------------------------
        // Dreieckszerlegung: Aufteilung in L und R Matrix
        // -----------------------------------------------------------------------------

        // -----------------------------------------------------------------------------
        // init both matrix
        // -----------------------------------------------------------------------------
        for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
        {
            for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
            {
                _rLowerMatrix[IndexOfRowElement][IndexOfColomnElement] = 0;
                _rUpperMatrix[IndexOfRowElement][IndexOfColomnElement] = m_Lines[IndexOfRowElement][IndexOfColomnElement];

                if (IndexOfColomnElement == IndexOfRowElement)
                {
                    _rLowerMatrix[IndexOfRowElement][IndexOfColomnElement] = 1;
                }
            }
        }

        // -----------------------------------------------------------------------------
        // create R and L Matrix
        // -----------------------------------------------------------------------------
        float ActualFactor;

        for (unsigned int NumberOfTurns = 0; NumberOfTurns < s_MaxNumberOfRows; ++NumberOfTurns)
        {
            for (unsigned int IndexOfRowElement = (NumberOfTurns + 1); IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
            {
                ActualFactor = _rUpperMatrix[IndexOfRowElement][NumberOfTurns] / _rUpperMatrix[NumberOfTurns][NumberOfTurns];

                for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
                {
                    _rUpperMatrix[IndexOfRowElement][IndexOfColomnElement] -= (ActualFactor * _rUpperMatrix[NumberOfTurns][IndexOfColomnElement]);
                }

                _rLowerMatrix[IndexOfRowElement][NumberOfTurns] = ActualFactor;
            }
        }
    }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    TDataTypeOfData CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::Determinate()
    {
        CThis LMatrix;
        CThis RMatrix;

        TriangularDecomposition(LMatrix, RMatrix);

        TDataTypeOfData Det(-1); 

        if (RMatrix.Rang() == s_MaxNumberOfColumns)
        {
            Det = RMatrix[0][0];

            for (unsigned int IndexOfElement = 1; IndexOfElement < s_MaxNumberOfColumns; ++IndexOfElement)
            {
                Det *= RMatrix[IndexOfElement][IndexOfElement];
            }
        }

        return Det;
    }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    int CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::Rang()
    {
        // -----------------------------------------------------------------------------
        // returns rang of matrix
        // -----------------------------------------------------------------------------

        int ZeroRang = 0;
        int Check = 0;

        for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
        {
            for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
            {
                Check += m_Lines[IndexOfRowElement][IndexOfColomnElement];
            }

            if (Check == 0)
            {
                ++ZeroRang;
            }

            Check = 0;
        }

        return s_MaxNumberOfColumns - ZeroRang;
    }
    
    // -----------------------------------------------------------------------------
    
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    bool CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::operator == (const CThis& _rRight) const
    {
        bool IsEqual = false;
        
        for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
        {
            for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
            {
                IsEqual = m_Lines[IndexOfRowElement][IndexOfColomnElement] == _rRight[IndexOfRowElement][IndexOfColomnElement];
                
                if (IsEqual == false) 
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    // -----------------------------------------------------------------------------
    
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    bool CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::operator != (const CThis& _rRight) const
    {
        bool IsEqual = false;
        
        for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
        {
            for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
            {
                IsEqual = m_Lines[IndexOfRowElement][IndexOfColomnElement] == _rRight[IndexOfRowElement][IndexOfColomnElement];
                
                if (IsEqual == false) 
                {
                    return true;
                }
            }
        }
        
        return false;
    }

    // -----------------------------------------------------------------------------
    
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    typename CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::SLine& CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::operator [](const unsigned int _Index)
    {
        return m_Lines[_Index];
    }
    
    // -----------------------------------------------------------------------------
    
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    const typename CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::SLine& CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::operator [](const unsigned int _Index) const
    {
        return m_Lines[_Index];
    }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    TDataTypeOfData& CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::SLine::operator [](const unsigned int _Index)
    {
        return m_Elements[_Index];
    }
    
    // -----------------------------------------------------------------------------
    
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    const TDataTypeOfData& CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::SLine::operator [](const unsigned int _Index) const
    {
        return m_Elements[_Index];
    }
} // namespace Math
} // namespace Core

namespace Core
{
namespace Math
{
    
    typedef CMatrix<int, 3, 3> CIntMatrix3x3;
    typedef CMatrix<int, 4, 4> CIntMatrix4x4;
    typedef CMatrix<int, 5, 5> CIntMatrix5x5;
    
    typedef CMatrix<float, 3, 3> CFloatMatrix3x3;
    typedef CMatrix<float, 4, 4> CFloatMatrix4x4;
    typedef CMatrix<float, 5, 5> CFloatMatrix5x5;
    
} // namespace Math
} // namespace Core