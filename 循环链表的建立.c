#include <stdio.h>
#include <stdlib.h>

///循环链表的建立
///输入：顺序表集合，顺序表长度
///输出：循环链表的尾地址
typedef struct node
{
	int data;
	struct node* pNext;
} LinkCircleListNode;

LinkCircleListNode* Create_Circle_LkList(int arr[], int length)
{
	LinkCircleListNode *head, *p, *q;
	int i;
	head = (LinkCircleListNode*)malloc(sizeof(LinkCircleListNode));
	q = head;

	for (i = 0; i < length; i++)
	{
		//p指向了临时申请的空间
		p = (LinkCircleListNode*)malloc(sizeof(LinkCircleListNode));
		p->data = arr[i];
		//q在串联p的节点
		q->pNext = p;
		//q移动到当前的节点
		q = p;
	}
	p->pNext = head;

	return p;
}
int main()
{
	int arr[] = {11, 22, 33, 44, 55};
	LinkCircleListNode* pRear = Create_Circle_LkList(arr, 5);
	LinkCircleListNode* p = pRear->pNext;
	//因为遍历的时候我们希望获得真正的元素，所以我们首先让p移动
	p = p->pNext;//此时p指向第一个真正的元素
	while (p != pRear->pNext)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}

	getchar();
	return 0;
}
