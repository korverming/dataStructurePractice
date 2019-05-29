//设有一个顺序表，其数据为a,b,c,d,e,f,g,
//要求将其就地转置为g,f,e,d,c,b,a
//要求逆转表仍然占据原空间
#include "SeqList.h"
#include <stdlib.h>
#include "LinkList.h"

SequenList *pGlobalSeq;

void ReverseSeqList(SequenList* pList)
{
	int temp;
	int count, i;

	if (pList->last == 0 || pList->last == 1)
		return;

	count = pList->last / 2;
	for (i = 0; i < count; i++)
	{
		temp = pList->data[i];
		pList->data[i] = pList->data[pList->last - 1 - i];
		pList->data[pList->last - 1 - i] = temp;
	}

}

int main5(void)
{
	pGlobalSeq = InitSeq();
	for (int i = 0; i < 10; i++)
	{
		InsertElemSqList(pGlobalSeq, i * 2, i);
	}

	printf("\n***************当前的顺序表元素****************\n");
	showSeqList(pGlobalSeq);
	ReverseSeqList(pGlobalSeq);
	printf("\n***************当前的顺序表元素****************\n");
	showSeqList(pGlobalSeq);
	free(pGlobalSeq);
	getchar();
	return 0;
}

LinkListNode* ReverseLkList(LinkListNode* pHead)
{
	LinkListNode* Pointer, *Next;//Pointer是将来依次获得的当前节点
	//Next：将来获得的当前节点的原先的下一个节点
	LinkListNode* Back;//原先节点的上一个节点
	//step1：将原先的next节点的next域变成pointer
	//step2：将原先的pointer的next域变成back

	Back = pHead;//原先就是从头节点开始，因此，我们首先将back作为头节点
	Pointer = Back->pNext;//通过头节点获得了第一个元素

	Next = Pointer->pNext;//此时pointer是第一个元素，因此它的pNext是第二个元素
	Pointer->pNext = Back;//pointer->pNext域变成了Back，又因为Back是头节点，
	//所以原先的第一个元素的后继已经变成了头节点
	Back = Pointer;//pointer是第一个元素，因此此时Back变成了第一个元素
	Pointer = Next;//因为Next已经是第二个元素了，因此此时pointer指向了第二个元素

	//在57行，next变成了原先的第二个元素，又因为57-61行，没有再对Next的pnext域
	//进行操作，因此原先链表中的后继信息没有破坏
	//58行，pointer作为当前元素指向了原先的前继节点的时候，此时当前元素把原先的前继元素
	//变成了后继节点
	//60行，再将Back设为当前元素，61行将Pointer设为下一个元素

	while (Pointer->pNext != NULL)
	{
		Next = Pointer->pNext;
		Pointer->pNext = Back;
							  
		Back = Pointer;
		Pointer = Next;
	}

	Pointer->pNext = Back;
	//此时Pointer已经是原先链表中的最后一个元素了
	//因此必须要把Pointer和原先的前继节点联系起来
	//而原先的前继节点一定在back中

	//此时反转完毕，需要重新设置头节点
	//原先的pHead没有变，因此原先的pHead->pNext指向原先的第一个元素
	//但是现在我么要让这个元素的pNext域设置为空
	pHead->pNext->pNext = NULL;
	//由于pHead没有变化，所以我们依然让它作为反转后链表的头节点
	//所以将当前的首元素放置它的pnext域中
	pHead->pNext = Pointer;

	return pHead;

}

int main(void)
{
	LinkListNode* pHead = NULL;
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	pHead = Create_Rear_LkList(arr, 10);
	printf("\n*********************当前的元素有\n");
	ShowLkList(pHead);

	pHead = ReverseLkList(pHead);
	printf("\n*********************当前的元素有\n");
	ShowLkList(pHead);
	getchar();
	return 0;
}