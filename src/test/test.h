#include <iostream>
#include <stdio.h>
#include <functional>
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
#include "Tree.h"
#include "GTree.h"
#include "BTree.h"

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

void test51_1()
{
	Tree<int>* t;
	TreeNode<int>* tn;
}

void test53_1()
{
	GTree<char> t;
	GTreeNode<char>* node = nullptr;

	t.insert('A', nullptr);

	node = t.find('A');
	t.insert('B', node);
	t.insert('C', node);
	t.insert('D', node);

	node = t.find('B');
	t.insert('E', node);
	t.insert('F', node);

	node = t.find('E');
	t.insert('K', node);
	t.insert('L', node);

	node = t.find('C');
	t.insert('G', node);

	node = t.find('D');
	t.insert('H', node);
	t.insert('I', node);
	t.insert('J', node);

	node = t.find('H');
	t.insert('M', node);

	const char* s = "KLFGMIJ";

	for (int i = 0; i < 7; i++)
	{
		TreeNode<char>* node = t.find(s[i]);

		while (node != nullptr)
		{
			cout << node->value << " ";

			node = node->parent;
		}

		cout << endl;
	}
}

void test55_1()
{
	GTree<char> t;
	GTreeNode<char>* node = nullptr;
	GTreeNode<char> root;

	root.value = 'A';
	root.parent = nullptr;

	t.insert(&root);

	node = t.find('A');
	t.insert('B', node);
	t.insert('C', node);
	t.insert('D', node);

	node = t.find('B');
	t.insert('E', node);
	t.insert('F', node);

	node = t.find('E');
	t.insert('K', node);
	t.insert('L', node);

	node = t.find('C');
	t.insert('G', node);

	node = t.find('D');
	t.insert('H', node);
	t.insert('I', node);
	t.insert('J', node);

	node = t.find('H');
	t.insert('M', node);

	t.clear();

	const char* s = "KLFGMIJ";

	for (int i = 0; i < 7; i++)
	{
		TreeNode<char>* node = t.find(s[i]);

		while (node != nullptr)
		{
			cout << node->value << " ";

			node = node->parent;
		}

		cout << endl;
	}
}

void test56_1()
{
	GTree<char> t;
	GTreeNode<char>* node = nullptr;
	GTreeNode<char> root;

	root.value = 'A';
	root.parent = nullptr;

	t.insert(&root);

	node = t.find('A');
	t.insert('B', node);
	t.insert('C', node);
	t.insert('D', node);

	node = t.find('B');
	t.insert('E', node);
	t.insert('F', node);

	node = t.find('E');
	t.insert('K', node);
	t.insert('L', node);

	node = t.find('C');
	t.insert('G', node);

	node = t.find('D');
	t.insert('H', node);
	t.insert('I', node);
	t.insert('J', node);

	node = t.find('H');
	t.insert('M', node);

	//t.remove('D');
	SharedPointer<Tree<char>> p = t.remove(t.find('D'));

	const char* s = "KLFGMIJ";

	for (int i = 0; i < 7; i++)
	{
		TreeNode<char>* node = t.find(s[i]);

		while (node != nullptr)
		{
			cout << node->value << " ";

			node = node->parent;
		}

		cout << endl;
	}

	cout << "the removed D sub tree:" << endl;
	for (int i = 0; i < 7; i++)
	{
		TreeNode<char>* node = p->find(s[i]);

		while (node != nullptr)
		{
			cout << node->value << " ";

			node = node->parent;
		}

		cout << endl;
	}
}

void test57_1()
{
	GTree<char> t;
	GTreeNode<char>* node = nullptr;
	GTreeNode<char> root;

	root.value = 'A';
	root.parent = nullptr;

	t.insert(&root);

	node = t.find('A');
	t.insert('B', node);
	t.insert('C', node);
	t.insert('D', node);

	node = t.find('B');
	t.insert('E', node);
	t.insert('F', node);

	node = t.find('E');
	t.insert('K', node);
	t.insert('L', node);

	node = t.find('C');
	t.insert('G', node);

	node = t.find('D');
	t.insert('H', node);
	t.insert('I', node);
	t.insert('J', node);

	node = t.find('H');
	t.insert('M', node);

	cout << t.count() << endl;
	cout << t.height() << endl;
	cout << t.degree() << endl;
}

void test58_1()
{
	GTree<char> t;
	GTreeNode<char>* node = nullptr;
	GTreeNode<char> root;

	root.value = 'A';
	root.parent = nullptr;

	t.insert(&root);

	node = t.find('A');
	t.insert('B', node);
	t.insert('C', node);
	t.insert('D', node);

	node = t.find('B');
	t.insert('E', node);
	t.insert('F', node);

	node = t.find('E');
	t.insert('K', node);
	t.insert('L', node);

	node = t.find('C');
	t.insert('G', node);

	node = t.find('D');
	t.insert('H', node);
	t.insert('I', node);
	t.insert('J', node);

	node = t.find('H');
	t.insert('M', node);

	cout << t.count() << endl;
	cout << t.height() << endl;
	cout << t.degree() << endl;

	for (t.begin(); !t.end(); t.next())
		cout << t.current() << endl;
}

