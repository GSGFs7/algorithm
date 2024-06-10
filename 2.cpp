#include <iostream>
#include <vector>

using namespace std;

/*
  问以某个节点为根的子树存在多少个颜色的数量大于k
*/

typedef pair<int, int> pii;
const int N = 2e5 + 10;
vector<int> g[N];
vector<pii> q[N];
// 树剖
int siz[N];
int son[N];
int f[N];
int a[N];
// dsu
int cnt[N];
int ans[N];
int skp = 0;
// 树状数组
int tree[N];
int vis[N];
int sum = 0;    // 记录树状数组中一共有多少个颜色

/// 树链剖分
void dfs(int u, int fa) {
    siz[u] = 1;
    son[u] = -1;
    f[u] = fa;

    for (auto v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
    }
}

/// 树状数组
inline int lowBit(int x) { return x & (-x); }

void update(int x, int v) {
    for (int i = x; i < N; i += lowBit(i)) tree[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowBit(i)) res++;
    return res;
}

/// 树上启发式合并
void cala(int u, int x) {
    for (auto v : g[u]) {
        if (v != skp && v != f[u]) cala(v, x);
    }

    if (x == 1 && !vis[a[u]]) update(a[u], x), vis[a[u]] = true, sum++;
    if (x == -1 && vis[a[u]]) update(a[u], x), vis[a[u]] = false, sum--;
}

void dsu(int u, bool keep) {
    for (auto v : g[u]) {
        if (v != son[u] && v != f[u]) dsu(v, false);
    }

    if (son[u] != -1) {
        dsu(son[u], true);
        skp = son[u];
    }

    cala(u, 1);
    for (auto i : q[u]) ans[i.second] = sum - query(i.first);
    if (son[u] != -1) skp = 0;
    if (!keep) cala(u, -1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= m; i++) {
        int x, k;
        cin >> x >> k;
        q[x].push_back({k, i});
    }

    dsu(1, 1);

    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
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