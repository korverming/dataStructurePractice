#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int num;
	float score;
} node;

//��������������50
#define LIST_SIZE 50

#define TRUE 1
#define FALSE 0

//����˳���Ľṹ
typedef struct
{
	node data[LIST_SIZE];
	int last;//���һ���ڵ��λ��
} SeqList;

//��ȡ�༶����
int GetSize(SeqList* pList)
{
	return pList->last;
}

//�������ȫ��ѧ����Ϣ
void ShowSeqList(SeqList* pList)
{
	for (int i = 0; i < pList->last; i++)
	{
		printf("ѧ����ѧ����%d,�ɼ���%f\n", pList->data[i].num, pList->data[i].score);
	}
}

//��ʼ��
static SeqList* InitSeq()
{
	SeqList* pList = NULL;
	pList = (SeqList*)malloc(sizeof(SeqList));
	if (pList != NULL)
		pList->last = 0;

	return pList;
	//�ڷ����������У�������������ռ����������׳ɹ�
	//�������Ǿ������ڲ��ͽ����ж�pList�Ƿ�Ϊ��
}

//����Ԫ��
int InsertStuSeq(SeqList* pList, node* pNode, int k)
{
	int j;
	
	//if (pList->last >= LIST_SIZE - 1)
	//	return FALSE;
	//���߽�if����Ƶ�����֮�⣬��ҵ����Աά������
	//�������������������õĿ����ܴ���ô���ǻ�����ڲ�У��
	//�����������һ���԰�ȫҪ��ܸߵĳ����ڲ�У����Ȼ��Ҫ
	//���ȥ�����ڲ�У�飬��ʵ�ʵĹ�˾�����У�����team leader��code review

	//�ڱ����У����Ǽٶ������k������Чλ��
	//��Զ��Ҫ���ŵ����ߴ�������ݣ������ھ��忪���л���Ҫ��������������
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

//ʵ�ְ�ѧ�Ų��ҵĹ���
void DisplayStu(SeqList* pList, int stuNo)
{
	for (int i = 0; i < pList->last; i++)
	{
		if (pList->data[i].num == stuNo)
		{
			printf("��ѧ���ĳɼ���%f\n", pList->data[i].score);
			return;
		}
	}

	printf("��ѧ��������\n");
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