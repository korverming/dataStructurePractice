//思想：看看我们需要设计的业务中，有哪些可以用我们已经学过的数据结构
//进行刻画，将这些业务问题，变成数据结构的组织问题
#include <stdio.h>

int main(void)
{
	int n = 50;
	int queue[42] = { 0, 1, 1, 0 };//0是换行
	int front = 1, rear = 4;//首先将杨辉三角的第一行输入
	for (int i = 0; i < n; i++)
	{
		//将队头的两个元素和插入rear位置
		queue[rear] = queue[front - 1] + queue[front];
		printf("%d ", queue[rear]);
		//准备好新元素的位置
		rear++;
		if (queue[front] == 0)
		{
			//添加新的分割
			queue[rear] = 0;
			rear++;
			printf("\n");
		}

		front++;
	}

	getchar();
	return 0;
}
//front是即将要处理的数据，rear是添加的数据