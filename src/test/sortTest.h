#include "Sort.h"
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
