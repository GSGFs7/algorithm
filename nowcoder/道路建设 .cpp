#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Kruskal 板子

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int N = 110;
int g[N][N];
int f[N];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve() {
    memset(&g, 0x3f, sizeof g);
    for (int i = 1; i < N; i++) f[i] = i;

    int c, n, m;
    cin >> c >> n >> m;
    priority_queue<piii> pq;
    for (int i = 0; i < n; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        pq.push({-x, {u, v}});
    }

    int ans = 0;
    while (!pq.empty()) {
        int d = pq.top().first;
        auto [u, v] = pq.top().second;
        pq.pop();

        if (find(u) != find(v)) {
            f[find(u)] = find(v);
            ans += -d;
        }
    }
    // cout << ans << '\n';
    cout << ((ans <= c) ? "Yes\n": "No\n");
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


// https://ac.nowcoder.com/acm/contest/26077/1010