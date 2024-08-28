// 拓扑序列
// 有向图
// 起点对应的数大于终点对应的数（无环）
// 有向无环图一定存在拓扑序列
// 入度：指向该点的个数
// 出度：该点指向下一个点的个数
//
// 1 -> 2 -> 3
// |---------^
//
//    入度 出度
// 1   0   2
// 2   1   1
// 3   2   0
// /
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;
    while (hh <= tt)
    {
        int  t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j] --;
            if (d[j] == 0) q[++tt] = j;
        }
    }
    return tt == n - 1;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if (topsort())
    {
        for (int i = 0; i < n; i++) printf("%d ", q[i]);
        puts("");
    }
    else puts("-1");
    return 0;
}