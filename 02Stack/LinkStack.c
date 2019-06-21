#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node
{
	datatype data;

	struct node* pNext;
} LinkStack;

//��ջ
LinkStack* PushLkStack(LinkStack* top, datatype x)
{
	LinkStack* p;
	p = (LinkStack*)malloc(sizeof(LinkStack));
	p->data = x;
	//���������Ƚ�p��������
	p->pNext = top;
	//top���Ƶ���ǰջ����ָ��ոռ����p�ڵ㣬��ʱtop��Զָ��ջ���ĵ�һ��Ԫ��
	top = p;

	return top;
}

//��ջ
LinkStack* PopLkStack(LinkStack* top, datatype* pData)
{
	LinkStack* p;
	//һ�����ǳ�ջ����ô������Ϊ���Ԫ�ؾͲ�Ӧ��ά������ָ���ϵ��
	if (top != NULL)
	{
		*pData = top->data;
		//��ʱ���ǽ���ǰ��ջ��Ԫ�ص�λ�ã�����������������ջ��Ԫ�ؼ�������
		p = top;
		top = p->pNext;
		free(p);
	}

	return top;
}

int main(void)
{
	//�����ʼ��
	//����ջ��ָ���pNext��Ұָ��
	LinkStack* pTop = NULL;
	pTop = PushLkStack(pTop, 1);
	pTop = PushLkStack(pTop, 1);
	getchar();
	return 0;
}