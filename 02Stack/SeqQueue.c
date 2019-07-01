#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100
typedef int datatype;

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef struct queue
{
	datatype data[QUEUE_SIZE];
	int front, rear;
} SeqQueue;

void Init_SqQueue(SeqQueue* sq)
{
	//�ӿ�ʱfront=rear
	sq->front = QUEUE_SIZE - 1;
	sq->rear = QUEUE_SIZE - 1;
}

BOOL IsEmpty_SqQueue(SeqQueue* sq)
{
	if (sq->rear == sq->front)
		return TRUE;

	return FALSE;
}

//���ص�Ӧ��������ĽǱ�
int Get_SqQueue(SeqQueue* sq)
{
	if (!IsEmpty_SqQueue(sq))
	{
		return (sq->front + 1) % QUEUE_SIZE;
	}

	return -1;
}

BOOL EnSqQueue(SeqQueue* sq, datatype x)
{
	if (sq->front == (sq->rear + 1) % QUEUE_SIZE)
		return FALSE;

	sq->rear = (sq->rear + 1) % QUEUE_SIZE;//��βָ�����
	sq->data[sq->rear] = x;//Ԫ�����

	return TRUE;
}

///��������ӿգ����ص���Ԫ�صĽǱ��Ϊ-1;���򷵻�����Ǳ�
BOOL DeSqQueue(SeqQueue* sq)
{
	if (!IsEmpty_SqQueue(sq))
	{
		sq->front = (sq->front + 1) % QUEUE_SIZE;
		return sq->front;
	}

	return -1;
}

int main(void)
{
	return 0;
}