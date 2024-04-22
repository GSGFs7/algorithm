#include <cstring>
#include <iostream>
#include <queue>

/*
  给出一个图, 求从起点到每个点一次后返回, 所花费的距离的最小值

  思路:
    抵达每个点后立马返回, 最容易的做法就是每到一个点就对这个点跑一次最短路
    模拟的思想, 但是复杂度爆炸, O(nmlogm)
    上面的n次dijkstra也可以用Floyd实现, 但复杂度依旧爆炸, O(n^3)
    但是经过简单的抽象就可以发现(不考虑路径, 直接压缩成一整条边, 把多余的边全删掉, 只考虑点的距离)
    向外走的边都是有一条边连向起点, 直接由正向图跑一边dij就可以得到所有的距离
    往回走的边都是有一条反向边连向起点(反过来看), 直接在反向的图上跑dij就可以得到所有点返回的距离
    一来一回刚好就是到每个点的距离再加上返回的距离
    最终的复杂度只有两个dij
*/

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
bool vis[N];
int dis[N];

struct Edge {
    int to, w, next;
} e[N << 1];    // 同时存正向和反向, 需要两倍的空间
int head[N << 1];
int tot = 0;

void add(int u, int v, int w) {
    e[++tot] = {v, w, head[u]};
    head[u] = tot;
}

void dijkstra(int s) {
    priority_queue<PII> pq;
    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top();    // 距离小的边优先
        pq.pop();

        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            int w = e[i].w;
            if (dis[v] > dis[u] + w) {
                pq.push({-w, v});
                dis[v] = dis[u] + w;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v + n, u + n, w);    // 反向边
    }

    int ans = 0;
    memset(&dis, 0x3f, sizeof dis);
    dijkstra(1);    // 正向
    for (int i = 1; i <= n; i++) ans += dis[i];

    dijkstra(n + 1);    // 反向
    for (int i = n + 1; i <= n + n; i++) ans += dis[i];

    // 所有边相加刚好就是往返的距离
    cout << ans << '\n';
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


// https://www.luogu.com.cn/problem/P1629
// 2024年4月21日