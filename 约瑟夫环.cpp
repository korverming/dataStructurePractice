#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* pNext;
} LinkJoeNode;
//考虑建立约瑟夫环的循环链表
//不带头节点：需要模拟约瑟夫环的工作过程
LinkJoeNode* CreateLkList(int arr[], int length)
{
	LinkJoeNode* head, *p, *q;
	int i;
	head = (LinkJoeNode*)malloc(sizeof(LinkJoeNode));
	head->data = arr[0];
	q = head;

	for (i = 1; i < length; i++)
	{
		p = (LinkJoeNode*)malloc(sizeof(LinkJoeNode));
		p->data = arr[i];
		q->pNext = p;
		q = p;
	}

	p->pNext = head;

	return p;
}


int main12(void)
{
	//从位置1开始，初始30个人，剩余15个人
	int s = 1;
	int m = 9;//每逢9就出圈
	int k = 15;//表明出圈者要有15个人

	int arr[30];
	//构造初始的序列
	for (int i = 0; i < 30; i++)
	{
		arr[i] = i + 1;//因为我们为每一个变量的序号设为i+1
	}
	LinkJoeNode* p, *q;
	LinkJoeNode* rear = CreateLkList(arr, 30);
	p = rear;//p是遍历指针，只要游戏运行，那么这个p就要移动

	while (k > 0)
	{
		//step1:只要人数没有达到15个人，那么就要找出第m-1个，
		//因为它的后继是即将要出圈的
		for (int j = 0; j < m - 1; j++)
		{
			p = p->pNext;
		}
		//此时，p停在了m-1处
		q = p->pNext;//q指向了第m个元素
		printf("第%d个元素出圈\n", q->data);
		//让m-1和m+1相连,此时q指向的第m个元素依然存在在内存空间中，
		//只是逻辑上不再存在和m元素相关联的联系
		p->pNext = q->pNext;
		//为了防止内存泄漏
		free(q);
		k--;
	}
	getchar();
	return 0;
}