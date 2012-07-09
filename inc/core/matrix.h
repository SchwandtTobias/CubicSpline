//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#pragma once

#include <assert.h>
#include <vector>

namespace Core
{
namespace Math
{
    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    class CMatrix
    {

    public:

        static const unsigned int s_MaxNumberOfRows     = TMaxNumberOfRows;
        static const unsigned int s_MaxNumberOfColumns  = TMaxNumberOfColumns;
        static const unsigned int s_MaxNumberOfElements = s_MaxNumberOfColumns * s_MaxNumberOfRows;

    public:
        CMatrix();
        CMatrix(const CMatrix<TDataTypeOfData, TMaxNumberOfRows,TMaxNumberOfColumns>& _Instance);
        ~CMatrix(); 

    public:
        
        bool BreathFistSearch(float _Start, float _Knot);
        bool DepthFirstSearch(float _Start, float _Knot);

    public:

        void TriangularDecomposition(CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>& _rLowerMatrix, CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>& _rUpperMatrix);
        TDataTypeOfData Determinate();
        int Rang();

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
    CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::CMatrix()
    { }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::CMatrix(const CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>& _Instance)
    {
        if (s_MaxNumberOfColumns <= _Instance.s_MaxNumberOfColumns && s_MaxNumberOfRows <= _Instance.s_MaxNumberOfRows)
        {
            for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
            {
                for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
                {
                    _rLowerMatrix[IndexOfColomnElement][IndexOfRowElement] = _Instance[IndexOfColomnElement][IndexOfRowElement];
                    _rUpperMatrix[IndexOfColomnElement][IndexOfRowElement] = _Instance[IndexOfColomnElement][IndexOfRowElement];
                }
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
    void CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::TriangularDecomposition(CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>& _rLowerMatrix, CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>& _rUpperMatrix)
    {
        // -----------------------------------------------------------------------------
        // Dreieckszerlegung: Aufteilung in L und R Matrix
        // -----------------------------------------------------------------------------

        // -----------------------------------------------------------------------------
        // init both matrix
        // -----------------------------------------------------------------------------
        for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
        {
            for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
            {
                _rLowerMatrix[IndexOfColomnElement][IndexOfRowElement] = 0;
                _rUpperMatrix[IndexOfColomnElement][IndexOfRowElement] = m_Lines[IndexOfColomnElement][IndexOfRowElement];

                if (IndexOfColomnElement == IndexOfRowElement)
                {
                    _rLowerMatrix[IndexOfColomnElement][IndexOfRowElement] = 1;
                }
            }
        }

        // -----------------------------------------------------------------------------
        // create R and L Matrix
        // -----------------------------------------------------------------------------
        float ActualFactor;

        for (unsigned int NumberOfTurns = 0; NumberOfTurns < s_MaxNumberOfRows; ++NumberOfTurns)
        {
            for (unsigned int IndexOfColomnElement = (NumberOfTurns + 1); IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
            {
                ActualFactor = _rUpperMatrix[IndexOfColomnElement][NumberOfTurns] / _rUpperMatrix[NumberOfTurns][NumberOfTurns];

                for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
                {
                    _rUpperMatrix[IndexOfColomnElement][IndexOfRowElement] -= (ActualFactor * _rUpperMatrix[NumberOfTurns][IndexOfRowElement]);
                }

                _rLowerMatrix[IndexOfColomnElement][NumberOfTurns] = ActualFactor;
            }
        }
    }

    // -----------------------------------------------------------------------------

    template <typename TDataTypeOfData, unsigned int TMaxNumberOfRows, unsigned int TMaxNumberOfColumns>
    TDataTypeOfData CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns>::Determinate()
    {
        assert(s_MaxNumberOfColumns == s_MaxNumberOfRows);

        CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns> LMatrix;
        CMatrix<TDataTypeOfData, TMaxNumberOfRows, TMaxNumberOfColumns> RMatrix;

        TriangularDecomposition(LMatrix, RMatrix);

        assert(RMatrix.s_MaxNumberOfColumns == RMatrix.s_MaxNumberOfRows);

        TDataTypeOfData Det(-1); 

        if (RMatrix.Rang() == RMatrix.s_MaxNumberOfColumns)
        {
            Det = RMatrix[0][0];

            for (unsigned int IndexOfColumns = 1; IndexOfColumns < RMatrix.s_MaxNumberOfColumns; ++IndexOfColumns)
            {
                Det *= RMatrix[IndexOfColumns][IndexOfColumns];
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

        for (unsigned int IndexOfColomnElement = 0; IndexOfColomnElement < s_MaxNumberOfColumns; ++IndexOfColomnElement)
        {
            for (unsigned int IndexOfRowElement = 0; IndexOfRowElement < s_MaxNumberOfRows; ++IndexOfRowElement)
            {
                Check += m_Lines[IndexOfColomnElement][IndexOfRowElement];
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