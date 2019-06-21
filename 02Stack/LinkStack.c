#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node
{
	datatype data;

	struct node* pNext;
} LinkStack;

//入栈
LinkStack* PushLkStack(LinkStack* top, datatype x)
{
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	//类似于首先将p链入链表
	p->pNext = top;
	//top上移到当前栈顶，指向刚刚加入的p节点，此时top永远指向栈顶的第一个元素
	top = p;

	return top;
}

//出栈
LinkStack* PopLkStack(LinkStack* top, datatype* pData)
{
	LinkStack* p;
	//一旦我们出栈，那么我们认为这个元素就不应当维护链表指向关系了
	if (top != NULL)
	{
		*pData = top->data;
		//此时我们将当前的栈顶元素的位置，保存下来，接下来栈顶元素即将脱离
		p = top;
		top = p->pNext;
		free(p);
	}

	return top;
}

int main(void)
{
	//必须初始化
	//否则栈顶指针的pNext是野指针
	LinkStack* pTop = NULL;
	pTop = PushLkStack(pTop, 1);
	pTop = PushLkStack(pTop, 1);
	getchar();
	return 0;
}