#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

/*
  
*/

using ll = long long;

const int N = 1e5 + 10, M = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int a[N];
int md[10];

struct Dinic {
    int n, s, t, tot = 1, mincost;
    int ver[M], edge[M], cost[M], nex[M], head[N], cur[N], dist[N], vis[N];
    ll maxflow;

    void init(int n, int s, int t) {
        this->n = n;
        this->s = s;
        this->t = t;
    }

    void add(int x, int y, int z, int c) {
        ver[++tot] = y;
        edge[tot] = z;    // 剩余流量
        cost[tot] = c;    // 费用
        nex[tot] = head[x];
        head[x] = tot;
        // 正反两条边
        ver[++tot] = x;
        edge[tot] = 0;
        cost[tot] = -c;
        nex[tot] = head[y];
        head[y] = tot;
    }

    // spfa判环
    bool spfa() {
        for (int i = 1; i <= t; i++) dist[i] = INF, vis[i] = 0;

        queue<int> q;
        q.push(s);
        dist[s] = 0;
        vis[s] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            vis[x] = 0;
            for (int i = head[x]; i; i = nex[i]) {
                int y = ver[i];
                int z = edge[i], c = cost[i];
                if (dist[y] <= dist[x] + c || !z) continue;
                dist[y] = dist[x] + c;
                if (!vis[y]) q.push(y), vis[y] = 1;
            }
        }
        // cout << dist[t] << endl;
        return dist[t] != INF;
    }

    ll dfs(int x, int flow) {
        if (x == t) return flow;

        ll ans = 0;
        vis[x] = 1;
        for (int i = cur[x]; i && flow; i = nex[i]) {
            int y = ver[i];
            int z = edge[i], c = cost[i];
            if (!z || dist[y] != dist[x] + c || vis[y]) continue;
            int k = dfs(y, min(flow, z));
            if (!k) dist[y] = INF;
            edge[i] -= k;
            edge[i ^ 1] += k;
            ans += k, mincost += k * c, flow -= k;
        }
        vis[x] = 0;
        return ans;
    }

    ll dinic() {
        while (spfa()) {
            for (int i = 1; i <= t; i++) cur[i] = head[i];
            ll now;
            while ((now = dfs(s, INF))) maxflow += now;
            // cout << maxflow << ' ' << mincost << '\n';
        }
        return mincost;
    }
} Dic;

void solve() {
    int n;
    cin >> n;
    Dic.init(n * 3 + 3, n * 3 + 1, n * 3 + 3);
    Dic.add(3 * n + 1, 3 * n + 2, 4, 0);
    for (int i = 1; i <= n; i++) {
        Dic.add(3 * n + 2, i, 1, 0);
        Dic.add(i, n + i, 1, -1);
        Dic.add(n + i, 2 * n + i, 1, 0);
        Dic.add(2 * n + i, 3 * n + 3, 1, 0);
        Dic.add(i, 2 * n + i, INF, 0);
    }
    for (int i = 1; i <= n; i++) {
        int e;
        cin >> e;
        if (a[e - 1]) Dic.add(a[e - 1], i, INF, 0);
        if (a[e + 1]) Dic.add(a[e + 1], i, INF, 0);
        if (md[e % 7]) Dic.add(md[e % 7], i, INF, 0);
        a[e] = n * 2 + i;
        md[e % 7] = n * 2 + i;
    }
    cout << -Dic.dinic() << '\n';
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


// https://codeforces.com/contest/818/problem/G
// 2024-09-12