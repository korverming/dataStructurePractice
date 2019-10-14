#include "Exception.h"
#include <cstring>
#include <cstdlib>//itoa,malloc
using namespace std;

void DTLib::Exception::init(const char* message, const char* file, int line)
{
	m_message = strdup(message);

	if (file != nullptr)
	{
		char sl[16] = { 0 };

		itoa(line, sl, 10);

		//2: ':' and '\0'
		m_location = static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));

		if (m_location != nullptr)
		{
			m_location = strcpy(m_location, file);
			m_location = strcat(m_location, ":");
			m_location = strcat(m_location, sl);
		}

	}
	else
	{
		m_location = nullptr;
	}
}

DTLib::Exception::Exception(const char* message)
{
	init(message, nullptr, 0);
}

DTLib::Exception::Exception(const char* file, int line)
{
	init(nullptr, file, line);
}

DTLib::Exception::Exception(const char* message, const char* file, int line)
{
	init(message, file, line);
}

DTLib::Exception::Exception(const Exception& e)
{
	m_message = strdup(e.m_message);
	m_location = strdup(e.m_location);
}

DTLib::Exception& DTLib::Exception::operator=(const Exception& e)
{
	if (this != &e)
	{
		free(m_message);
		free(m_location);

		m_message = strdup(e.m_message);
		m_location = strdup(e.m_location);
	}

	return *this;
}

const char* DTLib::Exception::message() const
{
	return m_message;
}

const char* DTLib::Exception::location() const
{
	return m_location;
}

//user defined destructor must be implemented
//even for pure virtual
DTLib::Exception::~Exception()
{
	free(m_message);
	free(m_location);
}