#ifndef StaticQueue_H
#define StaticQueue_H

#include "Queue.h"
#include "Exception.h"

namespace DTLib
{

template <typename T, int N>
class StaticQueue : public Queue<T>
{
protected:
	T m_space[N];
	int m_front;
	int m_rear;
	int m_length;

public:
	StaticQueue()
	{
		m_front = 0;
		m_rear = 0;
		m_length = 0;
	}

	int capacity() const
	{
		return N;
	}

	virtual void add(const T& e) override
	{
		if (m_length < N)
		{
			m_space[m_rear] = e;
			m_rear = (m_rear + 1) % N;
			m_length++;
		}
		else
		{
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No space in current queue ..."
			);
		}	
	}

	virtual void remove() override
	{
		if (m_length > 0)
		{
			m_front = (m_front + 1) % N;
			m_length--;
		}
		else
		{
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No element in current queue ..."
			);
		}
	}

	virtual T front() const override
	{
		if (m_length > 0)
			return m_space[m_front];
		else
		{
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No element in current queue ..."
			);
		}
	}

	virtual void clear() override
	{
		m_front = 0;
		m_rear = 0;
		m_length = 0;
	}

	virtual int length() const
	{
		return m_length;
	}
};
}
#endif