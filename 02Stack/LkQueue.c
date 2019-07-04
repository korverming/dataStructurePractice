#include <stdio.h>
#include <stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0
typedef int datatype;

typedef struct node
{
	datatype data;
	struct node* next;
} LinkListNode;

typedef struct
{
	LinkListNode* front, *rear;
} LinkQueue;

void Init_LkQueue(LinkQueue* lq)
{
	lq->front = (LinkListNode*)malloc(sizeof(LinkListNode));
	lq->front->next = NULL;
	lq->rear = lq->front;
}

BOOL IsEmpty_LkQueue(LinkQueue* lq)
{
	if (lq->front == lq->rear)
		return TRUE;
	else
		return FALSE;
}

BOOL GetLkQueue(LinkQueue* lq, datatype *x)
{
	if (IsEmpty_LkQueue(lq))
		return FALSE;

	x = &(lq->front->next->data);//��Ϊfrontʼ��ָ��ͷ�ڵ㣬���������Ƚ��ȳ���front��nextһ���Ƕ�ͷԪ��
	return TRUE;
}

void Insert_LkQueue(LinkQueue* lq, datatype x)
{
	lq->rear->next = (LinkListNode*)malloc(sizeof(LinkListNode));
	//�½ڵ����β
	lq->rear = lq->rear->next;
	lq->rear->data = x;
	lq->rear->next = NULL;
}

LinkListNode* Del_LkQueue(LinkQueue* lq)
{
	LinkListNode* s;
	if (!IsEmpty_LkQueue(lq))
	{
		s = lq->front->next;
		if (s->next == NULL)//����ֻ��һ���ڵ�
			lq->rear = lq->front;//�����ÿ�
		else
			lq->front->next = s->next;//��Ϊlq�������Լ���Ƽ�¼λ�õ�ָ�룬����Ҫ��ָ����һ����ͷԪ��

		return s;
	}

	return NULL;
}

void Destroy_LkQueue(LinkQueue* lq)
{
	//��ʹ�����˶��У�ҲҪ����ס�ṹ
	LinkListNode* s;
	while (!IsEmpty_LkQueue(lq))
	{
		s = Del_LkQueue(lq);
		free(s);
	}
	free(lq->front);//�ͷ�ͷ�ڵ�
	lq->front = NULL;
	lq->rear = NULL;
}

int main(void)
{
	LinkQueue node;
	LinkQueue *lpPtr = &node;
	LinkListNode* sPtr;
	datatype value;
	Init_LkQueue(lpPtr);
	//0,1,1,0���
	Insert_LkQueue(lpPtr, 0);
	Insert_LkQueue(lpPtr, 1);
	Insert_LkQueue(lpPtr, 1);
	Insert_LkQueue(lpPtr, 0);
	int N = 42;

	for (int i = 0; i < 42; i++)
	{
		//��ͷԪ�س���
		sPtr = Del_LkQueue(lpPtr);
		if (sPtr != NULL)
		{
			//��ͷ������Ԫ�أ�n-1��n�����µ�ϵ��
			value = sPtr->data + lpPtr->front->next->data;
			if (sPtr->data != 0)
			{
				printf("%d ", sPtr->data);
			}
			Insert_LkQueue(lpPtr, value);
		}

		if (lpPtr->front->next->data == 0)
		{
			//��ͷԪ����Ϊ�ָ���
			Insert_LkQueue(lpPtr, 0);
			printf("\n");
		}
	}

	Destroy_LkQueue(lpPtr);

	getchar();
	return 0;
}