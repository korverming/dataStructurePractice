#ifndef Sort_H
#define Sort_H

#include "Object.h"
#include "Array.h"

namespace DTLib
{

class Sort : public Object
{
private:
	Sort();
	Sort(const Sort& obj);
	Sort& operator=(const Sort&);

	template <typename T>
	static bool less(T v, T w)
	{
		return v < w;
	}

	template <typename T>
	static void Swap(T& a, T& b)
	{
		T c(a);
		a = b;
		b = c;
	}

	template <typename T>
	static void Swap(T array[], int i, int j)
	{
		T t(array[i]);
		array[i] = array[j];
		array[j] = t;
	}

	template <typename T>
	static int Partition(T array[], int begin, int end)
	{
		T v = array[begin];
		int i = begin;
		int j = end + 1;

		while (true)
		{
			while (less(array[++i], v))
			{
				if (i == end)
					break;
			}

			while (less(v, array[--j]))
			{
				if (j == begin)
					break;
			}

			if (i >= j)
				break;

			Swap(array, i, j);
		}

		Swap(array, begin, j);

		return j;
	}

	template <typename T>
	static void QuickSort(T array[], int begin, int end)
	{
		if (begin >= end)
			return;

		int j = Partition(array, begin, end);
		QuickSort(array, begin, j - 1);
		QuickSort(array, j + 1, end);
	}

public:

	template<typename T>
	static void QuickSort(T array[], int len)
	{
		QuickSort(array, 0, len - 1);
	}

	template <typename T>
	static void QuickSort(Array<T>& array)
	{
		QuickSort(array.array(), array.length());
	}
};

}
#endif