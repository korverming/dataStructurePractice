#include "Sort.h"
#include "StaticArray.h"
#include <iostream>
using namespace DTLib;
using namespace std;

void quickSortTest1()
{
	char array[] =
	{
		'Q', 'U', 'I', 'C',
		'K', 'S', 'O', 'R',
		'T', 'E', 'X', 'A',
		'M', 'P', 'L', 'E'
	};

	Sort::QuickSort(array, 16);

	for (int i = 0; i < 16; i++)
		cout << array[i] << endl;
}

void quickSortTest2()
{
	StaticArray<double, 5> sa;

	for (int i = 0; i < 5; i++)
	{
		sa[i] = 5 - i;
	}

	Sort::QuickSort(sa);

	for (int i = 0; i < sa.length(); i++)
		cout << sa[i] << endl;
}
