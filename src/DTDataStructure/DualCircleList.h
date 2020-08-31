#ifndef DualCircleList_H
#define DualCircleList_H

#include "LinuxList.h"
#include "DualLinkList.h"

namespace DTLib
{

template <typename T>
class DualCircleList : public DualLinkList<T>
{
protected:
	struct Node : public Object
	{
		list_head head;
		T value;
	};

	list_head m_header;
	list_head* m_current;

	list_head* position(int i) const
	{
		list_head* ret = const_cast<list_head*>(&m_header);

		for (int p = 0; p < i; p++)
			ret = ret->next;

		return ret;
	}

	int mod(int i) const
	{
		return (this->m_length == 0) ? 0 : (i % this->m_length);
	}

public:
	DualCircleList(): DualLinkList<T>()
	{
		this->m_length = 0;
		this->m_step = 1;

		m_current = nullptr;

		INIT_LIST_HEAD(&m_header);
	}

	virtual bool insert(const T& e) override
	{
		return insert(this->m_length, e);
	}

	virtual bool insert(int i, const T& e) override
	{
		bool ret = true;
		Node* node = new Node();

		i = i % (this->m_length + 1);

		if (node != nullptr)
		{
			node->value = e;

			list_add_tail(&node->head, position(i)->next);

			this->m_length++;
		}
		else
		{
			THROW_EXCEPTION
			(
				NoEnoughMemoryException,
				"No memory to insert new element ..."
			);
		}

		return ret;
	}

	virtual bool remove(int i) override
	{
		bool ret = true;

		i = mod(i);

		ret = ((0 <= i) && (i < this->m_length));

		if (ret)
		{
			list_head* toDel = position(i)->next;

			if (m_current == toDel)
				m_current = toDel->next;

			list_del(toDel);

			this->m_length--;

			delete list_entry(toDel, Node, head);
		}
		return ret;
	}

	virtual bool set(int i, const T& e) override
	{
		bool ret = true;

		i = mod(i);

		ret = ((0 <= i) && (i < this->m_length));

		if (ret)
			list_entry(position(i)->next, Node, head)->value = e;

		return ret;
	}

	virtual T get(int i) const
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

	virtual bool get(int i, T& e) const override
	{
		bool ret = true;

		i = mod(i);

		ret = ((0 <= i) && (i < this->m_length));

		if (ret)
			e = list_entry(position(i)->next, Node, head)->value;

		return ret;
	}

	virtual int find(const T& e) const override
	{
		int ret = -1;
		int i = 0;
		list_head* slider = nullptr;

		list_for_each(slider, &m_header)
		{
			if (list_entry(slider, Node, head)->value == e)
			{
				ret = i;
				break;
			}

			i++;
		}

		return ret;
	}

	/*virtual int length() const override
	{
		return m_length;
	}

	virtual void clear() override
	{
		while (m_length > 0)
		{
			remove(0);
		}
	}*/

	virtual bool move(int i, int step = 1) override
	{
		bool ret = (step > 0);

		i = mod(i);

		ret = ret && ((0 <= i) && (i < this->m_length));

		if (ret)
		{
			m_current = position(i)->next;
			this->m_step = step;
		}

		return ret;
	}

	virtual bool end() override
	{
		return (m_current == nullptr) || (this->m_length == 0);
	}

	virtual T current() override
	{
		if (!end())
			return list_entry(m_current, Node, head)->value;
		else
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No value at current position ..."
			);
	}

	virtual bool next() override
	{
		int i = 0;

		while ((i < this->m_step) && !end())
		{
			if (m_current != &m_header)
			{
				m_current = m_current->next;
				i++;
			}
			else
			{
				m_current = m_current->next;
			}
		}

		if (m_current == &m_header)
			m_current = m_current->next;

		return (i == this->m_step);
	}

	virtual bool pre() override
	{
		int i = 0;

		while ((i < this->m_step) && !end())
		{
			if (m_current != &m_header)
			{
				m_current = m_current->prev;
				i++;
			}
			else
			{
				m_current = m_current->prev;
			}
		}

		if (m_current == &m_header)
			m_current = m_current->prev;

		return (i == this->m_step);
	}

	~DualCircleList()
	{
		DualLinkList<T>::clear();
	}
};

}

#endif
