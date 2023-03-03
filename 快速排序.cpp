#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int a[N];

void quick_sort(int a[], int l, int r)//lΪ�м�����ֵ
{
	if (l >= r) return;						//���ֻ��һ��������������
	int x = a[l];								//�ָ��ߵ�ֵ
	int i = l - 1;								//��ʼλ��
	int j = r + 1;								//���������ĸ���
	while (i < j)								//�趨����ָ�룬���ҷֱ�£
	{
		do i++; while (a[i] < x);		//�ҵ�һ������x����
		do j--; while (a[j] > x);			//�ҵ�һ��С��x����
		if (i < j)swap(a[i], a[j]);			//����
	}
	quick_sort(a, l, j);
	quick_sort(a, j + 1, r);
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", a[i]);
	quick_sort(a, 0, n - 1);
	for (int i = 0; i < n; i++)printf("%d ", a[i]);
	return 0;
}