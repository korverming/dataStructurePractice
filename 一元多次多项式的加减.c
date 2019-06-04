#include <stdio.h>
#include <stdlib.h>

//设计数据项的数据结构
typedef struct Polynode
{
	int coef;//系数
	int exp;//指数
	//Polynode* pNext;
	struct Polynode* pNext;
} LinkPolyNode;

//面临算法抽象：补充说明：所有的存储结构按照幂指数升序
///将PolyA和PolyB进行相加，将结果放入PolyC中
///函数的输入是PolyA和PolyB的首地址
///函数返回的是PolyC的首地址

//我们需要新增节点功能，因为有可能在原链表中不存在
///新多项式元素的地址
///coef:系数 exp：幂指数 pc：新节点要插入的位置
///返回值：新分配的节点地址
LinkPolyNode* attach(int coef, int exp, LinkPolyNode* pc)
{
	LinkPolyNode* p;
	p = (LinkPolyNode*)malloc(sizeof(LinkPolyNode));
	p->coef = coef;
	p->exp = exp;
	pc->pNext = p;

	return p;
}

///将PolyA和PolyB进行相加，将结果放入PolyC中
///函数的输入是PolyA和PolyB的首地址
///函数返回的是PolyC的首地址
LinkPolyNode* MergePoly(LinkPolyNode* headA, LinkPolyNode* headB)
{
	LinkPolyNode* headC;//需要返回的多项式C的地址
	LinkPolyNode *pa, *pb, *pc, *p;

	int x;
	pa = headA->pNext;
	pb = headB->pNext;
	headC = (LinkPolyNode*)malloc(sizeof(LinkPolyNode));
	pc = headC;//此时将pc作为C多项式的头节点

	while (pa && pb)
	{
		if (pa->exp == pb->exp)
		{
			x = pa->coef + pb->coef;
			if (x != 0)
			{
				pc = attach(x, pa->exp, pc);
			}

			pa = pa->pNext;
			pb = pb->pNext;
			continue;
		}

		if (pa->exp < pb->exp)
		{
			p = pa;
			pa = pa->pNext;
		}
		else
		{
			p = pb;
			pb = pb->pNext;
		}

		pc = attach(p->coef, p->exp, pc);
	}

	p = pa;

	if (pa == NULL)
		p = pb;

	while (p)
	{
		pc = attach(p->coef, p->exp, pc);
		p = p->pNext;
	}
	pc->pNext = NULL;

	return headC;
}

//假定多项式的最低项是常数项,假定所有的元素都是关于x的多项式
//polyA: 1 + 2x + 3x^2
//polyB: 1 + 3x + x^4

//设计显示的辅助函数
void ShowList(LinkPolyNode* pHead)
{
	LinkPolyNode* p;
	p = pHead->pNext;
	while (p != NULL)
	{
		//美化设计显示的内容：设计常数项的显示
		if (p->exp == 0)
		{
			printf("%d", p->coef);
			p = p->pNext;
			continue;
		}
			
		
		//设计一次项的显示
		if (p->exp == 1)
		{
			if (p->coef > 0)
			{
				printf("+%dx", p->coef);
			}
			else
			{
				printf("%dx", p->coef);
			}
			p = p->pNext;
			continue;
		}

		//设计高次项的显示
		if (p->coef > 0)
		{
			printf("+%dx^%d", p->coef, p->exp);
		}
		else
		{
			printf("%dx ^%d", p->coef, p->exp);
		}

		p = p->pNext;
	}
}
//程序是调出来的，不是一蹴而就的，只有掌握了原理才能完成
int main(void)
{
	//polyA: 1 + 2x + 3x^2
	//polyB: 3x + x^4
	LinkPolyNode HeadA, A1, A2, A3;
	LinkPolyNode HeadB, B1, B2, B3;

	HeadA.pNext = &A1;
	A1.pNext = &A2;
	A2.pNext = &A3;
	A3.pNext = NULL;

	HeadB.pNext = &B1;
	B1.pNext = &B2;
	B2.pNext = NULL;

	//建立多项式polyA: 1 + 2x + 3x^2
	A1.coef = 1;
	A1.exp = 0;
	A2.coef = 2;
	A2.exp = 1;
	A3.coef = 3;
	A3.exp = 2;

	//建立多项式polyB: 3x + x^4
	B1.coef = 3;
	B1.exp = 1;
	B2.coef = 1;
	B2.exp = 4;

	printf("\n**********************polyA******************\n");
	ShowList(&HeadA);

	printf("\n**********************polyB******************\n");
	ShowList(&HeadB);

	LinkPolyNode* pPolyC;
	pPolyC = MergePoly(&HeadA, &HeadB);
	printf("\n**********************polyC******************\n");
	ShowList(pPolyC);

	getchar();
	return 0;
}

int main8(void)
{
	//polyA: 1 + 2x + 3x^2
	//polyB: 1 + 3x + x^4
	LinkPolyNode HeadA, A1, A2, A3;
	LinkPolyNode HeadB, B1, B2, B3;

	HeadA.pNext = &A1;
	A1.pNext = &A2;
	A2.pNext = &A3;
	A3.pNext = NULL;

	HeadB.pNext = &B1;
	B1.pNext = &B2;
	B2.pNext = &B3;
	B3.pNext = NULL;

	//建立多项式polyA: 1 + 2x + 3x^2
	A1.coef = 1;
	A1.exp = 0;
	A2.coef = 2;
	A2.exp = 1;
	A3.coef = 3;
	A3.exp = 2;

	//建立多项式polyB: 1 + 3x + x^4
	B1.coef = 1;
	B1.exp = 0;
	B2.coef = 3;
	B2.exp = 1;
	B3.coef = 1;
	B3.exp = 4;

	printf("\n**********************polyA******************\n");
	ShowList(&HeadA);

	printf("\n**********************polyB******************\n");
	ShowList(&HeadB);

	LinkPolyNode* pPolyC;
	pPolyC = MergePoly(&HeadA, &HeadB);
	printf("\n**********************polyC******************\n");
	ShowList(pPolyC);

	getchar();
	return 0;
}
