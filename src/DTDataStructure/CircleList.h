#ifndef CircleList_H
#define CircleList_H

#include "LinkList.h"

namespace DTLib
{
template <typename T>
class CircleList : public LinkList<T>
{
protected:
	typedef typename LinkList<T>::Node Node;

	int mod(int i) const
	{
		return (this->m_length == 0) ? 0 : (i % this->m_length);
	}

	Node* last() const
	{
		return this->position(this->m_length - 1)->next;
	}
	void last_to_first() const
	{
		last()->next = this->m_header.next;
	}

public:
	virtual bool insert(const T& e) override
	{
		return insert(this->m_length, e);
	}

	virtual bool insert(int i, const T& e) override
	{
		bool ret = true;

		i = i % (this->m_length + 1);

		ret = LinkList<T>::insert(i, e);

		if (ret && (i == 0))
		{
			last_to_first();
		}

		return ret;
	}

	virtual bool remove(int i) override
	{
		bool ret = true;

		i = mod(i);

		if (i == 0)
		{
			Node* toDel = this->m_header.next;

			if (toDel != nullptr)
			{
				this->m_header.next = toDel->next;
				this->m_length--;

				if (this->m_length > 0)
				{
					last_to_first();
					if (this->m_current == toDel)
						this->m_current = toDel->next;
				}
				else
				{
					this->m_header.next = nullptr;
					this->m_current = nullptr;
				}

				this->destroy(toDel
);
			}
			else
				return false;
		}
		else
		{
			ret = LinkList<T>::remove(i);
		}

		return ret;
	}

	virtual bool set(int i, const T& e) override
	{
		return LinkList<T>::set(mod(i), e);
	}

	virtual T get(int i) const override
	{
		return LinkList<T>::get(mod(i));
	}

	virtual bool get(int i, T& e) const override
	{
		return LinkList<T>::get(mod(i), e);
	}

	virtual int find(const T& e) const override
	{
		int ret = -1;

		Node* slider = this->m_header.next;

		for (int i = 0; i < this->m_length; i++)
		{
			if (slider->value == e)
			{
				ret = i;
				break;
			}
			slider = slider->next;
		}

		return ret;
	}

	virtual void clear() override
	{
		while (this->m_length > 1)
			remove(1);

		if (this->m_length == 1)
		{
			Node* toDel = this->m_header.next;

			this->m_header.next = nullptr;
			this->m_length = 0;
			this->m_current = nullptr;

			this->destroy(toDel);
		}
	}

	virtual bool move(int i, int step) override
	{
		return LinkList<T>::move(mod(i), step);
	}

	virtual bool end() override
	{
		return (this->m_length == 0) || (this->m_current == nullptr);
	}

	~CircleList()
	{
		clear();
	}

};

}
#endif
