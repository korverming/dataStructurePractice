#include <iostream>
#include "Exception.h"

using namespace std;
using namespace DTLib;

int main(int argc, char* argv)
{
	try
	{
		//remove pure virtual destructor ~Exception() temporarily
		//throw Exception("test", __FILE__, __LINE__);
		//THROW_EXCEPTION(Exception, "test");
		THROW_EXCEPTION(ArithmeticException, "test");
	}
	catch (const Exception& e)
	{
		cout << "catch(const Exception& e)" << endl;
		cout << e.message() << endl;
		cout << e.location() << endl;
	}
	catch (const ArithmeticException& e)//deriative exception class must before base class
	{
		cout << "catch(const ArithmeticException& e)" << endl;
		cout << e.message() << endl;
		cout << e.location() << endl;
	}
	return 0;
}