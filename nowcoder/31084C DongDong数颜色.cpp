#include <iostream>
#include <vector>

using namespace std;

/*
  数每个子树上有多少种颜色

  dsu on tree板子
*/

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
int siz[N];
int son[N];
int f[N];
int a[N];
int n, m;
int color[N];
int ans[N];
int cnt = 0;

void dfs(int u, int fa) {
    f[u] = fa;
    siz[u] = 1;
    son[u] = -1;

    for (auto v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
    }
}

void cala(int u, int op) {
    for (auto v : g[u]) {
        if (v == f[u]) continue;
        if (vis[v]) continue;

        cala(v, op);
    }

    if (op == 1 && !color[a[u]]) cnt++;
    color[a[u]] += op;
    if (op == -1 && !color[a[u]]) cnt--;
}

void dsu(int u, bool keep) {
    for (auto v : g[u]) {
        if (v != f[u] && v != son[u]) dsu(v, false);
    }

    if (son[u] != -1) {
        dsu(son[u], true);
        vis[son[u]] = true;
    }

    cala(u, 1);
    ans[u] = cnt;
    if (son[u] != -1) vis[son[u]] = false;
    if (!keep) cala(u, -1);

    // for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    // cout << '\n';
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    dsu(1, 1);

    // for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    // cout << '\n';

    while (m--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
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


// https://ac.nowcoder.com/acm/contest/31084/C
// 2024年6月5日