
#pragma once


namespace Core
{
namespace Math
{
namespace Base
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

		inline CThis& operator = (CThis& _rRight);

	public:

		inline T& operator [] (int _Index);
		inline const T& operator [] (int _Index) const;
		
	public:
		inline bool operator == (const CThis& _rRight) const;

	private:
		T m_V[s_MaxNumberOfElements];
	};
} // namespace Base
} // namespace Math
} // namespace Core


namespace Core
{
namespace Math
{
namespace Base
{
	template<typename T>
	CVector2<T>::CVector2()
		: m_V[0](0)
		, m_V[1](0)
	{}

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
	inline typename CVector2<T>::CThis& CVector2<T>::operator = (CThis& _rRight)
	{
		m_V[0] = _rRight[0];
		m_V[1] = _rRight[1];

		return this;
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	inline T& CVector2<T>::operator [] (int _Index)
	{
		return m_V[_Index];
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	inline const T& CVector2<T>::operator [] (int _Index) const
	{
		return m_V[_Index];
	}

	// -----------------------------------------------------------------------------

	template<typename T>
	inline bool CVector2<T>::operator == (const CThis& _rRight) const
	{
		bool IsEqual;

		IsEqual = m_V[0] == _rRight[0] && m_V[1] == _rRight[1];

		return IsEqual;
	}
} // namespace Base
} // namespace Math
} // namespace Core



namespace Core
{
	typedef Math::Base::CVector2<int>    Int2;
	typedef Math::Base::CVector2<float>  Float2;
	typedef Math::Base::CVector2<double> Double2;
} // namespace Core
