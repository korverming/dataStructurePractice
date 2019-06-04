#include <stdio.h>
#include <stdlib.h>

//�������������ݽṹ
typedef struct Polynode
{
	int coef;//ϵ��
	int exp;//ָ��
	//Polynode* pNext;
	struct Polynode* pNext;
} LinkPolyNode;

//�����㷨���󣺲���˵�������еĴ洢�ṹ������ָ������
///��PolyA��PolyB������ӣ����������PolyC��
///������������PolyA��PolyB���׵�ַ
///�������ص���PolyC���׵�ַ

//������Ҫ�����ڵ㹦�ܣ���Ϊ�п�����ԭ�����в�����
///�¶���ʽԪ�صĵ�ַ
///coef:ϵ�� exp����ָ�� pc���½ڵ�Ҫ�����λ��
///����ֵ���·���Ľڵ��ַ
LinkPolyNode* attach(int coef, int exp, LinkPolyNode* pc)
{
	LinkPolyNode* p;
	p = (LinkPolyNode*)malloc(sizeof(LinkPolyNode));
	p->coef = coef;
	p->exp = exp;
	pc->pNext = p;

	return p;
}

///��PolyA��PolyB������ӣ����������PolyC��
///������������PolyA��PolyB���׵�ַ
///�������ص���PolyC���׵�ַ
LinkPolyNode* MergePoly(LinkPolyNode* headA, LinkPolyNode* headB)
{
	LinkPolyNode* headC;//��Ҫ���صĶ���ʽC�ĵ�ַ
	LinkPolyNode *pa, *pb, *pc, *p;

	int x;
	pa = headA->pNext;
	pb = headB->pNext;
	headC = (LinkPolyNode*)malloc(sizeof(LinkPolyNode));
	pc = headC;//��ʱ��pc��ΪC����ʽ��ͷ�ڵ�

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

//�ٶ�����ʽ��������ǳ�����,�ٶ����е�Ԫ�ض��ǹ���x�Ķ���ʽ
//polyA: 1 + 2x + 3x^2
//polyB: 1 + 3x + x^4

//�����ʾ�ĸ�������
void ShowList(LinkPolyNode* pHead)
{
	LinkPolyNode* p;
	p = pHead->pNext;
	while (p != NULL)
	{
		//���������ʾ�����ݣ���Ƴ��������ʾ
		if (p->exp == 0)
		{
			printf("%d", p->coef);
			p = p->pNext;
			continue;
		}
			
		
		//���һ�������ʾ
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

		//��Ƹߴ������ʾ
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
//�����ǵ������ģ�����һ����͵ģ�ֻ��������ԭ��������
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

	//��������ʽpolyA: 1 + 2x + 3x^2
	A1.coef = 1;
	A1.exp = 0;
	A2.coef = 2;
	A2.exp = 1;
	A3.coef = 3;
	A3.exp = 2;

	//��������ʽpolyB: 3x + x^4
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

	//��������ʽpolyA: 1 + 2x + 3x^2
	A1.coef = 1;
	A1.exp = 0;
	A2.coef = 2;
	A2.exp = 1;
	A3.coef = 3;
	A3.exp = 2;

	//��������ʽpolyB: 1 + 3x + x^4
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
