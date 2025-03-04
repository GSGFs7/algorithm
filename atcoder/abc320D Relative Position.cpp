#include <bits/stdc++.h>

using namespace std;

/*
 * 在一个二维平面上 给出m个关系 表示b在a的(x,y)方向上 问是否可以确定每个人的位置
 *
 * 本来想着拓扑排序 写了半天发现半天对劲
 * 看别人直接BFS就解决了
 * 因为只有1号点是事先确定的
 * 直接从1号点开始向外扩散 不能扩散的点就是无法抵达的
 *
 * The given information is consistent
 * 题目中的描述 没有复杂情况
 * */

#define int long long
const int N = 2e5 + 10;
vector<array<int, 3>> e[N];    // 记录边和边权

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        e[u].push_back({v, x, y});
        e[v].push_back({u, -x, -y});    // 反过来
    }

    // 从1开始向外扩散
    queue<int> q;
    vector<pair<int, int>> pos(n + 1);
    vector<bool> vis(n + 1, false);
    q.push(1);
    pos[1] = {0, 0};
    vis[1] = true;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto [v, x, y] : e[u]) {
            if (vis[v]) continue;

            pos[v] = {pos[u].first + x, pos[u].second + y};
            vis[v] = true;
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            cout << pos[i].first << ' ' << pos[i].second << '\n';
        } else {
            cout << "undecidable\n";
        }
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


// https://atcoder.jp/contests/abc320/tasks/abc320_d
// 2024-10-22
