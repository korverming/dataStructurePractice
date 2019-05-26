#include "LinkList.h"
#include <malloc.h>
/*
1��	��ʼ���������Ա��е���ز�����ֵ
2��	�󳤶ȣ������Ա��е�Ԫ�صĸ���
3��	ȡԪ�أ�ȡ����λ�õ�Ԫ��ֵ
4��	��Ԫ�أ����Ҹ���Ԫ��ֵ��λ��
5��	����Ԫ�أ���ָ����λ�ò��������ֵ
6��	ɾ����ɾ��ָ��λ�õ�ֵ������ɾ��������ֵ��
7��	����Ԫ�أ���ͷ��βɨ�����Ա�
*/

//��������ͷ�ڵ������Init
LinkListNode* InitLinkList()
{
	LinkListNode* pHead = NULL;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	if (pHead)
	{
		pHead->pNext = NULL;
	}

	return pHead;
}

//�󳤶ȣ������Ա��е�Ԫ�صĸ���
int GetSizeLinkList(LinkListNode* pHead)
{
	int n = 0;
	while (pHead->pNext)
	{
		n++;
		pHead = pHead->pNext;
	}

	return n;
}

//ȡԪ�أ�ȡ����λ�õ�Ԫ��ֵ
//���������ͷָ�룬Ҫ���ҵı�ţ������i��Ԫ�صĵ�ַ
//pHead:ͷָ��  i:����ڵ�����
LinkListNode* GetLinkListNode(LinkListNode* pHead, int pos)
{
	int j;
	LinkListNode* p;
	p = pHead;
	j = 0;
	if (pos == 0)//?????
		return NULL;

	while (j < pos && p->pNext != NULL)
	{
		j++;
		p = p->pNext;
	}

	if (pos == j)
		return p;
	else
		return NULL;
}

//��Ԫ�أ����Ҹ���Ԫ��ֵ��λ��
//�ҵ��ͷ��ؽڵ�ĵ�ַ���Ҳ����ͷ���NULL
LinkListNode* locateLinkList(LinkListNode* pHead, int objData)
{
	LinkListNode* p;
	p = pHead->pNext;
	while (p != NULL &&p->data != objData)
	{
		p = p->pNext;
	}

	return p;
}

//����Ԫ�أ���ָ����λ�ò��������ֵ
//��Ϊ�������ֽṹ���ڴ����ɳ���Ա����ģ�
//������Ľ�����һ�������㷽��
//β�巨�������������߼��ϵ�˳�����뵥���������ṹ�У�
//arr:�����˳���   length:˳���ĳ���
LinkListNode* Create_Rear_LkList(ElemType arr[], int length)
{
	LinkListNode* pHead, *p = NULL, *q;
	int i;//ѭ����������������ȫ����˳���

	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));

	q = pHead;//q����˵�ǰ�����ͷ�ڵ�
	//q������pHead��ͬʱͨ��q����ǰ��ʹ������������
	for (i = 0; i < length; i++)
	{
		//���һ��������Ľڵ㣬������ڵ�
		//���뵽��pHeadָ������������
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		//p���һ�����Լ�������Ľڵ㵥Ԫ
		p->data = arr[i];//��˳�������ݴ��뵥����Ľڵ�

		q->pNext = p;
		q = p;
	}

	p->pNext = NULL;

	return pHead;
}

//ͷ�巨����������
LinkListNode* Create_Front1_LkList(ElemType arr[], int length)
{
	LinkListNode* pHead, *p, *q;
	int i;

	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = NULL;
	q = pHead->pNext;

	//ͷ��ʱ�����������˳���
	for (i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = q;//ʹ���¼���Ľڵ㴮������һ���ڵ�
		//q = p;
		pHead->pNext = p;//ͷ�ڵ�ָ���˵�ǰ���¼���ڵ�
		q = pHead->pNext;//��qָ��ǰ�Ľڵ�
	}

	return pHead;
}

//ͷ�巨2
LinkListNode* Create_Front2_LkList(ElemType arr[], int length)
{
	LinkListNode* pHead, *p, *q;
	int i;
	q = NULL;
	for (i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = q;
		q = p;
	}

	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = q;

	return pHead;
}

//ͷ�巨3
LinkListNode* Create_Front3_LkList(ElemType arr[], int length)
{
	LinkListNode* pHead, *p;
	int i;
	pHead = (LinkListNode*)malloc(sizeof(LinkListNode));
	pHead->pNext = NULL;
	for (i = length - 1; i >= 0; i--)
	{
		p = (LinkListNode*)malloc(sizeof(LinkListNode));
		p->data = arr[i];
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}
	//֮�������ǵķ���3���Խ�ʡ����1�е�һ������q
	//ԭ����pHead�������仯����pHead�е�pNextʼ����Ϊ��ǰ�ڵ��ָ��

	return pHead;
}
/*
˳���12��33��44��76��89��90���߼��ϵ�˳���==>������
�����������������ʾ����˳���
*/

