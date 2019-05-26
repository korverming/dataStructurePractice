#include "LinkList.h"
#include <malloc.h>
/*
1）	初始化：给线性表中的相关参数赋值
2）	求长度：求线性表中的元素的个数
3）	取元素：取给定位置的元素值
4）	查元素：查找给定元素值的位置
5）	插入元素：在指定的位置插入给定的值
6）	删除：删除指定位置的值或者是删除给定的值。
7）	遍历元素：从头到尾扫描线性表。
*/

//创建带有头节点的链表Init
LinkListNode* InitLinkList()
{
	LinkListNode* pHead = NULL;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (pHead)
	{
		pHead->pNext = NULL;
	}

	return pHead;
}

//求长度：求线性表中的元素的个数
int GetSizeLinkList(LinkListNode* pHead)
{
	int n = 0;
	while (pHead->pNext)
	{
		n++;
		pHead = pHead->pNext;
	}

	return n;
}

//取元素：取给定位置的元素值
//输入链表的头指针，要查找的编号，输出第i个元素的地址
//pHead:头指针  i:待查节点的序号
LinkListNode* GetLinkListNode(LinkListNode* pHead, int pos)
{
	int j;
	LinkListNode* p;
	p = pHead;
	j = 0;
	if (pos == 0)//?????
		return NULL;

	while (j < pos && p->pNext != NULL)
	{
		j++;
		p = p->pNext;
	}

	if (pos == j)
		return p;
	else
		return NULL;
}

//查元素：查找给定元素值的位置
//找到就返回节点的地址，找不到就返回NULL
LinkListNode* locateLinkList(LinkListNode* pHead, int objData)
{
	LinkListNode* p;
	p = pHead->pNext;
	while (p != NULL &&p->data != objData)
	{
		p = p->pNext;
	}

	return p;
}

//插入元素：在指定的位置插入给定的值
//因为链表这种结构的内存是由程序员管理的，
//因此它的建立由一定的运算方法
//尾插法建立单链表（将逻辑上的顺序表放入单链表的物理结构中）
//arr:传入的顺序表   length:顺序表的长度
LinkListNode* Create_Rear_LkList(ElemType arr[], int length)
{
	LinkListNode* pHead, *p = NULL, *q;
	int i;//循环变量，用来遍历全部的顺序表

	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));

	q = pHead;//q获得了当前链表的头节点
	//q保存了pHead，同时通过q不断前移使得链表串联起来
	for (i = 0; i < length; i++)
	{
		//获得一个单链表的节点，将这个节点
		//加入到有pHead指向的这个链表中
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		//p获得一个可以加入链表的节点单元
		p->data = arr[i];//将顺序表的内容存入单链表的节点

		q->pNext = p;
		q = p;
	}

	p->pNext = NULL;

	return pHead;
}

//头插法建立单链表
LinkListNode* Create_Front1_LkList(ElemType arr[], int length)
{
	LinkListNode* pHead, *p, *q;
	int i;

	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = NULL;
	q = pHead->pNext;

	//头插时必须逆序遍历顺序表
	for (i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = q;//使得新加入的节点串入了上一个节点
		//q = p;
		pHead->pNext = p;//头节点指向了当前的新加入节点
		q = pHead->pNext;//让q指向当前的节点
	}

	return pHead;
}

//头插法2
LinkListNode* Create_Front2_LkList(ElemType arr[], int length)
{
	LinkListNode* pHead, *p, *q;
	int i;
	q = NULL;
	for (i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = q;
		q = p;
	}

	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = q;

	return pHead;
}

//头插法3
LinkListNode* Create_Front3_LkList(ElemType arr[], int length)
{
	LinkListNode* pHead, *p;
	int i;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = NULL;
	for (i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}
	//之所以我们的方法3可以节省方法1中的一个变量q
	//原因是pHead不发生变化，而pHead中的pNext始终作为当前节点的指针

	return pHead;
}
/*
顺序表：12，33，44，76，89，90（逻辑上的顺序表）==>单链表
本例中我们用数组表示这种顺序表
*/

