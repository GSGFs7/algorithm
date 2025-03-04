#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个图 可以选择k条边使他们的花费减少一半 问从1到n的最小花费
 *
 * 分层图
 * 使用分层图将k种选择进行拆分
 * 因为如果重复选一条边的话也就是说明这条边使用了两次
 * 所以不会出现重复的情况 直接大力跑即可 不用每层图都去建边
 * */

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<vector<int>> dis(k + 1, vector<int>(n + 1, 1e9));
    priority_queue<array<int, 3>> pq;
    pq.push({0, 1, 0});
    dis[0][1] = 0;
    while (!pq.empty()) {
        int u = pq.top()[1];
        int layer = pq.top()[2];
        pq.pop();

        for (auto [v, w] : g[u]) {
            // 留在这一层
            if (dis[layer][v] > dis[layer][u] + w) {
                dis[layer][v] = dis[layer][u] + w;
                pq.push({-dis[layer][v], v, layer});
            }
            // 前往下一层
            if (layer != k && dis[layer + 1][v] > dis[layer][u] + w / 2) {
                dis[layer + 1][v] = dis[layer][u] + w / 2;
                pq.push({-dis[layer + 1][v], v, layer + 1});
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i <= k; i++) ans = min(ans, dis[i][n]);
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


// https://www.luogu.com.cn/problem/P4822
// 2024-10-31
