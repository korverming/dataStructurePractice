#ifndef Object_H
#define Object_H

namespace DTLib
{

class Object
{
public:
	void* operator new(size_t size) throw();
	void operator delete(void* p);
	void* operator new[](size_t size) throw();
	void operator delete[](void* p);
	bool operator==(const Object& obj);
	bool operator!=(const Object& obj);
	virtual ~Object() = 0;
};

}//end namespace DTLib


#endif

