//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#pragma once


namespace Core
{
namespace Math
{
	template<typename T>
	class CVector2
	{
	public:

		static const int s_MaxNumberOfElements = 2;

	public:

		typedef CVector2<T> CThis;

	public:

		CVector2();
		CVector2(T _Value);
		CVector2(T _Value0, T _Value1);
		CVector2(const CThis& _rCpy);

	public:

		inline CThis& operator = (CThis const& _rRight);

	public:

		inline T& operator [] (const int _Index);
		inline const T& operator [] (const int _Index) const;

	public:
		inline bool operator == (const CThis& _rRight) const;
        inline bool operator != (const CThis& _rRight) const;
        
        inline bool operator <  (const CThis& _rRight) const;
        inline bool operator <= (const CThis& _rRight) const;
        
        inline bool operator >  (const CThis& _rRight) const;
        inline bool operator >= (const CThis& _rRight) const;

	private:
		T m_V[s_MaxNumberOfElements];
	};
} // namespace Math
} // namespace Core


namespace Core
{
namespace Math
{
	template<typename T>
	CVector2<T>::CVector2()
	{
        m_V[0] = 0;
        m_V[1] = 0;
    }

	// -----------------------------------------------------------------------------

	template<typename T>
	CVector2<T>::CVector2(T _Value)
	{
		m_V[0] = _Value;
		m_V[1] = _Value;
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	CVector2<T>::CVector2(T _Value0, T _Value1)
	{
		m_V[0] = _Value0;
		m_V[1] = _Value1;
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	CVector2<T>::CVector2(const CThis& _rCpy)
	{
		m_V[0] = _rCpy[0];
		m_V[1] = _rCpy[1];
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	inline typename CVector2<T>::CThis& CVector2<T>::operator = (CThis const& _rRight)
	{
		m_V[0] = _rRight[0];
		m_V[1] = _rRight[1];

		return *this;
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	inline T& CVector2<T>::operator [] (const int _Index)
	{
		return m_V[_Index];
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	inline const T& CVector2<T>::operator [] (const int _Index) const
	{
		return m_V[_Index];
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	inline bool CVector2<T>::operator == (const CThis& _rRight) const
	{
		bool IsEqual;

		IsEqual = m_V[0] == _rRight.m_V[0] && m_V[1] == _rRight.m_V[1];

		return IsEqual;
	}
    
    // -----------------------------------------------------------------------------
    
	template<typename T>
	inline bool CVector2<T>::operator != (const CThis& _rRight) const
	{
		bool IsEqual;
        
		IsEqual = m_V[0] != _rRight.m_V[0] && m_V[1] != _rRight.m_V[1];
        
		return IsEqual;
	}
    
    // -----------------------------------------------------------------------------
    
    template<typename T>
    inline bool CVector2<T>::operator <  (const CThis& _rRight) const
    {
        bool IsSmaller;
        
        IsSmaller = m_V[0] < _rRight.m_V[0];
        
        return IsSmaller;
    }
    
    // -----------------------------------------------------------------------------
    
    template<typename T>
    inline bool CVector2<T>::operator <= (const CThis& _rRight) const
    {
        bool IsSmallerEqual;
        
        IsSmallerEqual = m_V[0] <= _rRight.m_V[0];
        
        return IsSmallerEqual;
    }
    
    // -----------------------------------------------------------------------------
    
    template<typename T>
    inline bool CVector2<T>::operator >  (const CThis& _rRight) const
    {
        bool IsGreater;
        
        IsGreater = m_V[0] > _rRight.m_V[0];
        
        return IsGreater;
    }
    
    // -----------------------------------------------------------------------------
    
    template<typename T>
    inline bool CVector2<T>::operator >= (const CThis& _rRight) const
    {
        bool IsGreaterEqual;
        
        IsGreaterEqual = m_V[0] >= _rRight.m_V[0];
        
        return IsGreaterEqual;
    }
} // namespace Math
} // namespace Core



namespace Core
{
namespace Math
{
	typedef CVector2<int>    Int2;
	typedef CVector2<float>  Float2;
	typedef CVector2<double> Double2;
} // namespace Math
} // namespace Core
