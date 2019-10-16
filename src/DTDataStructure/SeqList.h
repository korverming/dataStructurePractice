#ifndef SeqList_H
#define SeqList_H
#include "List.h"
#include "Exception.h"

namespace DTLib
{
template <typename T>
class SeqList : public List<T>
{
protected:
	T* m_array;
	int m_length;
public:
	virtual bool insert(int i, const T& e)
	{
		bool ret = (0 <= i) && (i <= m_length);
		ret = ret && (m_length < capacity());

		if (ret)
		{
			for (int p = m_length - 1; p >= i; p--)
				m_array[p + 1] = m_array[p];

			m_array[i] = e;
			m_length++;
		}

		return ret;
	}

	virtual bool remove(int i)
	{
		bool ret = (0 <= i) && (i < m_length);

		if (ret)
		{
			for (int p = i; p < m_length - 1; p++)
				m_array[p] = m_array[p + 1];

			m_length--;
		}

		return ret;
	}

	virtual bool set(int i, const T& e)
	{
		bool ret = (0 <= i) && (i < m_length);

		if (ret)
			m_array[i] = e;

		return ret;
	}

	virtual bool get(int i, T& e) const
	{
		bool ret = (0 <= i) && (i < m_length);

		if (ret)
			e = m_array[i];

		return ret;
	}

	virtual int length() const
	{
		return m_length;
	}

	virtual void clear()
	{
		m_length = 0;
	}

	T& operator[](int i)
	{
		if ((0 <= i) && (i < m_length))
			return m_array[i];
		else
			THROW_EXCEPTION
			(
				IndexOutOfBoundsException,
				"Parameter i is invalid ..."
			);
	}

	T operator[](int i) const
	{
		return (const_cast<SeqList<T>&>(*this))[i];
	}

	virtual int capacity() const = 0;
};

}//end namespace DTLib

#endif
