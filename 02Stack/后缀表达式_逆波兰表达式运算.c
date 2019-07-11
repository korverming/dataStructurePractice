#include <stdio.h>
#include "SeqStack.h"

int main(void)
{
	char expression[] = "1562/-3*+#";
	int position = 0;
	int operand1 = 0;
	int operand2 = 0;
	int evaluate = 0;//没有所谓的操作符

	SeqStack sStack;
	init(&sStack);
	while (expression[position] != '#')
	{
		if (Is_Operator(expression[position]))
		{
			operand1 = popStack(&sStack);
			operand2 = popStack(&sStack);
			pushStack(&sStack, two_res(expression[position], operand1, operand2));
		}
		else
		{
			pushStack(&sStack, expression[position] - 48);
		}
		position++;
	}

	evaluate = popStack(&sStack);
	printf("%d ", evaluate);

	getchar();
	return 0;
}