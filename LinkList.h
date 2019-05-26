#pragma once
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int ElemType;//假定线性表的元素类型为整型

//定义节点
typedef struct node
{
	int data;
	struct node* pNext;
} LinkListNode;

///创建带有头节点的链表Init
///函数的返回值是头节点，没有参数
LinkListNode* InitLinkList(void);

///求长度：求顺序表中的元素的个数
///函数的返回值是顺序表的长度，参数pHead：是单链表的头节点
int GetSizeLinkList(LinkListNode* pHead);

///取元素：取给定位置的元素值
///返回值：第i个元素的地址， pHead:头指针  i:待查节点的序号
LinkListNode* GetLinkListNode(LinkListNode* pHead, int pos);

///查元素：查找给定元素值的位置
///返回值：节点的地址，找不到就返回NULL
///pHead:单链表的头指针， objData：是需要匹配的元素值
LinkListNode* locateLinkList(LinkListNode* pHead, int objData);

///插入元素：在指定的位置插入给定的值
///尾插法建立单链表（将逻辑上的顺序表放入单链表的物理结构中）
///返回值：链表的头指针，arr:传入的顺序表   length:顺序表的长度
LinkListNode* Create_Rear_LkList(ElemType arr[], int length);

///头插法建立单链表
///返回值：链表的头指针，arr:传入的顺序表   length:顺序表的长度
LinkListNode* Create_Front1_LkList(ElemType arr[], int length);

///头插法2
///返回值：链表的头指针，arr:传入的顺序表   length:顺序表的长度
LinkListNode* Create_Front2_LkList(ElemType arr[], int length);

///头插法3
///返回值：链表的头指针，arr:传入的顺序表   length:顺序表的长度
LinkListNode* Create_Front3_LkList(ElemType arr[], int length);

///插入元素：在指定的位置插入给定的值
///ptr:待插入的元素的位置，将在ptr的后继节点中插入，x:插入的值
void Insert_After_LkList(LinkListNode* ptr, ElemType x);

///指定位置之前插入
///pHead:链表的头指针， ptr：待插入的元素位置，x:插入的值
void Insert_Before_LkList(LinkListNode* pHead, LinkListNode* ptr, ElemType x);


///删除节点：Ptr是需要删除的节点，将删除ptr的后续节点
///返回值是带删除的节点位置
LinkListNode* Delete_After_LkList(LinkListNode* ptr);

///删除第i个节点
///返回值是带删除的节点位置, pHead:头节点， i是第i个元素
LinkListNode* Delete_i_LkList(LinkListNode* pHead, int i);

///遍历
void ShowLkList(LinkListNode* pHead);