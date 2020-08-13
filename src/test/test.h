#include <iostream>
#include "LinkList.h"
#include "StaticLinkList.h"
#include "DynamicArray.h"
#include "SmartPointer.h"
#include "SharedPointer.h"
#include "CircleList.h"

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

void test26_1()
{
	try
	{
		NullPointerException npe;

		cout << "throw" << endl;

		throw npe;
	}
	catch (const Exception& e)
	{
		cout << "catch" << endl;
	}
}

void test26_2()
{
	class Test : public Object
	{
		int m_id;
	public:
		Test(int id = 0)
		{
			m_id = id;
		}
		~Test()
		{
			if (m_id == 1)
				throw m_id;
		}
	};

	LinkList<Test> list;
	Test t0(0), t1(1), t2(2);

	try
	{
		list.insert(t0);
		list.insert(t1);
		list.insert(t2);

		list.remove(1);
	}
	catch (int e)
	{
		cout << e << endl;
		cout << list.length() << endl;
	}
}

void test26_3()
{
	LinkList<int> list;

	for (int i = 0; i < 5; i++)
		list.insert(i);

	for (list.move(0); !list.end(); list.next())
	{
		if (list.current() == 3)
		{
			list.remove(list.find(list.current()));

			cout << list.current() << endl;
		}
	}
		
}

void test26_4()
{
	StaticLinkList<int, 10> list;

	for (int i = 0; i < 5; i++)
		list.insert(i);

	list.remove(3);

	for (int i = 0; i < list.length(); i++)
		cout << list.get(i) << endl;
}

void test26_5()
{
	DynamicArray<DynamicArray<int>> d;

	d.resize(3);

	for (int i = 0; i < d.length(); i++)
	{
		d[i].resize(i + 1);
	}

	for (int i = 0; i < d.length(); i++)
	{
		for (int j = 0; j < d[i].length(); j++)
		{
			d[i][j] = i + j;
		}
	}

	for (int i = 0; i < d.length(); i++)
	{
		for (int j = 0; j < d[i].length(); j++)
		{
			cout << d[i][j] << " ";
		}

		cout << endl;
	}
}

void test27()
{
	class Test : public Object
	{
	public:
		Test()
		{
			cout << "Test()" << endl;
		}

		~Test()
		{
			cout << "~Test()" << endl;
		}
	};

	SmartPointer<Test> sp = new Test();
	SmartPointer<Test> spn;
	spn = sp;
}

void test28()
{
	class Test : public Object
	{
	public:
		int value;
		Test(): value(0)
		{
			cout << "Test()" << endl;
		}

		~Test()
		{
			cout << "~Test()" << endl;
		}
	};

	SharedPointer<Test> sp0 = new Test();
	SharedPointer<Test> sp1 = sp0;
	SharedPointer<Test> sp2 = nullptr;

	sp2 = sp1;

	sp2->value = 100;

	cout << sp0->value << endl;
	cout << sp1->value << endl;
	cout << sp2->value << endl;

	sp2.clear();

	cout << (sp0 == sp2) << endl;

	/*const SharedPointer<Test> sp3 = new Test();
	sp3->value = 100;*/
}

void test29()
{
	int n = 41;
	int s = 1;
	int m = 3;

	CircleList<int> cl;

	for (int i = 1; i <= n; i++)
	{
		cl.insert(i);
	}

	cl.move(s - 1, m - 1);

	while (cl.length() > 0)
	{
		cl.next();
		cout << cl.current() << endl;
		cl.remove(cl.find(cl.current()));
	}
}