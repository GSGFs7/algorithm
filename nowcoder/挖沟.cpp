#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
  最小生成树板子
*/

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int N = 1e5 + 10;
int f[N];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        pq.push({x, {u, v}});
    }

    for (int i = 1; i <= n; i++) f[i] = i;
    int ans = 0;
    while (!pq.empty()) {
        int d = pq.top().first;
        auto [u, v] = pq.top().second;
        pq.pop();

        if (find(u) != find(v)) {
            f[find(u)] = find(v);
            ans += d;
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


// https://ac.nowcoder.com/acm/contest/26077/1008
// 2024年6月19日