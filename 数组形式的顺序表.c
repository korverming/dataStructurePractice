#include "SeqList.h"
#include <malloc.h>
/*
1）	初始化：给线性表中的相关参数赋值
2）	求长度：求线性表中的元素的个数
3）	取元素：取给定位置的元素值
4）	查元素：查找给定元素值的位置
5）	插入元素：在指定的位置插入给定的值
6）	删除：删除指定位置的值或者是删除给定的值。
7）	遍历元素：从头到尾扫描线性表。
*/

//实现初始化
SequenList* InitSeq()
{
	SequenList* pList = NULL;
	pList = (SequenList*)malloc(sizeof(SequenList));
	if (pList != NULL)
	{
		pList->last = 0;//初始化成功，且长度为0
	}
	return pList;
}

//求长度：求线性表中的元素的个数
int GetSizeSeq(SequenList* pList)
{
	return pList->last;
}

//取元素：取给定位置的元素值
//pList:目标的顺序表 pos:获取元素的下标 e:将元素值放入
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

	//说明此时pos在0-n之间
	*e = pList->data[pos];
	return TRUE;

}

//查元素：查找给定元素值的位置
//相同值只取第一个
//返回值:-1表示没找到，否则返回待查找元素的下标
//pList:传入的数组顺序表 Key:比对的值
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

//插入元素：在指定的位置插入给定的值
//插入的位置为k:0---n-1
//顺序表:不满
//pList:目标顺序表   x：待插入元素   k：插入位置
int InsertElemSqList(SequenList* pList, ElemType x, int k)
{
	int j;
	//顺序表是否填满
	if (pList->last >= LIST_SIZE - 1)
		return FALSE;
	//k是否有效位置
	if (k < 0 || k >(pList->last + 1))// k 可以等于last
		return FALSE;

	for (j = pList->last; j >= k; j--)
	{
		pList->data[j + 1] = pList->data[j];
	}
	pList->data[k] = x;

	pList->last = pList->last + 1;

	return TRUE;
}

//删除：删除指定位置的值或者是删除给定的值。
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

//遍历元素：从头到尾扫描线性表
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
		//todo:继续使用
		for (int i = 0; i < 10; i++)
		{
			InsertElemSqList(lPtr, i, i);
		}
		printf("初始化后顺序表的元素个数：%d\n", GetSizeSeq(lPtr));
		printf("********************\n");
		showSeqList(lPtr);
		InsertElemSqList(lPtr, 2000, 0);
		printf("初始化后顺序表的元素个数：%d\n", GetSizeSeq(lPtr));
		printf("*******************\n");
		showSeqList(lPtr);
		DelElemSqList(lPtr, 1);
		printf("初始化后顺序表的元素个数：%d\n", GetSizeSeq(lPtr));
		printf("*******************\n");
		showSeqList(lPtr);
		int pos = LocateElemSqList(lPtr, 16);
		if (pos >= 0)
		{
			printf("当前元素位于%d\n", pos);
		}
		else
		{
			printf("没有找到这个元素\n");
		}
		printf("*******************\n");
		showSeqList(lPtr);
		

	}
	else
	{
		//todo:提示没有可使用空间
		printf("no available memory\n");
	}
	getchar();
	return 0;
}