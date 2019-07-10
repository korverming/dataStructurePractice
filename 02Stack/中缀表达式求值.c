#include <stdio.h>
#include <stdlib.h>

//�ٶ��������һλ����û������
#define stackSize 100

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef int ElemType;//Ԫ������

typedef struct
{
	ElemType stack[stackSize];
	int top;//ջ��ָ��
} SeqStack;

///ջ�ĳ�ʼ��
BOOL init(SeqStack* pStack)
{
	pStack->top = 0;
	return 1;
}

///ջ���п�
BOOL isEmpty(SeqStack* pStack)
{
	return (pStack->top == 0);
}

///ѹջ
///����ֵΪ1��ʾ�ɹ���-1��ʾʧ��
///pStack��ʾ˳��ջ��x��ʾѹ���Ԫ��
BOOL pushStack(SeqStack* pStack, ElemType x)
{
	if (pStack->top == stackSize)
	{
		printf("�ռ����\n");
		return FALSE;
	}

	pStack->top = pStack->top + 1;
	pStack->stack[pStack->top] = x;

	return TRUE;
}

///��ջ
ElemType popStack(SeqStack* pStack)
{
	ElemType tmp;
	if (pStack->top == 0)
	{
		printf("��ǰ�ǿ�ջ\n");
		return -1;
	}

	tmp = pStack->stack[pStack->top];
	pStack->top = pStack->top - 1;//�߼��ϵĳ�ջ

	return tmp;
}

///��ȡջ��Ԫ��
///���ջΪ�գ�����ȡֵ���ɹ�������ֱ��ȡ��ջ��Ԫ�ع��û�ʹ��
BOOL GetSeqStack(SeqStack* s, ElemType* data)
{
	if (s->top == 0)
		return FALSE;
	*data = s->stack[s->top];
	return TRUE;
}

//�ж��Ƿ��������,����������������true�����򷵻�false
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

//�ж����ȼ��� x/ Ϊ2��+��-Ϊ1��
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

//������ֵ:�����Ǹ�������Ҳ�����ǳ���Ϊ0
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
	int position = 0;//ɨ����ַ���
	int op = 0;//�����
	int operand1 = 0;
	int operand2 = 0;
	int evaluate = 0;//������

	SeqStack sOperator;//������ջ
	init(&sOperator);
	SeqStack sOperand;
	init(&sOperand);//������ջ

	//��һ��ɨ���ַ���
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
			pushStack(&sOperand, expression[position] - 48);//��ascii��ת����ֵ
		}

		position++;
	}

	//��ղ�����ջ
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