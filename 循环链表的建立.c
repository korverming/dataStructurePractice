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

//遍历输出
void ShowCircleLkList(LinkCircleListNode* pRear)
{
	LinkCircleListNode* p = pRear->pNext;
	//因为遍历的时候我们希望获得真正的元素，所以我们首先让p移动
	p = p->pNext;//此时p指向第一个真正的元素
	while (p != pRear->pNext)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}
}

//两个循环链表的合并
//输入为链表a的尾指针，链表b的尾指针
LinkCircleListNode* Connect_Circle_LkList(LinkCircleListNode* ra, LinkCircleListNode* rb)
{
	LinkCircleListNode* p;
	//记录a的头节点
	p = ra->pNext;
	//讲b的第一个元素节点链入a的尾部
	ra->pNext = rb->pNext->pNext;
	free(rb->pNext);//回收空间，意味着b链表的头节点空间不可达，但是rb->pNext依然是有值的
	rb->pNext = p;
	//假定rb是0x20空间，在0x20空间下有一个next分量，这个分量是可以存储地址值
	//free(rb)才是使得rb->pNext不可用
	//free(rb->pNext),rb->pNext中的（data和pnext）分量不可用
	//rb->pNext始终指向的是原b链表中的头节点
	//所以57行执行完毕后，将b链表的尾指针指向了a链表的头节点

	return rb;
}

int main()
{
	//int arr[] = {11, 22, 33, 44, 55};
	//LinkCircleListNode* pRear = Create_Circle_LkList(arr, 5);
	//ShowCircleLkList(pRear);

	//测试合并
	int a[] = { 1, 3, 5 };
	int b[] = { 2, 4, 6 };
	LinkCircleListNode* ra, *rb;
	ra = Create_Circle_LkList(a, 3);
	rb = Create_Circle_LkList(b, 3);
	LinkCircleListNode* pRear = Connect_Circle_LkList(ra, rb);
	ShowCircleLkList(pRear);
	getchar();
	return 0;
}
