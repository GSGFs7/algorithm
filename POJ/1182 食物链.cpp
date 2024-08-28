#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 1e5 + 10;
int p[N];
int d[N];   // 0同类 1吃 2被吃
int ans = 0;

int find(int k)
{
    if (k != p[k])
    {
        int const t = p[k];         // 原本的父节点
        p[k] = find(p[k]);        // 路径压缩
        d[k] = (d[t] + d[k]) % 3;   // 更新到根节点的权值
    }
    return p[k];
}

void merge(int relation, int x, int y)
{
    int const rootx = find(x);
    int const rooty = find(y);
    if (rootx == rooty)                                         // 如果已经存在关系
    {
        if ((relation - 1) != (d[x] - d[y] + 3) % 3) ans ++;    // 相减可能得到负值
    }
    else
    {
        p[rootx] = p[rooty];                                        // 合并为同一个
        d[rootx] = (d[y] - d[x] + relation - 1) % 3;                // 更新权值
    }
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i, d[i] = 0;    // 初始化

    while (m--)
    {
        int relation, x, y;
        scanf("%d%d%d", &relation, &x, &y);// 会TLE
        if (x > n || y > n || (relation == 2 && x == y)) ans ++;
        else merge(relation, x, y);
    }
    cout << ans << '\n';
    return 0;
}


// http://poj.org/problem?id=1182