#include "LinkList.h"
#include <stdlib.h>
int main2(void)
{
	LinkListNode x, y, *p;
	p = &x;
	x.data = 100;
	x.pNext = NULL;

	y.data = 200;
	y.pNext = NULL;

	x.pNext = &y;

	p = &y;
	p->data;
	getchar();
	return 0;
}

int main3(void)
{
	LinkListNode *xPtr, *yPtr, *p;
	xPtr = (LinkListNode*)malloc(sizeof(LinkListNode));

	if (xPtr)
	{
		xPtr->pNext = NULL;
		xPtr->data = 100;
	}

	yPtr = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (yPtr)
	{
		yPtr->pNext = NULL;
		yPtr->data = 200;
	}

	xPtr->pNext = yPtr;

	getchar();
	return 0;
}

