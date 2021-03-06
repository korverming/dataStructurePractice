#ifndef StaticLinkList_H
#define StaticLinkList_H

#include "LinkList.h"

namespace DTLib
{

template <typename T, int N>
class StaticLinkList : public LinkList<T>
{
protected:
	typedef typename LinkList<T>::Node Node;
	struct SNode : public Node
	{
		void* operator new(size_t size, void* loc)
		{
			return loc;
		}
	};
	unsigned char m_space[sizeof(SNode) * N];
	int m_used[N];

	Node* create() override
	{
		SNode* ret = nullptr;
		for (int i = 0; i < N; i++)
		{
			if (!m_used[i])
			{
				ret = reinterpret_cast<SNode*>(m_space) + i;
				ret = new(ret)SNode();
				m_used[i] = 1;
				break;
			}
		}
		return ret;
	}

	void destroy(Node* pn) override
	{
		SNode* space = reinterpret_cast<SNode*>(m_space);
		SNode* psn = dynamic_cast<SNode*>(pn);
		
		for (int i = 0; i < N; i++)
		{
			if (psn == (space + i))
			{
				m_used[i] = 0;
				psn->~SNode();
				break;
			}
		}
	}

public:
	StaticLinkList()
	{
		for (int i = 0; i < N; i++)
			m_used[i] = 0;
	}

	int capacity()
	{
		return N;
	}

	~StaticLinkList()
	{
		LinkList<T>::clear();
	}
};

}//

#endif
