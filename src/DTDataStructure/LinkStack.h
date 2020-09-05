#ifndef LinkStack_H
#define LinkStack_H

#include "Stack.h"
#include "LinkList.h"

namespace DTLib
{

template <typename T>
class LinkStack : public Stack<T>
{
protected:
	LinkList<T> m_list;
public:
	virtual void push(const T& e) override
	{
		m_list.insert(0, e);
	}

	virtual void pop() override
	{
		if (m_list.length() > 0)
			m_list.remove(0);
		else
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No element in current stack ..."
			);
	}

	virtual T top() const override
	{
		if (m_list.length() > 0)
			return m_list.get(0);
		else
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No element in current stack ..."
			);
	}

	virtual void clear() override
	{
		m_list.clear();
	}

	virtual int size() const override
	{
		return m_list.length();
	}
};

}

#endif