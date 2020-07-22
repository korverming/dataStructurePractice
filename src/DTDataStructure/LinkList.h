#ifndef LinkList_H
#define LinkList_H

#include "List.h"
#include "Exception.h"

namespace DTLib
{
template <typename T>
class LinkList : public List<T>
{
protected:
	struct Node : public Object
	{
		T value;
		Node* next;
	};

	mutable Node m_header;
	int m_length;
public:
	LinkList()
	{
		m_header.next = nullptr;
		m_length = 0;
	}

	virtual bool insert(const T& e)
	{
		return insert(m_length, e);
	}

	virtual bool insert(int i, const T& e)
	{
		bool ret = ((0 <= i) && (i <= m_length));

		if (ret)
		{
			Node* node = new Node();

			if (node != NULL)
			{
				Node* current = &m_header;

				for (int p = 0; p < i; p++)
					current = current->next;

				node->value = e;
				node->next = current->next;
				current->next = node;

				m_length++;
			}
			else
			{
				THROW_EXCEPTION
				(
					NoEnoughMemoryException,
					"No memory to insert new element ..."
				);
			}
		}

		return ret;
	}

	virtual bool remove(int i)
	{
		bool ret = ((0 <= i) && (i < m_length));

		if (ret)
		{
			Node* current = &m_header;

			for (int p = 0; p < i; p++)
				current = current->next;

			Node* toDel = current->next;

			current->next = toDel->next;

			delete toDel;

			m_length--;
		}

		return ret;
	}
	virtual bool set(int i, const T& e)
	{
		bool ret = ((0 <= i) && (i < m_length));

		if (ret)
		{
			Node* current = &m_header;

			for (int p = 0; p < i; p++)
				current = current->next;

			current->next->value = e;
		}

		return ret;
	}

	T get(int i) const
	{
		T ret;

		if (get(i, ret))
			return ret;
		else
			THROW_EXCEPTION
			(
				IndexOutOfBoundsException,
				"Invalid parameter i to get element ..."
			);

		return ret;
	}

	virtual bool get(int i, T& e) const
	{
		bool ret = ((0 <= i) && (i < m_length));

		if (ret)
		{
			Node* current = &m_header;

			for (int p = 0; p < i; p++)
				current = current->next;

			e = current->next->value;
		}

		return ret;
	}

	virtual int length() const
	{
		return m_length;
	}

	virtual void clear()
	{
		while (m_header.next)
		{
			Node* toDel = m_header.next;

			m_header.next = toDel->next;

			delete toDel;
		}

		m_length = 0;
	}

	~LinkList()
	{
		clear();
	}
};

}
#endif
