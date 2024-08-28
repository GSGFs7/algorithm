#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
 * 数据范围足够小最大点数仅有1500
 * 可以直接BFS暴力解题
 * 更新一个点后就加入队列继续更新其他点
 * 等所有点更新完成后即为最终值
 * 类似dijkstra
 * */

typedef pair<int, int> PII;
const int N = 1510;
int n, m;
int g[N][N], d[N];

/// BFS
void bfs()
{
	memset(&d, -1, sizeof d);
	d[1] = 0;
	queue<int> q;
	q.push(1);

	while (!q.empty())// BFS队列循环
	{
		int const x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (g[x][i] && d[i] < d[x] + g[x][i]) {
				d[i] = d[x] + g[x][i];
				q.push(i);
			}
		}
	}
}

int main()
{
	//freopen("P1807_3.in", "r", stdin);
	//freopen("P1807_3", "w", stdout);

	cin >> n >> m;
	for (int i = 0, x, y, w; i < m; i++)
	{
		cin >> x >> y >> w;
		g[x][y] = max(g[x][y], w);// 邻接矩阵存图
	}
	bfs();
	cout << d[n] << endl;
	return 0;
}

// https://www.luogu.com.cn/problem/P1807
