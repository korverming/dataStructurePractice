#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* pNext;
} LinkJoeNode;
//���ǽ���Լɪ�򻷵�ѭ������
//����ͷ�ڵ㣺��Ҫģ��Լɪ�򻷵Ĺ�������
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
	//��λ��1��ʼ����ʼ30���ˣ�ʣ��15����
	int s = 1;
	int m = 9;//ÿ��9�ͳ�Ȧ
	int k = 15;//������Ȧ��Ҫ��15����

	int arr[30];
	//�����ʼ������
	for (int i = 0; i < 30; i++)
	{
		arr[i] = i + 1;//��Ϊ����Ϊÿһ�������������Ϊi+1
	}
	LinkJoeNode* p, *q;
	LinkJoeNode* rear = CreateLkList(arr, 30);
	p = rear;//p�Ǳ���ָ�룬ֻҪ��Ϸ���У���ô���p��Ҫ�ƶ�

	while (k > 0)
	{
		//step1:ֻҪ����û�дﵽ15���ˣ���ô��Ҫ�ҳ���m-1����
		//��Ϊ���ĺ���Ǽ���Ҫ��Ȧ��
		for (int j = 0; j < m - 1; j++)
		{
			p = p->pNext;
		}
		//��ʱ��pͣ����m-1��
		q = p->pNext;//qָ���˵�m��Ԫ��
		printf("��%d��Ԫ�س�Ȧ\n", q->data);
		//��m-1��m+1����,��ʱqָ��ĵ�m��Ԫ����Ȼ�������ڴ�ռ��У�
		//ֻ���߼��ϲ��ٴ��ں�mԪ�����������ϵ
		p->pNext = q->pNext;
		//Ϊ�˷�ֹ�ڴ�й©
		free(q);
		k--;
	}
	getchar();
	return 0;
}