void test61_1()
{
	GTree<char> t;
	GTreeNode<char>* node = nullptr;
	GTreeNode<char> root;

	root.value = 'A';
	root.parent = nullptr;

	t.insert(&root);

	node = t.find('A');
	t.insert('B', node);
	t.insert('C', node);
	t.insert('D', node);

	node = t.find('B');
	t.insert('E', node);
	t.insert('F', node);

	node = t.find('E');
	t.insert('K', node);
	t.insert('L', node);

	node = t.find('C');
	t.insert('G', node);

	node = t.find('D');
	t.insert('H', node);
	t.insert('I', node);
	t.insert('J', node);

	node = t.find('H');
	t.insert('M', node);

	cout << t.count() << endl;
	cout << t.height() << endl;
	cout << t.degree() << endl;

	for (t.begin(); !t.end(); t.next())
		cout << t.current() << endl;

	BTree<int> bt;
	BTreeNode<int> btn;
}

void test62_1()
{
	BTree<int> bt;
	BTreeNode<int> btn;

	bt.find(1);
	bt.find(&btn);

}

void test63_1()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	n = bt.find(6);
	bt.insert(11, n, LEFT);

	int a[] = { 8, 9, 10, 11, 7 };

	for (int i = 0; i < 5; i++)
	{
		TreeNode<int>* node = bt.find(a[i]);

		while (node)
		{
			cout << node->value << " ";
			node = node->parent;
		}

		cout << endl;
	}
}

void test64_1()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	n = bt.find(6);
	bt.insert(11, n, LEFT);

	int a[] = { 8, 9, 10, 11, 7 };

	SharedPointer<Tree<int>> sp = bt.remove(3);

	for (int i = 0; i < 5; i++)
	{
		TreeNode<int>* node = bt.find(a[i]);

		while (node)
		{
			cout << node->value << " ";
			node = node->parent;
		}

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		TreeNode<int>* node = sp->find(a[i]);

		while (node)
		{
			cout << node->value << " ";
			node = node->parent;
		}

		cout << endl;
	}

}

void test65_1()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	cout << bt.count() << endl;
	cout << bt.height() << endl;
	cout << bt.degree() << endl;
}

void test66_1()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	cout << bt.count() << endl;
	cout << bt.height() << endl;
	cout << bt.degree() << endl;

	cout << endl;

	for (bt.begin(); !bt.end(); bt.next())
		cout << bt.current() << " ";

	cout << endl;
}

void test67()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	cout << bt.count() << endl;
	cout << bt.height() << endl;
	cout << bt.degree() << endl;

	cout << endl;

	for (bt.begin(); !bt.end(); bt.next())
		cout << bt.current() << " ";

	cout << endl;

	SharedPointer<Array<int>> sp = nullptr;

	//sp = bt.traversal(PreOrder);
	//sp = bt.traversal(InOrder);
	sp = bt.traversal(PostOrder);

	for (int i = 0; i < (*sp).length(); i++)
		cout << (*sp)[i] << " ";

	cout << endl;
}

void test68_1()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	cout << bt.count() << endl;
	cout << bt.height() << endl;
	cout << bt.degree() << endl;

	SharedPointer<BTree<int>> btClone = bt.clone();

	int a[] = { 8, 9, 10, 7 };

	cout << "Clone: " << endl;
	for (int i = 0; i < 5; i++)
	{
		TreeNode<int>* node = btClone->find(a[i]);

		while (node)
		{
			cout << node->value << " ";
			node = node->parent;
		}

		cout << endl;
	}

	cout << endl;

	cout << "Old BTree: " << endl;
	for (int i = 0; i < 5; i++)
	{
		TreeNode<int>* node = bt.find(a[i]);

		while (node)
		{
			cout << node->value << " ";
			node = node->parent;
		}

		cout << endl;
	}

}

void test68_2()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	cout << bt.count() << endl;
	cout << bt.height() << endl;
	cout << bt.degree() << endl;

	SharedPointer<BTree<int>> btClone = bt.clone();

	int a[] = { 8, 9, 10, 7 };

	cout << "Clone: " << endl;
	for (int i = 0; i < 5; i++)
	{
		TreeNode<int>* node = btClone->find(a[i]);

		while (node)
		{
			cout << node->value << " ";
			node = node->parent;
		}

		cout << endl;
	}

	cout << endl;

	cout << "Old BTree: " << endl;
	for (int i = 0; i < 5; i++)
	{
		TreeNode<int>* node = bt.find(a[i]);

		while (node)
		{
			cout << node->value << " ";
			node = node->parent;
		}

		cout << endl;
	}

	cout << endl;

	cout << "bt == *btClone: " << (bt == *btClone) << endl;

}

