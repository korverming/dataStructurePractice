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
	//队空时front=rear
	sq->front = QUEUE_SIZE - 1;
	sq->rear = QUEUE_SIZE - 1;
}

BOOL IsEmpty_SqQueue(SeqQueue* sq)
{
	if (sq->rear == sq->front)
		return TRUE;

	return FALSE;
}

//返回的应当是数组的角标
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

	sq->rear = (sq->rear + 1) % QUEUE_SIZE;//队尾指针后移
	sq->data[sq->rear] = x;//元素入队

	return TRUE;
}

///出队如果队空，返回的是元素的角标记为-1;否则返回数组角标
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