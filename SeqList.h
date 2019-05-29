#pragma once
#include <stdio.h>
typedef int ElemType;//�ٶ����Ա��Ԫ������Ϊ����
#define LIST_SIZE 1024//�ٶ����Ա�����1024
#define TRUE 1
#define FALSE 0

typedef struct
{
	ElemType data[LIST_SIZE];
	int last;//ָ�����һ���ڵ��λ��
} SequenList;
//last���ڵ�Ŀ�ģ�Ϊ���ں������õ�ʱ�򴫵����ݷ��㣬��Ϊ����Ԥ
//����Ŀռ��в���������������

SequenList* lPtr;

///����˳����ʵ�ֳ�ʼ��
///���һ������Ϊ0������
SequenList* InitSeq();

///�󳤶ȣ������Ա��е�Ԫ�صĸ���
///��õ�ǰ����˳����Ԫ�ظ����� pList��˳������ʼ��ַ
int GetSizeSeq(SequenList* pList);

///ȡԪ�أ�ȡ����λ�õ�Ԫ��ֵ
///pList:Ŀ���˳��� pos:��ȡԪ�ص��±� e:��Ԫ��ֵ����
int GetElemSqList(SequenList* pList, int pos, ElemType* e);

///��Ԫ�أ����Ҹ���Ԫ��ֵ��λ��
///��ֵֻͬȡ��һ��
///����ֵ:-1��ʾû�ҵ������򷵻ش�����Ԫ�ص��±�
///pList:���������˳��� Key:�ȶԵ�ֵ
int LocateElemSqList(SequenList* pList, ElemType key);

//����Ԫ�أ���ָ����λ�ò��������ֵ
//�����λ��Ϊk:0---n-1
//pList:Ŀ��˳���   x��������Ԫ��   k������λ��
int InsertElemSqList(SequenList* pList, ElemType x, int k);

///ɾ����ɾ��ָ��λ�õ�ֵ������ɾ��������ֵ��
///pList:Ŀ��˳�����飬 k��ʾ��Ҫɾ����λ��
int DelElemSqList(SequenList* pList, int k);

//����Ԫ�أ���ͷ��βɨ�����Ա�
///pList:Ŀ��˳������
void showSeqList(SequenList* pList);
