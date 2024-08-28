// n皇后问题
// 可以横竖斜走
// DFS搜索
#include <iostream>
using namespace std;

// 首先看第一行皇后可以放在那一列，然后进行全排列（注意剪枝）

const int N = 20;
int n;
char g[N][N];// 存图
bool col[N], dg[N], udg[N];// 同一列，正对角线，反对角线

void dfs(int u)
{
    if (u == n)// 成功搜到底时输出
    {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // 这一列没有放过皇后&&对角线上也没有&&反对角线上也没有
        if (!col[i] && !dg[u + i] && !udg[n - u + i])// 正对角线从左上角开始，反对角线从右上角开始
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';// 复原
        }
    }
}

int main()
{
    cin >> n;

    // 初始化
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}


// https://www.acwing.com/problem/content/845/

// 一种原始方式 O((2^n)^2)
/*
#include <iostream>
using namespace std;

const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N], row[N];

void dfs(int x, int y, int s)
{
    if (y == n) y = 0, x++; // 如果出界，转向下一行

    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++) puts(g[i]);
            puts("");
        }
        return;
    }

    // 不放
    dfs(x, y+1, s);

    // 放
    if (!row[x] && !col[y] && !dg[x+y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y+1, s+1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0, 0, 0);
    return 0;
}
 */