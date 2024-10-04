#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/*
  给出一个简单图和两个点，往图上加边，使两点的距离不变，求这样的点有多少个

  为什么这题都没出啊！！！
  数据范围只有1e3，计算出每个点到起点和终点的距离直接暴力枚举是否符合条件即可
*/

const int N = 1010;
vector<int> g[N];
map<int, int> mp[N];    // 是否已经存在边了

void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[u][v] = 1;
        mp[v][u] = 1;
    }

    queue<int> q;
    vector<int> d1(n + 1, 1e9);    // 到起点的距离
    q.push(s);
    d1[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (d1[v] > d1[u] + 1) {
                d1[v] = d1[u] + 1;
                q.push(v);
            }
        }
    }
    vector<int> d2(n + 1, 1e9);    // 到终点的距离
    q.push(t);
    d2[t] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (d2[v] > d2[u] + 1) {
                d2[v] = d2[u] + 1;
                q.push(v);
            }
        }
    }

    int ans = 0;
    int d = d1[t];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // 原本没有边，并且这条路不会比原本的更短
            if (!mp[i][j] && min(d1[i] + d2[j] + 1, d1[j] + d2[i] + 1) >= d) {
                ans++;
                // cout << i << '\t' << j << '\n';
            }
        }
    }
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


// https://codeforces.com/contest/954/problem/D
// 2024-09-17