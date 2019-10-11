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

DTLib::Object::~Object()
{
}
