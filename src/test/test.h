#include <iostream>
#include <stdio.h>
#include "LinkList.h"
#include "StaticLinkList.h"
#include "DynamicArray.h"
#include "SmartPointer.h"
#include "SharedPointer.h"
#include "CircleList.h"
#include "DualLinkList.h"
#include "LinuxList.h"
#include "DualCircleList.h"
#include "StaticStack.h"
#include "LinkStack.h"
#include "StaticQueue.h"
#include "LinkQueue.h"
#include "LinuxLinkQueue.h"

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

void test30()
{
	DualLinkList<int> dl;

	for (int i = 0; i < 5; i++)
	{
		dl.insert(0, i);
		dl.insert(0, 5);
	}

	for (dl.move(0); !dl.end(); dl.next())
	{
		cout << dl.current() << endl;
	}

	cout << "begin" << endl;

	for (dl.move(dl.length() - 1); !dl.end(); dl.pre())
	{
		cout << dl.current() << endl;
	}

	cout << "end" << endl;

	dl.move(dl.length() - 1);

	while (!dl.end())
	{
		if (dl.current() == 5)
		{
			cout << dl.current() << endl;
			dl.remove(dl.find(dl.current()));
		}
		else
			dl.pre();
	}

	for (dl.move(0); !dl.end(); dl.next())
	{
		cout << dl.current() << endl;
	}
}

void test32_1()
{
	struct Node
	{
		struct list_head head;
		int value;
	};

	struct Node l = { 0 };

	INIT_LIST_HEAD(&l.head);
}

void test32_2()
{
	struct Node
	{
		struct list_head head;
		int value;
	};

	struct Node l = { 0 };
	struct list_head* list = (struct list_head*)&l;
	struct list_head* slider = nullptr;

	INIT_LIST_HEAD(&l.head);

	printf("Insert begin ...\n");

	for (int i = 0; i < 5; i++)
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n->value = i;

		list_add_tail((struct list_head*)n, list);
	}

	list_for_each(slider, list)
	{
		printf("%d\n", ((struct Node*)slider)->value);
	}

	printf("Insert end ...\n");

	printf("Delete begin ...\n");

	list_for_each(slider, list)
	{
		if (((struct Node*)slider)->value == 3)
		{
			list_del(slider);
			free(slider);
			break;
		}
	}

	list_for_each(slider, list)
	{
		printf("%d\n", ((struct Node*)slider)->value);
	}

	printf("Delete end ...\n");
}

void test32_3()
{
	struct Node
	{
		int value;
		struct list_head head;
	};

	struct Node l = { 0 };
	struct list_head* list = &l.head;
	struct list_head* slider = nullptr;

	INIT_LIST_HEAD(&l.head);

	printf("Insert begin ...\n");

	for (int i = 0; i < 5; i++)
	{
		struct Node* n = (struct Node*)malloc(sizeof(struct Node));
		n->value = i;

		list_add(&n->head, list);
	}

	list_for_each(slider, list)
	{
		printf("%d\n", list_entry(slider, struct Node, head)->value);
	}

	printf("Insert end ...\n");

	printf("Delete begin ...\n");

	list_for_each(slider, list)
	{
		struct Node* n = list_entry(slider, struct Node, head);

		if (n->value == 3)
		{
			list_del(slider);
			free(n);
			break;
		}
	}

	list_for_each(slider, list)
	{
		printf("%d\n", list_entry(slider, struct Node, head)->value);
	}

	printf("Delete end ...\n");
}

