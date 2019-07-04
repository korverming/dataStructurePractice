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

	x = &(lq->front->next->data);//因为front始终指向头节点，而队列是先进先出，front的next一定是队头元素
	return TRUE;
}

void Insert_LkQueue(LinkQueue* lq, datatype x)
{
	lq->rear->next = (LinkListNode*)malloc(sizeof(LinkListNode));
	//新节点入队尾
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
		if (s->next == NULL)//队中只有一个节点
			lq->rear = lq->front;//队列置空
		else
			lq->front->next = s->next;//因为lq是我们自己设计记录位置的指针，所以要让指向下一个队头元素

		return s;
	}

	return NULL;
}

void Destroy_LkQueue(LinkQueue* lq)
{
	//即使销毁了队列，也要保持住结构
	LinkListNode* s;
	while (!IsEmpty_LkQueue(lq))
	{
		s = Del_LkQueue(lq);
		free(s);
	}
	free(lq->front);//释放头节点
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
	//0,1,1,0入队
	Insert_LkQueue(lpPtr, 0);
	Insert_LkQueue(lpPtr, 1);
	Insert_LkQueue(lpPtr, 1);
	Insert_LkQueue(lpPtr, 0);
	int N = 42;

	for (int i = 0; i < 42; i++)
	{
		//队头元素出队
		sPtr = Del_LkQueue(lpPtr);
		if (sPtr != NULL)
		{
			//队头的两个元素，n-1，n生成新的系数
			value = sPtr->data + lpPtr->front->next->data;
			if (sPtr->data != 0)
			{
				printf("%d ", sPtr->data);
			}
			Insert_LkQueue(lpPtr, value);
		}

		if (lpPtr->front->next->data == 0)
		{
			//队头元素作为分隔符
			Insert_LkQueue(lpPtr, 0);
			printf("\n");
		}
	}

	Destroy_LkQueue(lpPtr);

	getchar();
	return 0;
}