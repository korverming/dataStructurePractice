//˼�룺����������Ҫ��Ƶ�ҵ���У�����Щ�����������Ѿ�ѧ�������ݽṹ
//���п̻�������Щҵ�����⣬������ݽṹ����֯����
#include <stdio.h>

int main(void)
{
	int n = 50;
	int queue[42] = { 0, 1, 1, 0 };//0�ǻ���
	int front = 1, rear = 4;//���Ƚ�������ǵĵ�һ������
	for (int i = 0; i < n; i++)
	{
		//����ͷ������Ԫ�غͲ���rearλ��
		queue[rear] = queue[front - 1] + queue[front];
		printf("%d ", queue[rear]);
		//׼������Ԫ�ص�λ��
		rear++;
		if (queue[front] == 0)
		{
			//����µķָ�
			queue[rear] = 0;
			rear++;
			printf("\n");
		}

		front++;
	}

	getchar();
	return 0;
}
//front�Ǽ���Ҫ��������ݣ�rear����ӵ�����