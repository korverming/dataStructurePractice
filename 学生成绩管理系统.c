#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int num;
	float score;
} node;

//单班人数上限是50
#define LIST_SIZE 50

#define TRUE 1
#define FALSE 0

//定义顺序表的结构
typedef struct
{
	node data[LIST_SIZE];
	int last;//最后一个节点的位置
} SeqList;

//获取班级人数
int GetSize(SeqList* pList)
{
	return pList->last;
}

//便利输出全体学生信息
void ShowSeqList(SeqList* pList)
{
	for (int i = 0; i < pList->last; i++)
	{
		printf("学生的学号是%d,成绩是%f\n", pList->data[i].num, pList->data[i].score);
	}
}

//初始化
static SeqList* InitSeq()
{
	SeqList* pList = NULL;
	pList = (SeqList*)malloc(sizeof(SeqList));
	if (pList != NULL)
		pList->last = 0;

	return pList;
	//在服务器分配中，连续分配大量空间往往不容易成功
	//所以我们经常在内部就进行判断pList是否为空
}

//插入元素
int InsertStuSeq(SeqList* pList, node* pNode, int k)
{
	int j;
	
	//if (pList->last >= LIST_SIZE - 1)
	//	return FALSE;
	//或者将if语句移到函数之外，由业务人员维护插入
	//如果这个函数被反复调用的开销很大，那么我们会放弃内部校验
	//但是如果这是一个对安全要求很高的程序，内部校验依然需要
	//如果去掉了内部校验，在实际的公司开发中，会有team leader做code review

	//在本例中，我们假定传入的k就是有效位置
	//永远不要相信调用者传入的数据，但是在具体开发中还是要具体情况具体分析
	for (j = pList->last; j >= k; j--)
	{
		pList->data[j + 1].num = pList->data[j].num;
		pList->data[j + 1].score = pList->data[j].score;
	}

	pList->data[k].num = pNode->num;
	pList->data[k].score = pNode->score;
	pList->last++;

	return TRUE;

}
int DelSeqList(SeqList* pList, int k)
{
	if (k <= 0 || k > pList->last)
		return FALSE;

	if (pList->last == 0)
		return FALSE;
	for (int j = k; j <= pList->last; j++)
	{
		pList->data[j].num = pList->data[j + 1].num;
		pList->data[j].score = pList->data[j + 1].score;
	}

	pList->last--;
	return TRUE;
}

//实现按学号查找的功能
void DisplayStu(SeqList* pList, int stuNo)
{
	for (int i = 0; i < pList->last; i++)
	{
		if (pList->data[i].num == stuNo)
		{
			printf("该学生的成绩是%f\n", pList->data[i].score);
			return;
		}
	}

	printf("该学生不存在\n");
}

int main10()
{
	SeqList* stuList = InitSeq();
	node stu[2];
	stu[0].num = 1;
	stu[0].score = 99;
	stu[1].num = 2;
	stu[1].score = 100;

	if (stuList)
	{
		for (int i = 0; i < 2; i++)
		{
			InsertStuSeq(stuList, &stu[i], i);
		}
	}

	ShowSeqList(stuList);

	//DelSeqList(stuList, 1);
	//ShowSeqList(stuList);

	printf("\n**********************\n");
	DisplayStu(stuList, 1);
	system("Pause");
	return 0;
}