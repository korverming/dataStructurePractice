#include <stdio.h>
#include <stdlib.h>

/*
1.栈的初始化
2.取栈顶的元素
3.压栈：在栈S中插入元素e，使其成为新的栈顶元素
4.出栈：删除S中的栈顶元素
5.判断栈空
*/

#define stackSize 100

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef int ElemType;//元素类型

typedef struct
{
	ElemType stack[stackSize];
	int top;//栈顶指针
} SeqStack;

///栈的初始化
BOOL init(SeqStack* pStack)
{
	pStack->top = 0;
	return 1;
}

///栈的判空
BOOL isEmpty(SeqStack* pStack)
{
	return (pStack->top == 0);
}

///压栈
///返回值为1表示成功，-1表示失败
///pStack表示顺序栈，x表示压入的元素
BOOL pushStack(SeqStack* pStack, ElemType x)
{
	if (pStack->top == stackSize)
	{
		printf("空间溢出\n");
		return FALSE;
	}

	pStack->top = pStack->top + 1;
	pStack->stack[pStack->top] = x;

	return TRUE;
}

///出栈
ElemType popStack(SeqStack* pStack)
{
	ElemType tmp;
	if (pStack->top == 0)
	{
		printf("当前是空栈\n");
		return -1;
	}

	tmp = pStack->stack[pStack->top];
	pStack->top = pStack->top - 1;//逻辑上的出栈

	return tmp;
}

void myConv(SeqStack* pStack, int n)
{
	int e;//每一个元素
	while (n)
	{
		pushStack(pStack, n % 8);
		n = n / 8;
	}

	while (!isEmpty(pStack))
	{
		e = popStack(pStack);
		printf("%d", e);
	}
}

///获取栈顶元素
///如果栈为空，返回取值不成功，否则直接取出栈顶元素供用户使用
BOOL GetSeqStack(SeqStack* s, ElemType* data)
{
	if (s->top == 0)
		return FALSE;
	*data = s->stack[s->top];
	return TRUE;
}
int main1(void)
{
	SeqStack s;
	init(&s);
	printf("十进制数1348，转为的8进制是:\n");
	myConv(&s, 1348);
	getchar();
	return 0;
}

/*
首先我们必须知道，一旦设立了栈，那么就请按照栈的特点进行操作
“先进后出”
我们都知道，只要知道下标，就可以获取数组的元素
stack[0],stack[1],stack[2].....
我们没有能力再直接操作上面的元素
我们只能取栈顶，因为只有这一个函数；其他，要么出栈，要么进栈
*/