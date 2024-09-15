#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
  给出一棵树, 问某棵子树上相同颜色超过k的有多少个

  DSU+树状数组
*/

typedef pair<int, int> pii;
const int N = 2e5 + 10;
vector<int> g[N];
vector<pii> q[N];
int ans[N];
int a[N];
// 剖分
int siz[N];
int son[N];
int f[N];
// dsu
int cnt[N];
int skp = 0;
// 树状数组
int tree[N];
int sum;

void dfs(int u, int fa) {
    siz[u] = 1;
    son[u] = -1;
    f[u] = fa;

    for (auto v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
    }
}

//*****************************************************************
inline int lowBit(int u) { return u & (-u); }

void update(int u, int x) {
    for (int i = u; i < N; i += lowBit(i)) tree[i] += x;
}

int query(int u) {
    int res = 0;
    for (int i = u; i; i -= lowBit(i)) res += tree[i];
    return res;
}

//*****************************************************************
void cala(int u, int op) {
    for (auto v : g[u]) {
        if (v == f[u]) continue;
        if (v == skp) continue;

        cala(v, op);
    }

    // 树状数组的修改, 如果是2->1这样的修改, 需要先删掉2再添加1
    if (op == 1) {
        if (cnt[a[u]] == 0) sum++;               // 是否存在
        if (cnt[a[u]]) update(cnt[a[u]], -1);    // 删掉原来的值
        cnt[a[u]]++;                             // 更改
        update(cnt[a[u]], 1);                    // 加上新的值
    } else {
        update(cnt[a[u]], -1);
        cnt[a[u]]--;
        if (cnt[a[u]]) update(cnt[a[u]], 1);
        if (cnt[a[u]] == 0) sum--;
    }
}

void dsu(int u, int keep) {
    for (auto v : g[u]) {
        if (v == son[u]) continue;
        if (v == f[u]) continue;

        dsu(v, false);
    }

    if (son[u] != -1) {
        dsu(son[u], true);
        skp = son[u];
    }

    cala(u, 1);
    skp = 0;
    for (auto i : q[u]) {                            // 处理询问
        ans[i.second] = sum - query(i.first - 1);    // 超过数量就是总数减去小于的
        // cout << i.first << ' ', cout << sum << ' ' << query(i.first - 1) << '\n';
    }
    if (!keep) {    // 清空
        cala(u, -1);
        // cout << sum << '\n';
        // for (int i = 1; i < 200; i++) cout << tree[i] << ' ';cout << '\n';
        // for (int i = 1; i < 200; i++) cout << cnt[i] << ' ';cout << '\n';
    }
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

    for (int i = 1; i <= m; i++) {    // 记录每个子树的询问
        int x, k;
        cin >> x >> k;
        q[x].push_back({k, i});
    }

    dfs(1, 0);
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


// https://codeforces.com/contest/375/problem/D
// 280 ms 	29780 KB