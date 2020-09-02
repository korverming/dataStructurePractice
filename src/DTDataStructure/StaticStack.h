#ifndef StaticStack_H
#define StaticStack_H

#include "Stack.h"
#include "Exception.h"

namespace DTLib
{

template <typename T, int N>
class StaticStack : public Stack<T>
{
protected:
	T m_space[N];
	int m_top;
	int m_size;
public:
	StaticStack()
	{
		m_top = -1;
		m_size = 0;
	}

	int capacity() const
	{
		return N;
	}

	virtual void push(const T& e) override
	{
		if (m_size < N)
		{
			m_space[m_top + 1] = e;
			m_top++;
			m_size++;
		}
		else
		{
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No space in current stack ..."
			);
		}
	}

	virtual void pop() override
	{
		if (m_size > 0)
		{
			m_top--;
			m_size--;
		}
		else
		{
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No element in current stack ..."
			);
		}
	}

	virtual T top() const override
	{
		if (m_size > 0)
		{
			return m_space[m_top];
		}
		else
		{
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No element in current stack ..."
			);
		}
	}

	virtual void clear() override
	{
		m_top = -1;
		m_size = 0;
	}

	virtual int size() const override
	{
		return m_size;
	}
};

}
#endif
