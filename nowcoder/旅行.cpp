#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
  给出一个图, 在图上选三个点, 求三个点最远的路径

  思路:
    最短路
    数据范围只有1000
    直接枚举每个点作为中转点的情况, 对这个点跑dijkstra
    取最大的两个点作为这个状态下的结果
    复杂度O(n^2*logn)
*/

typedef pair<int, int> pii;
const int N = 1010;
vector<pii> g[N];
int d[N];
int n, m;

int dijkstra(int s) {
    memset(&d, 0x3f, sizeof d);

    // 最短路
    priority_queue<pii> pq;
    pq.push({0, s});
    d[s] = 0;
    while (!pq.empty()) {
        auto [x, u] = pq.top();
        pq.pop();

        for (auto [v, dist] : g[u]) {
            if (d[v] > d[u] + dist) {
                d[v] = d[u] + dist;
                pq.push({-d[v], v});
            }
        }
    }

    // 取最大两点
    sort(d + 1, d + n + 1);
    int pos = n;
    while (pos && d[pos] == 0x3f3f3f3f) pos--;

    // for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    // cout << '\n';

    if (pos <= 2) return -1;    // 如果不够三个点, 因为起点是0, 需要大于3
    return d[pos - 1] + d[pos];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    // dijkstra复杂度O(nlogn)
    int ans = -1e9;
    for (int i = 1; i <= n; i++) {    // 枚举中转点
        ans = max(ans, dijkstra(i));
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://ac.nowcoder.com/acm/contest/26077/1004
// 2024年6月19日