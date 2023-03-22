#include <iostream>
using namespace std;

/*
解此题必须画图，推出计算下一个前缀和的公式
*/

const int N = 1010;
int a[N][N], s[N][N];
int n, m, q;

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];//由矩形关系，计算前缀和
		}
	}
	while (q--)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]));//还原特定部分的前缀和
	}
	return 0;
}