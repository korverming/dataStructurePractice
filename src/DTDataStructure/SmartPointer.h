#ifndef SmartPointer_H_
#define SmartPointer_H_


namespace DTLib
{

/////////////////////////////////////
////unique_autoPtr
template <typename T>
class SmartPointer
{
protected:
	T* m_pointer;

public:

	SmartPointer(T* p = nullptr)
	{
		m_pointer = p;
	}

	SmartPointer(const SmartPointer<T>& obj)
	{
		m_pointer = obj.m_pointer;
		const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
	}

	SmartPointer<T>& operator=(const SmartPointer<T>& obj)
	{
		if (this != &obj)
		{
			delete m_pointer;

			m_pointer = obj.m_pointer;
			const_cast<SmartPointer<T>&>(obj).m_pointer = nullptr;
		}

		return *this;
	}

	T* operator->()
	{
		return m_pointer;
	}

	T& operator*()
	{
		return *m_pointer;
	}

	bool isNull()
	{
		return m_pointer == nullptr;
	}

	T* get()
	{
		return m_pointer;
	}

	~SmartPointer()
	{
		delete m_pointer;
	}
};

}//end namespace DTLib
#endif
