#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int a[N];

void quick_sort(int a[], int l, int r)//l为中间任意值
{
	if (l >= r) return;						//如果只有一个数，则不用排列
	int x = a[l];								//分割线的值
	int i = l - 1;								//起始位置
	int j = r + 1;								//数组内数的个数
	while (i < j)								//设定两个指针，左右分别靠拢
	{
		do i++; while (a[i] < x);		//找到一个大于x的数
		do j--; while (a[j] > x);			//找到一个小于x的数
		if (i < j)swap(a[i], a[j]);			//交换
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