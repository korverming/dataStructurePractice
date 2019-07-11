#pragma once
#include <stdio.h>
#include <stdlib.h>

//�ٶ��������һλ����û������
#define stackSize 100

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef int ElemType;//Ԫ������

typedef struct
{
	ElemType stack[stackSize];
	int top;//ջ��ָ��
} SeqStack;

///ջ�ĳ�ʼ��
BOOL init(SeqStack* pStack);

///ջ���п�
BOOL isEmpty(SeqStack* pStack);

///ѹջ
///����ֵΪ1��ʾ�ɹ���-1��ʾʧ��
///pStack��ʾ˳��ջ��x��ʾѹ���Ԫ��
BOOL pushStack(SeqStack* pStack, ElemType x);

///��ջ
ElemType popStack(SeqStack* pStack);

///��ȡջ��Ԫ��
///���ջΪ�գ�����ȡֵ���ɹ�������ֱ��ȡ��ջ��Ԫ�ع��û�ʹ��
BOOL GetSeqStack(SeqStack* s, ElemType* data);

//�ж��Ƿ��������,����������������true�����򷵻�false
BOOL Is_Operator(char oper);

//�ж����ȼ��� x/ Ϊ2��+��-Ϊ1��
int Priority(char oper);

//������ֵ:�����Ǹ�������Ҳ�����ǳ���Ϊ0
int two_res(int oper, int opand1, int opand2);