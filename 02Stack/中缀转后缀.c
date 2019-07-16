#include <stdio.h>
#include "SeqStack.h"

//对扩展开放，对修改封闭
//修改一下运算符判断
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
	char inorder[50] = "1+((2+3)*4)-5#";//声明中缀(中序)表达式的字符串
	char postorder[50];
	int op = 0;//运算符
	int in_position;//中序表达式的角标
	int po_position;//后续表达式的角标
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
		//todo:利用栈进行优先级,去括号的过程
		if (Is_OperatorEx(inorder[in_position]))
		{
			if (isEmpty(&sOper) || inorder[in_position] == '(')
				pushStack(&sOper, inorder[in_position]);
			else
			{
				if (inorder[in_position] == ')')
				{
					//匹配左括号
					while (sOper.stack[sOper.top] != '(')
					{
						op = popStack(&sOper);
						postorder[po_position++] = op;
					}
					if (sOper.stack[sOper.top] == '(')
					{
						popStack(&sOper);
					}
				}//ctrl + ] 括号跳转
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