#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个图 可以将k条边距离变成0 问从1到n的最小距离
 *
 * 分层图板子
 * 但是还有DP写法
 * */

#define int long long
const int N = 1e4 + 10;
vector<pair<int, int>> g[N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // 分成k+1层 表示这一层使操作了几条边
    vector<vector<int>> dis(k + 1, vector<int>(n + 1, 1e18));
    priority_queue<array<int, 3>> pq;
    pq.push({0, 1, 0});
    dis[0][1] = 0;
    while (!pq.empty()) {
        int u = pq.top()[1];
        int layer = pq.top()[2];
        pq.pop();


        for (auto [v, w] : g[u]) {
            // 这一层
            if (dis[layer][v] > dis[layer][u] + w) {
                dis[layer][v] = dis[layer][u] + w;
                pq.push({-dis[layer][v], v, layer});
            }
            // 到下一层
            if (layer != k && dis[layer + 1][v] > dis[layer][u]) {
                dis[layer + 1][v] = dis[layer][u];
                pq.push({-dis[layer + 1][v], v, layer + 1});
            }
        }
    }

    cout << dis[k][n] << '\n';
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


// https://www.luogu.com.cn/problem/P2939
// 2024-10-30
