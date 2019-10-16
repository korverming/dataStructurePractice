#ifndef StaticList_H
#define StaticList_H
#include "SeqList.h"

namespace DTLib
{
template <typename T, int N>
class StaticList : public SeqList<T>
{
protected:
	T m_space[N];

public:
	StaticList()
	{
		this->m_array = m_space;
		this->m_length = 0;
	}

	virtual int capacity() const
	{
		return N;
	}
};

}//end namespace DTLib

#endif
