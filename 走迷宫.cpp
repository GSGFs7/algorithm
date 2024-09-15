#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N];// 迷宫
int d[N][N];// 判重
PII q[N*N], Prev[N][N];// 模拟队列

int bfs()
{
    int hh = 0, tt = 0;// 手搓队列
    q[0] = {0, 0};

    // 初始化
    memset(d, -1, sizeof d);
    d[0][0] = 0;// 起点

    int const dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};// 向量表示

    while (hh <= tt)// 如果不为空
    {
        auto t = q[hh++];// 取出队头

        for (int i = 0; i < 4; i++)// 查询上下左右四个方向
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)// 在边界内，没走过，可以走
            {
                d[x][y] = d[t.first][t.second] + 1;
                Prev[x][y] = t;
                q[++tt] = {x, y};
            }
        }
    }

    // 输出路径
    // 从下往上看
    int x = n - 1, y = m - 1;
    while (x || y)
    {
        cout << x << " " << y << endl;
        auto t = Prev[x][y];
        x = t.first, y = t.second;
    }

    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];// 存入迷宫

    cout << bfs() << endl;
    return 0;
}

// https://www.acwing.com/problem/content/846/
// BFS最短路