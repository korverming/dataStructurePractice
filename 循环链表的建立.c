#include <stdio.h>
#include <stdlib.h>

///ѭ������Ľ���
///���룺˳����ϣ�˳�����
///�����ѭ�������β��ַ
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
		//pָ������ʱ����Ŀռ�
		p = (LinkCircleListNode*)malloc(sizeof(LinkCircleListNode));
		p->data = arr[i];
		//q�ڴ���p�Ľڵ�
		q->pNext = p;
		//q�ƶ�����ǰ�Ľڵ�
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
	//��Ϊ������ʱ������ϣ�����������Ԫ�أ���������������p�ƶ�
	p = p->pNext;//��ʱpָ���һ��������Ԫ��
	while (p != pRear->pNext)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}

	getchar();
	return 0;
}
