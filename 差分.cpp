#include <iostream>
using namespace std;

/*
��־���ǰ׺�͵�������
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
		b[i] = a[i] - a[i - 1];//�����������
	}
	int l, r, c;
	while (m--)
	{
		scanf("%d%d%d", &l, &r, &c);
		b[l] += c;//�����ÿһ�����c
		b[r + 1] -= c;//ȡ�������c
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = b[i] + a[i - 1];//��ԭǰ׺��
		printf("%d ", a[i]);
	}
	return 0;
}