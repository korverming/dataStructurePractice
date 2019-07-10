#include <stdio.h>
#include <stdlib.h>

//假定处理的是一位数，没有括号
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

///获取栈顶元素
///如果栈为空，返回取值不成功，否则直接取出栈顶元素供用户使用
BOOL GetSeqStack(SeqStack* s, ElemType* data)
{
	if (s->top == 0)
		return FALSE;
	*data = s->stack[s->top];
	return TRUE;
}

//判断是否是运算符,如果是运算符，返回true，否则返回false
BOOL Is_Operator(char oper)
{
	switch (oper)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return TRUE;
	default:
		return FALSE;
	}
}

//判断优先级： x/ 为2，+，-为1，
int Priority(char oper)
{
	switch (oper)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}

//计算数值:不考虑浮点数，也不考虑除数为0
int two_res(int oper, int opand1, int opand2)
{
	switch (oper)
	{
	case '+':
		return (opand2 + opand1);
	case '-':
		return (opand2 - opand1);
	case '*':
		return (opand2 * opand1);
	case '/':
		return (opand2 / opand1);
	default:
		return 0;
	}
}

int main(void)
{
	char expression[] = "8*9-4/2";
	int position = 0;//扫描的字符串
	int op = 0;//运算符
	int operand1 = 0;
	int operand2 = 0;
	int evaluate = 0;//运算结果

	SeqStack sOperator;//操作符栈
	init(&sOperator);
	SeqStack sOperand;
	init(&sOperand);//操作数栈

	//第一步扫描字符串
	while (expression[position] != '\0' && expression[position] != '\n')
	{
		if (Is_Operator(expression[position]))
		{
			if (!isEmpty(&sOperand))
			{
				while 
				(
					Priority(expression[position]) <= Priority(sOperator.stack[sOperator.top]) &&
					!isEmpty(&sOperator)
				)
				{
					operand1 = popStack(&sOperand);
					operand2 = popStack(&sOperand);
					op = popStack(&sOperator);
					pushStack(&sOperand, two_res(op, operand1, operand2));
				}
			}
			pushStack(&sOperator, expression[position]);
		}
		else
		{
			pushStack(&sOperand, expression[position] - 48);//将ascii码转成数值
		}

		position++;
	}

	//清空操作符栈
	while (!isEmpty(&sOperator))
	{
		op = popStack(&sOperator);
		operand1 = popStack(&sOperand);
		operand2 = popStack(&sOperand);
		pushStack(&sOperand, two_res(op, operand1, operand2));
	}

	printf("%d", popStack(&sOperand));
	getchar();
	return 0;
}