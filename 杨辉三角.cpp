#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	int a[20][20];//����Ϊ���20*20�Ķ�ά����
	scanf("%d", &n);
	//����ʼֵ��������������Ҷ�Ϊ1
	for (int i = 0; i < n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	//�������
	for (int i = 2; i < n; i++)//����i��ʾ��
	{
		for (int j = 1; j < i; j++)//����j��ʾi���еĵ�j+1��
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];//ÿ��������������һ��(i-1��)�����һ��(j-1)�����Ϸ����Ǹ�(j)
		}
	}
	//���ÿ��Ҫ�����
	for (int i = 0; i < n; i++)//���n��
		{
			for(int j=0;j<=i;j++)//���n��
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");//����
		}
	return 0;
}