#include <stdio.h>
#include <stdlib.h>

///ѭ������Ľ���
///���룺˳����ϣ�˳�����
///�����ѭ�������β��ַ
typedef struct node
{
	int data;
	struct node* pNext;
} LinkCircleListNode;

LinkCircleListNode* Create_Circle_LkList(int arr[], int length)
{
	LinkCircleListNode *head, *p, *q;
	int i;
	head = (LinkCircleListNode*)malloc(sizeof(LinkCircleListNode));
	q = head;

	for (i = 0; i < length; i++)
	{
		//pָ������ʱ����Ŀռ�
		p = (LinkCircleListNode*)malloc(sizeof(LinkCircleListNode));
		p->data = arr[i];
		//q�ڴ���p�Ľڵ�
		q->pNext = p;
		//q�ƶ�����ǰ�Ľڵ�
		q = p;
	}
	p->pNext = head;

	return p;
}

//�������
void ShowCircleLkList(LinkCircleListNode* pRear)
{
	LinkCircleListNode* p = pRear->pNext;
	//��Ϊ������ʱ������ϣ�����������Ԫ�أ���������������p�ƶ�
	p = p->pNext;//��ʱpָ���һ��������Ԫ��
	while (p != pRear->pNext)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}
}

//����ѭ������ĺϲ�
//����Ϊ����a��βָ�룬����b��βָ��
LinkCircleListNode* Connect_Circle_LkList(LinkCircleListNode* ra, LinkCircleListNode* rb)
{
	LinkCircleListNode* p;
	//��¼a��ͷ�ڵ�
	p = ra->pNext;
	//��b�ĵ�һ��Ԫ�ؽڵ�����a��β��
	ra->pNext = rb->pNext->pNext;
	free(rb->pNext);//���տռ䣬��ζ��b�����ͷ�ڵ�ռ䲻�ɴ����rb->pNext��Ȼ����ֵ��
	rb->pNext = p;
	//�ٶ�rb��0x20�ռ䣬��0x20�ռ�����һ��next��������������ǿ��Դ洢��ֵַ
	//free(rb)����ʹ��rb->pNext������
	//free(rb->pNext),rb->pNext�еģ�data��pnext������������
	//rb->pNextʼ��ָ�����ԭb�����е�ͷ�ڵ�
	//����57��ִ����Ϻ󣬽�b�����βָ��ָ����a�����ͷ�ڵ�

	return rb;
}

int main()
{
	//int arr[] = {11, 22, 33, 44, 55};
	//LinkCircleListNode* pRear = Create_Circle_LkList(arr, 5);
	//ShowCircleLkList(pRear);

	//���Ժϲ�
	int a[] = { 1, 3, 5 };
	int b[] = { 2, 4, 6 };
	LinkCircleListNode* ra, *rb;
	ra = Create_Circle_LkList(a, 3);
	rb = Create_Circle_LkList(b, 3);
	LinkCircleListNode* pRear = Connect_Circle_LkList(ra, rb);
	ShowCircleLkList(pRear);
	getchar();
	return 0;
}
