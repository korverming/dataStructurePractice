#include <iostream>
#include "SmartPointer.h"
#include "Exception.h"

using namespace std;
using namespace DTLib;

int main()
{
	SmartPointer<int>* sp = new SmartPointer<int>();
	delete sp;

	InvalidOperationException* e = new InvalidOperationException();
	delete e;

	return 0;
}