//����Ԫ�أ���ָ����λ�ò��������ֵ
//��ָ��λ��֮�����
void Insert_After_LkList(LinkListNode* ptr, ElemType x)
{
	LinkListNode* s;
	s = (LinkListNode*)malloc(sizeof(LinkListNode));
	s->data = x;
	s->pNext = ptr->pNext;
	ptr->pNext = s;
}

//ָ��λ��֮ǰ����
void Insert_Before_LkList(LinkListNode* pHead, LinkListNode* ptr, ElemType x)
{
	LinkListNode* s, *qPtr;
	s = (LinkListNode*)malloc(sizeof(LinkListNode));
	s->data = x;
	qPtr = pHead;//qPtr��������pHead���ƶ�
	while (qPtr->pNext != ptr)
	{
		qPtr = qPtr->pNext;
	}

	s->pNext = ptr;
	qPtr->pNext = s;
	//��Ϊ�����ǵ���ģ���Ȼ��֪����ǰ�ڵ���ptr
	//�������﷨�����ϣ��������֪��ptr��ǰ�̽ڵ�ֻ�ܴ�head��������
	//�鵽�˵�ǰ�ڵ��ǰ�̲���ʹ�ú��ķ�����ɽڵ�ļ���
}

//ɾ����ɾ��ָ��λ�õ�ֵ������ɾ��������ֵ
//����1��ɾ��ָ���ڵ�ĺ�̽ڵ�
//����2��ɾ����i���ڵ㣬�ٶ�ͷ�ڵ�i=0
//ɾ������Ŀ��ڵ�ĵ�ַ�������漰����̬�ռ�Ļ���
//�ڶ�̬���տռ��Ҫ���У�Ӧ����ѭ��ԭ����˭��Ⱦ˭����
//��˳����е�ɾ�������߼��ϵ�ɾ��������˵���ǵ�����ڵ㲻��
//�����ڵ�ǰ��˳�������
///ɾ���ڵ㣺Ptr����Ҫɾ���Ľڵ㣬��ɾ��ptr�ĺ����ڵ�
LinkListNode* Delete_After_LkList(LinkListNode* ptr)
{
	LinkListNode* fptr;
	//�ٶ�˳���A->B->C,ɾ��A�ĺ����ڵ�B��A->C
	fptr = ptr->pNext;//ptr��A������ptr��next��B������fptr��B
	ptr->pNext = fptr->pNext;//ptr��A��fptr��B������fptr��next��C������ptr->next�ͱ����C

	return fptr;
}

///ɾ����i���ڵ�
LinkListNode* Delete_i_LkList(LinkListNode* pHead, int i)
{
	LinkListNode* ptr, *qPtr = NULL;
	ptr = GetLinkListNode(pHead, i - 1);//�ҵ�i��ǰ�̽ڵ�

	if (ptr != NULL && ptr->pNext != NULL)
	{
		qPtr = Delete_After_LkList(ptr);
	}

	return qPtr;
}

//����
void ShowLkList(LinkListNode* pHead)
{
	LinkListNode* p = pHead->pNext;
	while (p != NULL)
	{
		printf(" %d", p->data);
		p = p->pNext;
	}
}

//test push
int main(void)
{
	ElemType MySeq[] = {1, 2, 3, 4, 5};
	LinkListNode* pHead = Create_Rear_LkList(MySeq, 5);
	printf("\n**************��ʾ��ǰ�������е�ȫ��Ԫ��***************\n");
	ShowLkList(pHead);
	LinkListNode* pPos = GetLinkListNode(pHead, 2);
	Insert_After_LkList(pPos, 999);
	printf("\n**************��ʾ��ǰ�������е�ȫ��Ԫ��**********\n");
	ShowLkList(pHead);
	Insert_Before_LkList(pHead, pPos, 666);
	printf("\n**************��ʾ��ǰ�������е�ȫ��Ԫ��**********\n");
	ShowLkList(pHead);
	//Delete_After_LkList(pPos);
	Delete_i_LkList(pHead, 2);
	printf("\n**************��ʾ��ǰ�������е�ȫ��Ԫ��**********\n");
	ShowLkList(pHead);
	printf("\nList Size: %d", GetSizeLinkList(pHead));
	//Create_Front1_LkList(MySeq, 5);
	//Create_Front2_LkList(MySeq, 5);
	getchar();
	return 0;
}

