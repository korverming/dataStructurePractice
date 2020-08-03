#include <iostream>
#include "LinkList.h"
#include "StaticLinkList.h"

using namespace DTLib;
using namespace std;

void test22()
{
	DTLib::LinkList<int> list;

	for (int i = 0; i < 5; i++)
	{
		//list.insert(i);
		list.insert(0, i);
		list.set(0, i * i);
	}
		

	for (int i = 0; i < list.length(); i++)
	{
		//int v = 0;
		//list.get(i, v);

		//std::cout << v << std::endl;

		cout << list.get(i) << endl;
	}

	//list.remove(2);
	list.clear();

	for (int i = 0; i < list.length(); i++)
	{
		cout << list.get(i) << endl;
	}

	//class Test
	//{
	//public:
	//	Test()
	//	{
	//		throw 0;
	//	}
	//};

	//LinkList<Test> list2;
}

void test23()
{
	class Test:
		public Object
	{
		int i;
	public:
		Test(int v = 0)
		{
			i = v;
		}

		bool operator==(const Test& t)
		{
			return (i == t.i);
		}
	};
	Test t1(1);
	Test t2(2);
	Test t3(3);
	LinkList<Test> list;

	list.insert(t1);
	list.insert(t2);
	list.insert(t3);

	cout << list.find(t2) << endl;

	//LinkList<int> list;

	//for (int i = 0; i < 5; i++)
	//	list.insert(0, i);

	//cout << list.find(-3) << endl;
}

void test24()
{
	LinkList<int> list;

	for (int i = 0; i < 5; i++)
		list.insert(0, i);

	for (list.move(0); !list.end(); list.next())
		cout << list.current() << endl;

	for (list.move(0, 2); !list.end(); list.next())
		cout << list.current() << endl;

	for (list.move(0, 3); !list.end(); list.next())
		cout << list.current() << endl;

	for (list.move(0, 10); !list.end(); list.next())
		cout << list.current() << endl;
}

void test25()
{
	while (1)
	{
		StaticLinkList<int, 5> list;

		for (int i = 0; i < 5; i++)
			list.insert(0, i);
	}

	
	/*for (list.move(0); !list.end(); list.next())
		cout << list.current() << endl;
	
	try
	{
		list.insert(6);
	}
	catch (const Exception& e)
	{
		cout << e.message() << endl;
	}*/
}
