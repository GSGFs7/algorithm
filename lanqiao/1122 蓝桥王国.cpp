#include <bits/stdc++.h>
#define int long long   // de了半个晚上加上这个就过了，想不通
using namespace std;

const int N = 3e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
bool st[N];         // 是否已经找到这个点的最短路
long long dist[N];  // 到原点的距离

struct edge {       // 图上的边，和图的节点是不一样的概念
    int from, to;
    long long dist;
    edge(int u, int v, int w) { from = u, to = v, dist = w; }
};
vector<edge> mp[N]; // 存边

struct node {       // 图上的节点
    int id;         // 节点编号
    long long dist;
    node(int u, int v) { id = u, dist = v; }
    // 定义这个结构体比较的方式
    bool operator < (const node & a) const { return a.dist < dist; }
};

void dijkstra()
{
    /* 初始化部分 */
    for (int i = 1; i <= n; i++) dist[i] = INF, st[i] = false;
    dist[1] = 0;

    priority_queue<node> q;
    q.emplace(1, 0);

    while (!q.empty())
    {
        auto now = q.top();
        q.pop();

        if (st[now.id]) continue;
        st[now.id] = true;

        for (auto i : mp[now.id])
        {
            if (st[i.to]) continue;

            if (dist[i.to] > dist[now.id] + i.dist)
            {
                dist[i.to] = dist[now.id] + i.dist;
                q.emplace(i.to, dist[i.to]);
            }
        }
    }
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a].emplace_back(a, b, c);
    }

    dijkstra();

    for (int i = 1; i <= n; i++)
        if (dist[i] >= INF) cout << "-1 ";
        else cout << dist[i] << ' ';
    return 0;
}


// https://www.lanqiao.cn/problems/1122/learning
// 算法竞赛给出的代码见 c/dijkstra算法.cpp