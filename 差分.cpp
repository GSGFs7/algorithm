#include <iostream>
using namespace std;

/*
差分就是前缀和的逆运算
a[i] = a[i+1] - b[i]
*/

int main()
{
	const int N = 1e5 + 10;
	int n, m;
	int a[N], b[N];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i] - a[i - 1];//构建差分数组
	}
	int l, r, c;
	while (m--)
	{
		scanf("%d%d%d", &l, &r, &c);
		b[l] += c;//后面的每一项都会多加c
		b[r + 1] -= c;//取消加入的c
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = b[i] + a[i - 1];//还原前缀和
		printf("%d ", a[i]);
	}
	return 0;
}