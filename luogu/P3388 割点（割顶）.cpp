#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 割点
 * 对于一个无向图，如果删掉一个点使图中的级大连通分量增加了，那么这个点就是图的割点（也称割顶）
 *
 * 使用Tarjan算法来实现
 * dfn数组，用于存储dfs遍历的时间戳
 * low数组，用于看这个点不经过父节点能抵达的最早的点（判断是否通向自己的祖宗节点）
 *
 * 对于每个点进行判断：如果这个点不连接他的父节点不能抵达更早的地方，也就是说没有其他路径能通向父节点
 * 那么就没有和自己的父节点成环，删除这个点图中就会分出一个连通块，这个点就是割点
 * */

const int N = 2e5;
vector<int> v[N];
int dfn[N];// 时间戳
int low[N];// 低点
int id = 0;
bool flag[N];// 是否是割点
int res = 0;

void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++ id;// Tarjan的时间戳
    int child = 0;// 子连通块

    for (auto i : v[u])// 遍历自己的子节点
    {
        if (!dfn[i])
        {
            // 关于child，这个点的child间是不能成环的，因为如果成环DFS会抢先访问其他的child
            // 所以child就直接是不成环的子连通块
            child ++;
            dfs(i, u);
            low[u] = min(low[u], low[i]);// 如果自己的子节点通向前面的点，更新能抵达的最早的点

            // 判割点的核心代码
            // 简单说就是：删掉父节点后就没有路径返回更早的节点了
            if (fa != u && low[i] >= dfn[u] && !flag[u])
            {
                flag[u] = true;
                res ++;
            }
        }
        else if (i != fa)
            low[u] = min(low[u], dfn[i]);// 如果指向前面的点，更新自己
    }

    if (fa == u && child >= 2 && !flag[u])// 如果搜索的这个点正好就是个割点
    {
        flag[u] = true;
        res ++;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);// 双向图
        v[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)// 原图可能不相连
    {
        if (!dfn[i])
            dfs(i, i);
    }

    cout << res << '\n';
    for (int i = 1; i <= n; i++)
        if (flag[i]) cout << i << ' ';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
    return 0;
}


// https://www.luogu.com.cn/problem/P3388