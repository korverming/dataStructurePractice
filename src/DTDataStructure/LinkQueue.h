#ifndef LinkQueue_H
#define LinkQueue_H

#include "Queue.h"
#include "LinkList.h"
#include "Exception.h"

namespace DTLib
{

	template <typename T>
	class LinkQueue : public Queue<T>
	{
	protected:
		LinkList<T> m_list;

	public:
		LinkQueue()
		{}

		virtual void add(const T& e) override
		{
			m_list.insert(e);
		}

		virtual void remove() override
		{
			if (m_list.length() > 0)
			{
				m_list.remove(0);
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
			if (m_list.length() > 0)
				return m_list.get(0);
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
			m_list.clear();
		}

		virtual int length() const
		{
			return m_list.length();
		}
	};
}

#endif