void test68_3()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	cout << bt.count() << endl;
	cout << bt.height() << endl;
	cout << bt.degree() << endl;

	SharedPointer<BTree<int>> btClone = bt.clone();

	cout << "bt == *btClone: " << (bt == *btClone) << endl;

	BTree<int> nbt;

	nbt.insert(0, nullptr);

	n = nbt.find(0);
	nbt.insert(6, n);
	nbt.insert(2, n);

	n = nbt.find(2);
	nbt.insert(7, n);
	nbt.insert(8, n);

	SharedPointer<BTree<int>> r = bt.add(nbt);

	int a[] = { 8, 9, 10, 13, 5 };

	cout << "Add result: " << endl;
	for (int i = 0; i < 5; i++)
	{
		TreeNode<int>* node = r->find(a[i]);

		while (node)
		{
			cout << node->value << " ";
			node = node->parent;
		}

		cout << endl;
	}

	cout << endl;

	SharedPointer<Array<int>> tr = r->traversal(PreOrder);

	for (int i = 0; i < tr->length(); i++)
		cout << (*tr)[i] << " ";

	cout << endl;

}

void test69_1()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	cout << bt.count() << endl;
	cout << bt.height() << endl;
	cout << bt.degree() << endl;

	SharedPointer<Array<int>> tr = bt.traversal(LevelOrder);

	for (int i = 0; i < tr->length(); i++)
		cout << (*tr)[i] << " ";

	cout << endl;

}

void test69_2()
{
	BTree<int> bt;
	BTreeNode<int>* n = nullptr;

	bt.insert(1, nullptr);

	n = bt.find(1);
	bt.insert(2, n);
	bt.insert(3, n);

	n = bt.find(2);
	bt.insert(4, n);
	bt.insert(5, n);

	n = bt.find(4);
	bt.insert(8, n);
	bt.insert(9, n);

	n = bt.find(5);
	bt.insert(10, n);

	n = bt.find(3);
	bt.insert(6, n);
	bt.insert(7, n);

	cout << bt.count() << endl;
	cout << bt.height() << endl;
	cout << bt.degree() << endl;

	SharedPointer<Array<int>> tr = bt.traversal(LevelOrder);

	for (int i = 0; i < tr->length(); i++)
		cout << (*tr)[i] << " ";

	cout << endl;

	BTreeNode<int>* head = bt.thread(LevelOrder);

	//while (head != nullptr)
	//{
	//	cout << head->value << " ";
	//	head = head->right;
	//}


	while (head->right != nullptr)
	{
		head = head->right;
	}

	while (head != nullptr)
	{
		cout << head->value << " ";
		head = head->left;
	}

	cout << endl;
}

void test70_1()
{
	auto createTree = []()
	{
		static BTreeNode<int> ns[9];

		for (int i = 0; i < 9; i++)
		{
			ns[i].value = i;
			ns[i].parent = nullptr;
			ns[i].left = nullptr;
			ns[i].right = nullptr;
		}

		ns[0].left = &ns[1];
		ns[0].right = &ns[2];
		ns[1].parent = &ns[0];
		ns[2].parent = &ns[0];

		ns[1].left = &ns[3];
		ns[1].right = nullptr;
		ns[3].parent = &ns[1];

		ns[2].left = &ns[4];
		ns[2].right = &ns[5];
		ns[4].parent = &ns[2];
		ns[5].parent = &ns[2];

		ns[3].left = nullptr;
		ns[3].right = &ns[6];
		ns[6].parent = &ns[3];

		ns[4].left = &ns[7];
		ns[4].right = nullptr;
		ns[7].parent = &ns[4];

		ns[5].left = &ns[8];
		ns[5].right = nullptr;
		ns[8].parent = &ns[5];

		return ns;
	};

	function<void(BTreeNode<int>*)> printInOrder = 
	[&](BTreeNode<int>* node)
	{
		if (node != nullptr)
		{
			printInOrder(node->left);

			cout << node->value << " ";

			printInOrder(node->right);
		}
	};

	BTreeNode<int>* ns = createTree();

	printInOrder(ns);

	cout << endl;

	ns = delOdd1(ns);

	printInOrder(ns);

	cout << endl;

	int a[] = {6, 7, 8};

	for (int i = 0; i < 3; i++)
	{
		TreeNode<int>* n = ns + a[i];

		while (n != nullptr)
		{
			cout << n->value << " ";

			n = n->parent;
		}

		cout << endl;
	}

	cout << endl;

}
