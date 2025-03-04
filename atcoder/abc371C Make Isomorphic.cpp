#include <bits/stdc++.h>

using namespace std;

/*
 * 给出两个图，问从第一个变到第二个的同构图的最小花费
 *
 * 同构图，图中对应节点所连的边相同的图
 * 只与边和点的关系有关，与内部的节点编号无关
 * 因为数据范围只有8,直接大力枚举所有节点对应到第二个图上的情况
 * 找所有情况中的最小值
 * */

void solve() {
    int n;
    cin >> n;
    int m1;
    cin >> m1;
    vector<vector<bool>> g1(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        g1[u][v] = g1[v][u] = true;
    }
    int m2;
    cin >> m2;
    vector<vector<bool>> g2(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        g2[u][v] = g2[v][u] = true;
    }
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 1e9;
    vector<int> p = {0};
    vector<bool> vis(n + 1, false);
    function<void()> dfs = [&]() {
        if (int(p.size()) > n) {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (g1[p[i]][p[j]] != g2[i][j]) {
                        res += a[i][j];
                    }
                }
            }
            ans = min(ans, res);
            return;
        }

        // 全排列，重排另一个图的节点编号
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;

            p.push_back(i);
            vis[i] = true;
            dfs();
            vis[i] = false;
            p.pop_back();
        }
    };
    dfs();
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


// https://atcoder.jp/contests/abc371/tasks/abc371_c
// 2024-11-25
