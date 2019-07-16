#include <stdio.h>
#include "SeqStack.h"

//����չ���ţ����޸ķ��
//�޸�һ��������ж�
int Is_OperatorEx(char op)
{
	switch (op)
	{
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}

int PriorityEx(char op)
{
	switch (op)
	{
	case '(': return 1;
	case '+':
	case '-': return 2;
	case '*':
	case '/':
		return 3;
	default:
		return 0;
	}
}

int main(void)
{
	char inorder[50] = "1+((2+3)*4)-5#";//������׺(����)���ʽ���ַ���
	char postorder[50];
	int op = 0;//�����
	int in_position;//������ʽ�ĽǱ�
	int po_position;//�������ʽ�ĽǱ�
	int i;
	in_position = 0;
	po_position = 0;
	for (int i = 0; i < 50; i++)
	{
		postorder[i] = 0;
	}
	SeqStack sOper;
	init(&sOper);

	while (inorder[in_position] != '#')
	{
		//todo:����ջ�������ȼ�,ȥ���ŵĹ���
		if (Is_OperatorEx(inorder[in_position]))
		{
			if (isEmpty(&sOper) || inorder[in_position] == '(')
				pushStack(&sOper, inorder[in_position]);
			else
			{
				if (inorder[in_position] == ')')
				{
					//ƥ��������
					while (sOper.stack[sOper.top] != '(')
					{
						op = popStack(&sOper);
						postorder[po_position++] = op;
					}
					if (sOper.stack[sOper.top] == '(')
					{
						popStack(&sOper);
					}
				}//ctrl + ] ������ת
				else
				{
					while (PriorityEx(inorder[in_position]) <= PriorityEx(sOper.stack[sOper.top]) && !isEmpty(&sOper))
					{
						op = popStack(&sOper);
						postorder[po_position++] = op;
					}

					pushStack(&sOper, inorder[in_position]);
				}
			}
		}
		else
		{
			postorder[po_position++] = inorder[in_position];
		}

		in_position++;
	}

	while (!isEmpty(&sOper))
	{
		op = popStack(&sOper);
		postorder[po_position++] = op;
	}

	for (int i = 0; i < 50; i++)
	{
		if (postorder[i] == 0)
			break;
		printf("%c", postorder[i]);//123+4*+5-
	}

	getchar();
	return 0;
}