#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个图，问中间经过特定的几个点后从1到n的最短距离
 * */

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1e18));    // 需要一个很大的初始值
    vector<int> u(m + 1), v(m + 1), w(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        dis[u[i]][v[i]] = min(dis[u[i]][v[i]], 1ll * w[i]);
        dis[v[i]][u[i]] = min(dis[v[i]][u[i]], 1ll * w[i]);
    }

    // floyd
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int q;
    cin >> q;
    while (q--) {
        int K;
        cin >> K;
        vector<int> id(K + 1);
        for (int i = 1; i <= K; i++) cin >> id[i];
        sort(++id.begin(), id.end());
        int ans = 1e18;

        // 爆搜找最短路
        function<void(int, int, int)> dfs = [&](int idx, int x, int cost) {
            if (cost > ans) return;

            if (x == u[id[idx]]) {
                x = v[id[idx]];
            } else {
                x = u[id[idx]];
            }
            cost += w[id[idx]];

            if (idx == K) {
                cost += dis[x][n];
                ans = min(ans, cost);
                return;
            }

            dfs(idx + 1, u[id[idx + 1]], cost + dis[x][u[id[idx + 1]]]);
            dfs(idx + 1, v[id[idx + 1]], cost + dis[x][v[id[idx + 1]]]);
        };

        // 全排列
        do {
            // 两个方向
            dfs(1, u[id[1]], dis[1][u[id[1]]]);
            dfs(1, v[id[1]], dis[1][v[id[1]]]);
            // for (auto i : id) cout << i << ' ';
            // cout << endl;
        } while (next_permutation(++id.begin(), id.end()));
        cout << ans << '\n';
    }
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


// https://atcoder.jp/contests/abc369/tasks/abc369_e
// 2024-11-22
