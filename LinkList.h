#pragma once
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int ElemType;//�ٶ����Ա��Ԫ������Ϊ����

//����ڵ�
typedef struct node
{
	int data;
	struct node* pNext;
} LinkListNode;

///��������ͷ�ڵ������Init
///�����ķ���ֵ��ͷ�ڵ㣬û�в���
LinkListNode* InitLinkList(void);

///�󳤶ȣ���˳����е�Ԫ�صĸ���
///�����ķ���ֵ��˳���ĳ��ȣ�����pHead���ǵ������ͷ�ڵ�
int GetSizeLinkList(LinkListNode* pHead);

///ȡԪ�أ�ȡ����λ�õ�Ԫ��ֵ
///����ֵ����i��Ԫ�صĵ�ַ�� pHead:ͷָ��  i:����ڵ�����
LinkListNode* GetLinkListNode(LinkListNode* pHead, int pos);

///��Ԫ�أ����Ҹ���Ԫ��ֵ��λ��
///����ֵ���ڵ�ĵ�ַ���Ҳ����ͷ���NULL
///pHead:�������ͷָ�룬 objData������Ҫƥ���Ԫ��ֵ
LinkListNode* locateLinkList(LinkListNode* pHead, int objData);

///����Ԫ�أ���ָ����λ�ò��������ֵ
///β�巨�������������߼��ϵ�˳�����뵥���������ṹ�У�
///����ֵ�������ͷָ�룬arr:�����˳���   length:˳���ĳ���
LinkListNode* Create_Rear_LkList(ElemType arr[], int length);

///ͷ�巨����������
///����ֵ�������ͷָ�룬arr:�����˳���   length:˳���ĳ���
LinkListNode* Create_Front1_LkList(ElemType arr[], int length);

///ͷ�巨2
///����ֵ�������ͷָ�룬arr:�����˳���   length:˳���ĳ���
LinkListNode* Create_Front2_LkList(ElemType arr[], int length);

///ͷ�巨3
///����ֵ�������ͷָ�룬arr:�����˳���   length:˳���ĳ���
LinkListNode* Create_Front3_LkList(ElemType arr[], int length);

///����Ԫ�أ���ָ����λ�ò��������ֵ
///ptr:�������Ԫ�ص�λ�ã�����ptr�ĺ�̽ڵ��в��룬x:�����ֵ
void Insert_After_LkList(LinkListNode* ptr, ElemType x);

///ָ��λ��֮ǰ����
///pHead:�����ͷָ�룬 ptr���������Ԫ��λ�ã�x:�����ֵ
void Insert_Before_LkList(LinkListNode* pHead, LinkListNode* ptr, ElemType x);


///ɾ���ڵ㣺Ptr����Ҫɾ���Ľڵ㣬��ɾ��ptr�ĺ����ڵ�
///����ֵ�Ǵ�ɾ���Ľڵ�λ��
LinkListNode* Delete_After_LkList(LinkListNode* ptr);

///ɾ����i���ڵ�
///����ֵ�Ǵ�ɾ���Ľڵ�λ��, pHead:ͷ�ڵ㣬 i�ǵ�i��Ԫ��
LinkListNode* Delete_i_LkList(LinkListNode* pHead, int i);

///����
void ShowLkList(LinkListNode* pHead);