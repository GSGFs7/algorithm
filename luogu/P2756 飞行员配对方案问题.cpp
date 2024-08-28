#include <cstring>
#include <iostream>
#include <queue>

/*
  给出m和n-m个人, 需要两两一组组队, 给出哪两个人可以组队, 问组队最多的情况

  思路:
    最大流跑二分图
    对于一半的人直接从起点连一条有向边, 另一半人连一条边到终点, 这样整个图就被划分成了两半
    如果一个人可以跟另一个人组队就连一条有向边到那个点
    然后开始跑最大流, 最大流会自行处理可行的最大流通方案, 最后直接输出有流量经过的边就可以了
*/

using namespace std;
const int N = 2e5 + 10;// ??????
// 数据输入有坑, 没有确切说明上限, 可能存在很多条边 (但是为什么是cin的那行报错, de了两天...)

struct Edge {
    int u, v, w, next;
} e[N];
int cnt = 1;
int head[N];
int d[N];
int cur[N];
int S = 450, T = 452;    // 起点和终点

// 额外存储了入点的前向星
void add(int u, int v, int w) {
    // e[++cnt] = {u, v, w, head[u]};
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

bool BFS() {
    memset(&d, 0, sizeof d);

    queue<int> q;
    q.push(S);
    d[S] = 1;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (d[v] == 0 && w) {
                d[v] = d[u] + 1;
                q.push(v);

                if (v == T) return true;
            }
        }
    }
    return false;
}

int DFS(int u, int mf) {
    if (u == T) return mf;

    int sum = 0;
    for (int i = cur[u]; i; i = e[i].next) {
        cur[u] = i;
        int v = e[i].v;
        int w = e[i].w;
        if (d[v] == d[u] + 1 && w) {
            int f = DFS(v, min(mf, w));

            e[i].w -= f;
            e[i ^ 1].w += f;
            mf -= f;
            sum += f;
            if (mf == 0) break;
        }
    }

    if (sum == 0) d[u] = 0;
    return sum;
}

int dinic() {
    int flow = 0;
    while (BFS()) {
        memcpy(&cur, &head, sizeof head);
        flow += DFS(S, 1e9);
    }
    return flow;
}

void solve() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        if (i <= m) {
            add(S, i, 1);
            add(i, S, 0);
        } else {
            add(i, T, 1);
            add(T, i, 0);
        }
    }

    while (true) {
        int u, v;
        cin >> u >> v;

        if (u == -1 || v == -1) break;
        add(u, v, 1);
        add(v, u, 0);
    }

    cout << dinic() << '\n';
    for (int i = 2; i <= cnt; i += 2) {                     // 只搜存在的正向边
        if (e[i].w == 0 && e[i].u != S && e[i].v != T) {    // 如果这条边有流量
            cout << e[i].u << ' ' << e[i].v << '\n';
        }
    }
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


// https://www.luogu.com.cn/problem/P2756
// 5ms一个点, 跑的飞快