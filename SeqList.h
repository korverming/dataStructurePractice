#pragma once
#include <stdio.h>
typedef int ElemType;//假定线性表的元素类型为整型
#define LIST_SIZE 1024//假定线性表长度是1024
#define TRUE 1
#define FALSE 0

typedef struct
{
	ElemType data[LIST_SIZE];
	int last;//指向最后一个节点的位置
} SequenList;
//last存在的目的：为了在函数调用的时候传递数据方便，因为我们预
//分配的空间中并不是立即存满的

SequenList* lPtr;

///数组顺序表的实现初始化
///获得一个长度为0的数组
SequenList* InitSeq();

///求长度：求线性表中的元素的个数
///获得当前数组顺序表的元素个数， pList：顺序表的起始地址
int GetSizeSeq(SequenList* pList);

///取元素：取给定位置的元素值
///pList:目标的顺序表 pos:获取元素的下标 e:将元素值放入
int GetElemSqList(SequenList* pList, int pos, ElemType* e);

///查元素：查找给定元素值的位置
///相同值只取第一个
///返回值:-1表示没找到，否则返回待查找元素的下标
///pList:传入的数组顺序表 Key:比对的值
int LocateElemSqList(SequenList* pList, ElemType key);

//插入元素：在指定的位置插入给定的值
//插入的位置为k:0---n-1
//pList:目标顺序表   x：待插入元素   k：插入位置
int InsertElemSqList(SequenList* pList, ElemType x, int k);

///删除：删除指定位置的值或者是删除给定的值。
///pList:目标顺序数组， k表示需要删除的位置
int DelElemSqList(SequenList* pList, int k);

//遍历元素：从头到尾扫描线性表
///pList:目标顺序数组
void showSeqList(SequenList* pList);
