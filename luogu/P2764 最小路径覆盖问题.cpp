#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

/*
  给出一个有向图, 需要使图中每个点都有路径覆盖, 求最小的路径数量

  思路:
    二分图的最大流
    对于路径而言, 每个点最多只能存在两条边, 一个入度和一个出度(只会被匹配这两次)
    直接拆点, 每个点拆成两部分, 一部分和超级起点相连(出度), 一部分和超级终点相连(入度)
    将拆出来的点看成不同的点, 这样就组成了一个二分图, 直接最大流跑二分图求出二分图的最大匹配
    这个最大匹配就是图中路径可行的最大边数, 问题又来了, 边数有什么用
    对于一条路径, 边数等于点数减一, 如果少了几条边也就说明, 肯定不只一条路径
    那么就可以知道:  路径=总点数-边数
    所以只要找出二分图的最大匹配就能求出最小的路径数量
    那么就到了最难的部分了, 如何求得路径?
    类似重链剖分的思想, 把所有的"重儿子"都做一个标记, 标记这个点不是起点
    然后遍历每个点, 如果是起点就从这里开始拉表, 输出路径
    Q: 为什么是对的, 不会被覆盖?
*/

const int N = 1e5 + 10;
int s = 1000, t = 1100;
int d[N];
int cur[N];
int net[N];    // 路径记录
bool vis[N];
bool inQueue[N];    // ???不加这个RE??? https://www.luogu.com.cn/record/156786908
int n, m;           // 加了的 https://www.luogu.com.cn/record/156786886

struct Edge {
    int to, w, next;
} e[N << 2];    // 开两倍不够
int head[N];
int tot = 1;

void add(int u, int v, int w) {
    e[++tot] = {v, w, head[u]};
    head[u] = tot;
}

bool bfs() {
    memset(&d, 0, sizeof d);

    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            int w = e[i].w;
            // if (d[v] == 0 && w) {
            if (!d[v] && w) {
                d[v] = d[u] + 1;
                q.push(v);
                if (v == t) return true;
            }
        }
    }
    return false;
}

int dfs(int u, int mf) {    // EK, 只找一条路径
    if (u == t) return mf;

    for (int i = head[u]; i; i = e[i].next) {
        cur[u] = i;
        int v = e[i].to;
        int w = e[i].w;
        if (d[v] == d[u] + 1 && w) {    // ==少个=卡了好久
            int f = dfs(v, min(mf, w));
            if (f) {    // 如果可以走这条路
                e[i].w -= f;
                e[i ^ 1].w += f;

                net[u] = v;           // 记录下一个点
                vis[v - n] = true;    // 标记这个点不是起点, 别忘了还有个n
                return f;
            }
        }
    }
    return 0;
}

int EK() {
    int flow = 0;
    while (bfs()) {
        // cout << "BFS_OK!\n";
        memcpy(&cur, &head, sizeof head);
        flow += dfs(s, 1e9);
    }
    return flow;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {    // 建立二分图, 每个点都可以是起点和终点
        add(s, i, 1);
        add(i, s, 0);
        add(i + n, t, 1);    // 另一边要当成另一个点处理
        add(t, i + n, 0);
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        add(u, v + n, 1);    // 靠近超级终点的那一边才要再加上n
        add(v + n, u, 0);
    }

    // for (int u = 1; u < 12; u++) {
    //     cout << u << ":\n";
    //     for (int i = head[u]; i; i = e[i].next) {
    //         cout << e[i].to << ' ' << e[i].w << ' ' << e[i].next << '\n';
    //     }
    // }
    // cout << s << ":\n";
    // for (int i = head[s]; i; i = e[i].next) {
    //     cout << e[i].to << ' ' << e[i].w << ' ' << e[i].next << '\n';
    // }
    // cout << t << ":\n";
    // for (int i = head[t]; i; i = e[i].next) {
    //     cout << e[i].to << ' ' << e[i].w << ' ' << e[i].next << '\n';
    // }

    int ans = EK();

    // 输出部分
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int u = i;
            cout << i << ' ';
            while (net[u] != t && net[u] != 0) {
                cout << net[u] - n << ' ', u = net[u] - n;
            }
            cout << '\n';
        }
    }
    cout << n - ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P2764
// 2024年4月24日