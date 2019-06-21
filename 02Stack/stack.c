#include <stdio.h>
#include <stdlib.h>

/*
1.ջ�ĳ�ʼ��
2.ȡջ����Ԫ��
3.ѹջ����ջS�в���Ԫ��e��ʹ���Ϊ�µ�ջ��Ԫ��
4.��ջ��ɾ��S�е�ջ��Ԫ��
5.�ж�ջ��
*/

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

void myConv(SeqStack* pStack, int n)
{
	int e;//ÿһ��Ԫ��
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

///��ȡջ��Ԫ��
///���ջΪ�գ�����ȡֵ���ɹ�������ֱ��ȡ��ջ��Ԫ�ع��û�ʹ��
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
	printf("ʮ������1348��תΪ��8������:\n");
	myConv(&s, 1348);
	getchar();
	return 0;
}

/*
�������Ǳ���֪����һ��������ջ����ô���밴��ջ���ص���в���
���Ƚ������
���Ƕ�֪����ֻҪ֪���±꣬�Ϳ��Ի�ȡ�����Ԫ��
stack[0],stack[1],stack[2].....
����û��������ֱ�Ӳ��������Ԫ��
����ֻ��ȡջ������Ϊֻ����һ��������������Ҫô��ջ��Ҫô��ջ
*/