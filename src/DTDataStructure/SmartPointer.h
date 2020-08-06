#ifndef SmartPointer_H
#define SmartPointer_H
#include "Pointer.h"

namespace DTLib
{

/////////////////////////////////////
////unique_autoPtr
template <typename T>
class SmartPointer: public Pointer<T>
{
public:

	SmartPointer(T* p = nullptr): Pointer<T>(p)
	{
	}

	SmartPointer(const SmartPointer<T>& obj)
	{
		this->m_pointer = obj.m_pointer;
		const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
	}

	SmartPointer<T>& operator=(const SmartPointer<T>& obj)
	{
		if (this != &obj)
		{
			T* p = this->m_pointer;

			this->m_pointer = obj.m_pointer;

			const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;

			delete p;
		}

		return *this;
	}

	~SmartPointer()
	{
		delete this->m_pointer;
	}
};

}//end namespace DTLib
#endif