void test33_1()
{
	DualCircleList<int> dl;

	/*for (int i = 0; i < 5; i++)
	{
		dl.insert(0, i);
		dl.insert(0, 5);
	}*/

	for (int i = 0; i < 5; i++)
	{
		dl.insert(i);
		dl.insert(5);
	}

	//for (dl.move(0); !dl.end(); dl.next())
	//{
	//	cout << dl.current() << endl;
	//}

	cout << "begin" << endl;

	//for (dl.move(dl.length() - 1); !dl.end(); dl.pre())
	//{
	//	cout << dl.current() << endl;
	//}

	dl.move(dl.length() - 1);

	while (dl.find(5) != -1)
	{
		if (dl.current() == 5)
		{
			cout << dl.current() << endl;
			dl.remove(dl.find(dl.current()));
		}
		else
			dl.pre();
	}

	cout << "end" << endl;

	//for (int i = 0; i < dl.length(); i++)
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << dl.get(i) << endl;
	//}

	int i = 0;
	for (dl.move(dl.length() - 1); (i < dl.length()) && !dl.end(); dl.pre(), i++)
	{
		cout << dl.current() << endl;
	}
}

void test33_2()
{
	struct Node : public Object
	{
		list_head head;
		int value;
	};

	Node node;
	list_head* ld = &node.head;

	Node* pn1 = reinterpret_cast<Node*>(ld);
	Node* pn2 = list_entry(ld, Node, head);

	cout << "pn1 = " << pn1 << endl;
	cout << "pn2 = " << pn2 << endl;

}

void test34_1()
{
	StaticStack<int, 5> stack;

	try
	{
		stack.pop();
	}
	catch (const Exception& e)
	{
		cout << e.message() << endl;
		cout << e.location() << endl;
	}

	for (int i = 0; i < 5; i++)
		stack.push(i);

	while (stack.size() > 0)
	{
		cout << stack.top() << endl;
		stack.pop();
	}
		
}

void test35_1()
{
	auto is_left = [](char c)
	{
		return (c == '(') || (c == '{') || (c == '[') || (c == '<');
	};

	auto is_right = [](char c)
	{
		return (c == ')') || (c == '}') || (c == ']') || (c == '>');
	};

	auto is_quot = [](char c)
	{
		return (c == '\'') || (c == '\"');
	};

	auto is_match = [](char l, char r)
	{
		return ((l == '(') && (r == ')')) ||
			((l == '{') && (r == '}')) ||
			((l == '[') && (r == ']')) ||
			((l == '<') && (r == '>')) ||
			((l == '\'') && (r == '\'')) ||
			((l == '\"') && (r == '\"'));
	};

	auto scan = [is_left, is_right, is_match, is_quot](const char* code)
	{
		LinkStack<char> stack;
		int i = 0;
		bool ret = true;

		code = (code == nullptr) ? "" : code;

		while (ret && (code[i] != '\0'))
		{
			if (is_left(code[i]))
				stack.push(code[i]);
			else if (is_right(code[i]))
			{
				if ((stack.size() > 0) && is_match(stack.top(), code[i]))
					stack.pop();
				else
					ret = false;
			}
			else if (is_quot(code[i]))
			{
				if ((stack.size() == 0) || !is_match(stack.top(), code[i]))
					stack.push(code[i]);
				else if (is_match(stack.top(), code[i]))
					stack.pop();
			}
			i++;
		}

		return ret && (stack.size() == 0);
	};

	cout << scan("else if (is_quot(code[i])){if ((stack.size() == 0) || !is_match(stack.top(), code[i]))stack.push(code[i]);else if (is_match(stack.top(), code[i]))stack.pop();}") << endl;
}

void test36_1()
{
	StaticQueue<int, 5> queue;

	for (int i = 0; i < 5; i++)
		queue.add(i);

	while (queue.length() > 0)
	{
		cout << queue.front() << endl;
		queue.remove();

	}
}

void test37_1()
{
	LinkQueue<int> lq;

	for (int i = 0; i < 10; i++)
	{
		lq.add(i);
	}

	while (lq.length() > 0)
	{
		cout << lq.front() << endl;
		lq.remove();
	}
}

void test37_2()
{
	LinuxLinkQueue<int> lq;

	for (int i = 0; i < 10; i++)
	{
		lq.add(i);
	}

	while (lq.length() > 0)
	{
		cout << lq.front() << endl;
		lq.remove();
	}
}