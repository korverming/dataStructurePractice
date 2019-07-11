#pragma once
#include <stdio.h>
#include <stdlib.h>

//假定处理的是一位数，没有括号
#define stackSize 100

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef int ElemType;//元素类型

typedef struct
{
	ElemType stack[stackSize];
	int top;//栈顶指针
} SeqStack;

///栈的初始化
BOOL init(SeqStack* pStack);

///栈的判空
BOOL isEmpty(SeqStack* pStack);

///压栈
///返回值为1表示成功，-1表示失败
///pStack表示顺序栈，x表示压入的元素
BOOL pushStack(SeqStack* pStack, ElemType x);

///出栈
ElemType popStack(SeqStack* pStack);

///获取栈顶元素
///如果栈为空，返回取值不成功，否则直接取出栈顶元素供用户使用
BOOL GetSeqStack(SeqStack* s, ElemType* data);

//判断是否是运算符,如果是运算符，返回true，否则返回false
BOOL Is_Operator(char oper);

//判断优先级： x/ 为2，+，-为1，
int Priority(char oper);

//计算数值:不考虑浮点数，也不考虑除数为0
int two_res(int oper, int opand1, int opand2);