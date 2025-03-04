#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
int dis[N];
int dis1[N];

void solve() {
    fill(dis, dis + N, 1e9);
    fill(dis1, dis1 + N, 1e9);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // 转化a到超级起点
    int S = 1e5 + 7;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[S].push_back({i, a[i]});
        // g[i].push_back({S, a[i]});
        // dis1[g[i][0].first] = min(dis1[g[i][0].first], g[i][0].second + a[i]);
        dis1[i] = a[i];
    }
    // for (int i = 1; i <= n; i++) cout << dis1[i] << '\t';
    // cout << '\n';

    auto bfs = [&]() {
        // {距离, {这条边是否是第一层, {这条边的起点, 这条边的终点}}}
        priority_queue<pair<int, pair<int, pair<int, int>>>> pq;
        pq.push({0, {1, {0, S}}});
        dis[S] = 0;

        while (!pq.empty()) {
            // cout << pq.top().first << '\t' << pq.top().second.first << '\t';
            // cout << pq.top().second.second.first << '\t' <<
            // pq.top().second.second.second
            //      << '\n';

            int cur = pq.top().second.first;
            int u = pq.top().second.second.second;
            pq.pop();

            for (auto [v, w] : g[u]) {
                if (cur) {    // 如果在上层的话可以继续留在上层，也可以走到下层
                    // 上层
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        pq.push({-dis[v], {1, {u, v}}});
                    }

                    // 下层
                    if (u == S) {    // 处理超级起点导致的a值消失的问题
                        // dis1[v] = min(dis1[v], a[v]);
                        // pq.push({0, {0, {u, v}}});
                        // if (dis1[g[v][0].first] > dis[v] + g[v][0].second) {
                        //     dis1[g[v][0].first] = dis[v] + g[v][0].second;
                        //     pq.push({-dis1[g[v][0].first], {0, {v, g[v][0].first}}});
                        // }
                    } else {
                        if (dis1[v] > dis[u]) {
                            dis1[v] = dis[u];
                            pq.push({-dis1[v], {0, {u, v}}});
                            cout << "DEBUG: " << -dis1[v] << '\t' << u << '\t' << v
                                 << endl;
                        }
                    }
                } else {    // 如果在下层的话也就无法回到上层了
                    if (dis1[v] > dis1[u] + w) {
                        dis1[v] = dis1[u] + w;    // 找了这么久竟然是这里少加了w
                        pq.push({-dis1[v], {0, {u, v}}});
                        // cout << "DEBUG: " << -dis1[v] << '\t' << u << '\t' << v <<
                        // endl;
                    }
                }
            }
        }
    };
    bfs();

    int ans = -1e9;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dis1[i]);
        // cout << dis[i] << '\t' << dis1[i] << '\n';
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
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
