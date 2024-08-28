#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 最短路板子

typedef pair<int, int> pii;
const int N = 1010;
vector<pii> g[N];
int dist[N];

void solve() {
    memset(&dist, 0x3f, sizeof dist);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }

    priority_queue<pii> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto [v, d] : g[u]) {
            if (dist[v] > dist[u] + d) {
                dist[v] = dist[u] + d;
                pq.push({-d, v});
            }
        }
    }

    // for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
    // cout << '\n';

    if (dist[t] == 0x3f3f3f3f) return cout << -1 << '\n', void();
    cout << dist[t] << '\n';
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


// https://ac.nowcoder.com/acm/contest/26077/1007