#include "SeqList.h"
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

//ʵ�ֳ�ʼ��
SequenList* InitSeq()
{
	SequenList* pList = NULL;
	pList = (SequenList*)malloc(sizeof(SequenList));
	if (pList != NULL)
	{
		pList->last = 0;//��ʼ���ɹ����ҳ���Ϊ0
	}
	return pList;
}

//�󳤶ȣ������Ա��е�Ԫ�صĸ���
int GetSizeSeq(SequenList* pList)
{
	return pList->last;
}

//ȡԪ�أ�ȡ����λ�õ�Ԫ��ֵ
//pList:Ŀ���˳��� pos:��ȡԪ�ص��±� e:��Ԫ��ֵ����
int GetElemSqList(SequenList* pList, int pos, ElemType* e)
{
	if (pos < 0 || pos > pList->last)
	{
		return FALSE;
	}

	if (pList->last <= 0)
	{
		return FALSE;
	}

	//˵����ʱpos��0-n֮��
	*e = pList->data[pos];
	return TRUE;

}

//��Ԫ�أ����Ҹ���Ԫ��ֵ��λ��
//��ֵֻͬȡ��һ��
//����ֵ:-1��ʾû�ҵ������򷵻ش�����Ԫ�ص��±�
//pList:���������˳��� Key:�ȶԵ�ֵ
int LocateElemSqList(SequenList* pList, ElemType key)
{
	int i;
	for (i = 0; i < pList->last; i++)
	{
		if (pList->data[i] == key)
		{
			return i;
		}
	}

	return -1;
}

//����Ԫ�أ���ָ����λ�ò��������ֵ
//�����λ��Ϊk:0---n-1
//˳���:����
//pList:Ŀ��˳���   x��������Ԫ��   k������λ��
int InsertElemSqList(SequenList* pList, ElemType x, int k)
{
	int j;
	//˳����Ƿ�����
	if (pList->last >= LIST_SIZE - 1)
		return FALSE;
	//k�Ƿ���Чλ��
	if (k < 0 || k >(pList->last + 1))// k ���Ե���last
		return FALSE;

	for (j = pList->last; j >= k; j--)
	{
		pList->data[j + 1] = pList->data[j];
	}
	pList->data[k] = x;

	pList->last = pList->last + 1;

	return TRUE;
}

//ɾ����ɾ��ָ��λ�õ�ֵ������ɾ��������ֵ��
int DelElemSqList(SequenList* pList, int k)
{
	if ((k >= 0 && k <= pList->last) && (pList->last != 0))
	{
		for (int j = k; j <= pList->last; j++)
		{
			pList->data[j] = pList->data[j + 1];
		}
		pList->last--;
		return TRUE;
	}

	return FALSE;
}

//����Ԫ�أ���ͷ��βɨ�����Ա�
void showSeqList(SequenList* pList)
{
	for (int i = 0; i < pList->last; i++)
	{
		printf(" %d", pList->data[i]);
	}

}

int main1(void)
{
	lPtr = InitSeq();
	if (lPtr)
	{
		//todo:����ʹ��
		for (int i = 0; i < 10; i++)
		{
			InsertElemSqList(lPtr, i, i);
		}
		printf("��ʼ����˳����Ԫ�ظ�����%d\n", GetSizeSeq(lPtr));
		printf("********************\n");
		showSeqList(lPtr);
		InsertElemSqList(lPtr, 2000, 0);
		printf("��ʼ����˳����Ԫ�ظ�����%d\n", GetSizeSeq(lPtr));
		printf("*******************\n");
		showSeqList(lPtr);
		DelElemSqList(lPtr, 1);
		printf("��ʼ����˳����Ԫ�ظ�����%d\n", GetSizeSeq(lPtr));
		printf("*******************\n");
		showSeqList(lPtr);
		int pos = LocateElemSqList(lPtr, 16);
		if (pos >= 0)
		{
			printf("��ǰԪ��λ��%d\n", pos);
		}
		else
		{
			printf("û���ҵ����Ԫ��\n");
		}
		printf("*******************\n");
		showSeqList(lPtr);
		

	}
	else
	{
		//todo:��ʾû�п�ʹ�ÿռ�
		printf("no available memory\n");
	}
	getchar();
	return 0;
}