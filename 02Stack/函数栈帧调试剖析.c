#include <stdio.h>
//1+2+3+4+5...
//递归是我们程序设计入门的一个坎
//我们可以使用重复的力量，来解决这个问题
int sum = 0;
int FunGaosi(int value)
{
	if (value == 1)
		return 1;
	sum = value + FunGaosi(value - 1);

	return sum;
}

int main3(void)
{
	printf("%d\n", FunGaosi(4));
	getchar();
	return 0;
}

//call stack最基本的作用：
/*
就是告诉程序员，你现在停留的指令在什么位置，当你的函数返回时
你将在哪一个函数的指令继续推进你的程序
只有我们清楚的知道你的程序代码是如何推进，
你才找到你的程序怎么运行，
bug是程序没有按照我们预定的逻辑进行推进，那么我们必须知道
在哪里运行的路劲不正确
*/