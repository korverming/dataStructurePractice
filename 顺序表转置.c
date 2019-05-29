//����һ��˳���������Ϊa,b,c,d,e,f,g,
//Ҫ����͵�ת��Ϊg,f,e,d,c,b,a
//Ҫ����ת����Ȼռ��ԭ�ռ�
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

	printf("\n***************��ǰ��˳���Ԫ��****************\n");
	showSeqList(pGlobalSeq);
	ReverseSeqList(pGlobalSeq);
	printf("\n***************��ǰ��˳���Ԫ��****************\n");
	showSeqList(pGlobalSeq);
	free(pGlobalSeq);
	getchar();
	return 0;
}

LinkListNode* ReverseLkList(LinkListNode* pHead)
{
	LinkListNode* Pointer, *Next;//Pointer�ǽ������λ�õĵ�ǰ�ڵ�
	//Next��������õĵ�ǰ�ڵ��ԭ�ȵ���һ���ڵ�
	LinkListNode* Back;//ԭ�Ƚڵ����һ���ڵ�
	//step1����ԭ�ȵ�next�ڵ��next����pointer
	//step2����ԭ�ȵ�pointer��next����back

	Back = pHead;//ԭ�Ⱦ��Ǵ�ͷ�ڵ㿪ʼ����ˣ��������Ƚ�back��Ϊͷ�ڵ�
	Pointer = Back->pNext;//ͨ��ͷ�ڵ����˵�һ��Ԫ��

	Next = Pointer->pNext;//��ʱpointer�ǵ�һ��Ԫ�أ��������pNext�ǵڶ���Ԫ��
	Pointer->pNext = Back;//pointer->pNext������Back������ΪBack��ͷ�ڵ㣬
	//����ԭ�ȵĵ�һ��Ԫ�صĺ���Ѿ������ͷ�ڵ�
	Back = Pointer;//pointer�ǵ�һ��Ԫ�أ���˴�ʱBack����˵�һ��Ԫ��
	Pointer = Next;//��ΪNext�Ѿ��ǵڶ���Ԫ���ˣ���˴�ʱpointerָ���˵ڶ���Ԫ��

	//��57�У�next�����ԭ�ȵĵڶ���Ԫ�أ�����Ϊ57-61�У�û���ٶ�Next��pnext��
	//���в��������ԭ�������еĺ����Ϣû���ƻ�
	//58�У�pointer��Ϊ��ǰԪ��ָ����ԭ�ȵ�ǰ�̽ڵ��ʱ�򣬴�ʱ��ǰԪ�ذ�ԭ�ȵ�ǰ��Ԫ��
	//����˺�̽ڵ�
	//60�У��ٽ�Back��Ϊ��ǰԪ�أ�61�н�Pointer��Ϊ��һ��Ԫ��

	while (Pointer->pNext != NULL)
	{
		Next = Pointer->pNext;
		Pointer->pNext = Back;
							  
		Back = Pointer;
		Pointer = Next;
	}

	Pointer->pNext = Back;
	//��ʱPointer�Ѿ���ԭ�������е����һ��Ԫ����
	//��˱���Ҫ��Pointer��ԭ�ȵ�ǰ�̽ڵ���ϵ����
	//��ԭ�ȵ�ǰ�̽ڵ�һ����back��

	//��ʱ��ת��ϣ���Ҫ��������ͷ�ڵ�
	//ԭ�ȵ�pHeadû�б䣬���ԭ�ȵ�pHead->pNextָ��ԭ�ȵĵ�һ��Ԫ��
	//����������ôҪ�����Ԫ�ص�pNext������Ϊ��
	pHead->pNext->pNext = NULL;
	//����pHeadû�б仯������������Ȼ������Ϊ��ת�������ͷ�ڵ�
	//���Խ���ǰ����Ԫ�ط�������pnext����
	pHead->pNext = Pointer;

	return pHead;

}

int main(void)
{
	LinkListNode* pHead = NULL;
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	pHead = Create_Rear_LkList(arr, 10);
	printf("\n*********************��ǰ��Ԫ����\n");
	ShowLkList(pHead);

	pHead = ReverseLkList(pHead);
	printf("\n*********************��ǰ��Ԫ����\n");
	ShowLkList(pHead);
	getchar();
	return 0;
}