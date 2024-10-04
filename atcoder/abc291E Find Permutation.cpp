#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
  给出m个关系(x,y)，表示第x个数小于第y个数，问是否存在给出的关系所对应的排列

  这题眼看过去没有一点头绪（甚至在往最大流哪方面想）
  竟然是拓扑排序，真的好少见，我连拓扑的板子都忘记了    
  因为可以很轻松的找到最小的点，然后回退找到第二大的点...
*/

const int N = 2e5 + 10;
vector<int> g[N];
int d[N];
int ans[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);    // 大的数向小的数连边，这样先拓扑出来的就是最小的数
        d[u]++;    // 出度，当一个点没有出度的时候也就说明这个点就是当前最小的了
    }

    /// topo
    int cnt = n;    // 怎么反过来了，好像不太对
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
    }
    if (q.size() > 1) return cout << "No\n", void();    // 必须有唯一确定的排列
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        ans[u] = cnt--;

        for (auto v : g[u]) {
            if (--d[v] == 0) q.push(v);
        }
        if (q.size() > 1) return cout << "No\n", void();
    }

    // 如果本身就不符合拓扑的条件
    for (int i = 1; i <= n; i++) {
        if (d[i] != 0) return cout << "No\n", void();
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
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


// https://atcoder.jp/contests/abc291/tasks/abc291_e
// 2024-10-02