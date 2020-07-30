#include "Object.h"
#include <cstdlib>

void* DTLib::Object::operator new(size_t size) throw()
{
	return malloc(size);
}

void DTLib::Object::operator delete(void* p)
{
	free(p);
}

void* DTLib::Object::operator new[](size_t size) throw()
{
	return malloc(size);
}

void DTLib::Object::operator delete[](void* p) throw()
{
	free(p);
}

bool DTLib::Object::operator==(const Object& obj)
{
	return (this == &obj);
}

bool DTLib::Object::operator!=(const Object& obj)
{
	return (this != &obj);
}

DTLib::Object::~Object()
{
}