//插入元素：在指定的位置插入给定的值
//在指定位置之后插入
void Insert_After_LkList(LinkListNode* ptr, ElemType x)
{
	LinkListNode* s;
	s = (LinkListNode*)malloc(sizeof(LinkListNode));
	s->data = x;
	s->pNext = ptr->pNext;
	ptr->pNext = s;
}

//指定位置之前插入
void Insert_Before_LkList(LinkListNode* pHead, LinkListNode* ptr, ElemType x)
{
	LinkListNode* s, *qPtr;
	s = (LinkListNode*)malloc(sizeof(LinkListNode));
	s->data = x;
	qPtr = pHead;//qPtr用来代替pHead的移动
	while (qPtr->pNext != ptr)
	{
		qPtr = qPtr->pNext;
	}

	s->pNext = ptr;
	qPtr->pNext = s;
	//因为链表是单向的，虽然我知道当前节点是ptr
	//但是在语法层面上，我如果想知道ptr的前继节点只能从head遍历而来
	//查到了当前节点的前继才能使用后插的方法完成节点的加入
}

//删除：删除指定位置的值或者是删除给定的值
//情形1：删除指定节点的后继节点
//情形2：删除第i个节点，假定头节点i=0
//删除返回目标节点的地址，并不涉及到动态空间的回收
//在动态回收空间的要求中，应该遵循的原理是谁污染谁治理
//在顺序表中的删除就是逻辑上的删除，就是说我们的这个节点不再
//存在于当前的顺序表中了
///删除节点：Ptr是需要删除的节点，将删除ptr的后续节点
LinkListNode* Delete_After_LkList(LinkListNode* ptr)
{
	LinkListNode* fptr;
	//假定顺序表A->B->C,删除A的后续节点B，A->C
	fptr = ptr->pNext;//ptr是A，所以ptr的next是B，所以fptr是B
	ptr->pNext = fptr->pNext;//ptr是A，fptr是B，所以fptr的next是C，所以ptr->next就变成了C

	return fptr;
}

///删除第i个节点
LinkListNode* Delete_i_LkList(LinkListNode* pHead, int i)
{
	LinkListNode* ptr, *qPtr = NULL;
	ptr = GetLinkListNode(pHead, i - 1);//找到i的前继节点

	if (ptr != NULL && ptr->pNext != NULL)
	{
		qPtr = Delete_After_LkList(ptr);
	}

	return qPtr;
}

//遍历
void ShowLkList(LinkListNode* pHead)
{
	LinkListNode* p = pHead->pNext;
	while (p != NULL)
	{
		printf(" %d", p->data);
		p = p->pNext;
	}
}

//test push
int main(void)
{
	ElemType MySeq[] = {1, 2, 3, 4, 5};
	LinkListNode* pHead = Create_Rear_LkList(MySeq, 5);
	printf("\n**************显示当前单链表中的全部元素***************\n");
	ShowLkList(pHead);
	LinkListNode* pPos = GetLinkListNode(pHead, 2);
	Insert_After_LkList(pPos, 999);
	printf("\n**************显示当前单链表中的全部元素**********\n");
	ShowLkList(pHead);
	Insert_Before_LkList(pHead, pPos, 666);
	printf("\n**************显示当前单链表中的全部元素**********\n");
	ShowLkList(pHead);
	//Delete_After_LkList(pPos);
	Delete_i_LkList(pHead, 2);
	printf("\n**************显示当前单链表中的全部元素**********\n");
	ShowLkList(pHead);
	printf("\nList Size: %d", GetSizeLinkList(pHead));
	//Create_Front1_LkList(MySeq, 5);
	//Create_Front2_LkList(MySeq, 5);
	getchar();
	return 0;
}

