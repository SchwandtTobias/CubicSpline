
#pragma once

template <typename TDataTypeOfData, unsigned int TMaxNumberOfItems>
class CVector
{

    public:

        static const unsigned int s_MaxNumberOfElements = TMaxNumberOfItems;

    public:

        SLine& operator [](unsigned int _Index);

    private:

        TDataTypeOfData  m_Elements[s_MaxNumberOfRows];

};

template <typename TDataTypeOfData, unsigned int TMaxNumberOfItems>
TDataTypeOfData CMatrix<TDataTypeOfData, TMaxNumberOfItems>::operator [](unsigned int _Index)
{
    return m_Lines[m_Elements];
}