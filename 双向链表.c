#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
	int data;
	struct DNode* prior, *next;
} DLinkListNode;

DLinkListNode* Delete_DL(DLinkListNode* ptr)
{
	ptr->prior->next = ptr->next;
	ptr->next->prior = ptr->prior;//���߼��ϣ�������Ҳ�޷��ҵ����ptr

	return ptr;
}

void Insert_Before_DL(DLinkListNode* p, int x)
{
	DLinkListNode* s;
	s = (DLinkListNode*)malloc(sizeof(DLinkListNode));
	s->data = x;
	//��s�Ĺ�ϵ���뵽������
	s->prior = p->prior;
	if (p->prior != NULL)
		p->prior->next = s;
	s->next = p;
	p->prior = s;
}

int main(void)
{
	DLinkListNode x;
	DLinkListNode* head;
	DLinkListNode* ptr;
	ptr = &x;

	ptr->data = 3;
	ptr->prior = NULL;
	ptr->next = NULL;

	Insert_Before_DL(ptr, 1);
	Insert_Before_DL(ptr, 2);
	DLinkListNode* p, *q;
	p = &x;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		if (p->prior == NULL)
			q = p;//q��¼�˵�һ���ڵ�
		p = p->prior;
		//�ŵ�������
		//if (p->prior == NULL)
		//	q = p;//q��¼�˵�һ���ڵ�
	}

	while (q != NULL)
	{
		printf("%d\n", q->data);
		q = q->next;
	}
	getchar();
	return 0;
}