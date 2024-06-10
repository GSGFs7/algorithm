#include <iostream>
#include <vector>

using namespace std;

/*
  给出以棵树, 求某棵子树上不超过k的节点有多少个

  n在1e6级, 时限3s, 正常dsu肯定超时
  可以使用前缀和, 用tree[k]统计子树上所有不超过k的值出现次数
  统计答案的时候就不用重新回到子树删掉大于k的点了, 使用树状数组实现
*/

typedef pair<int, int> pii;
const int N = 3e6 + 10;
vector<int> g[N];
vector<int> qq[N];    // 存储询问的下标
pii q[N];             // 存储询问
int a[N];
int n, m;
// 树链剖分
int son[N];
int siz[N];
int re[N];    // 还原 reduction
int L[N];
int R[N];
int f[N];
int cnt = 0;
// dsu
int ans[N];
int skp;
// 树状数组
int tree[N];

//************************************************

/// 树剖部分
void dfs(int u, int fa) {
    f[u] = fa;
    L[u] = ++cnt;
    re[cnt] = u;
    siz[u] = 1;
    son[u] = -1;

    for (auto v : g[u]) {
        if (v == fa) continue;

        dfs(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[son[u]] < siz[v]) son[u] = v;
    }
    R[u] = cnt;
}
//************************************************

/// 树状数组部分
inline int lowBit(int u) { return u & (-u); }

void update(int u, int x) {
    for (int i = u; i < N; i += lowBit(i)) tree[i] += x;
}

int query(int u) {
    int res = 0;
    for (int i = u; i; i -= lowBit(i)) res += tree[i];
    return res;
}
//************************************************

/// dsu on tree 部分
void cala(int u, int op) {
    for (int i = L[u]; i <= R[u]; i++) {
        if (re[i] == skp) {
            i = R[re[i]];    // 后面for会自己加上1跳过这个数
            continue;
        }
        update(a[re[i]], op);    // 更新这个点
    }
}

void dsu(int u, bool keep) {
    for (auto v : g[u]) {
        if (v != f[u] && v != son[u]) dsu(v, false);
    }

    if (son[u] != -1) {
        dsu(son[u], true);
        skp = son[u];
    }

    cala(u, 1);
    // 节省时间的关键, 把同一颗子树上的所有答案全部合并到一起计算
    for (auto i : qq[u]) ans[i] = query(q[i].second);
    if (son[u] != -1) skp = 0;
    if (!keep) cala(u, -1);
}
//************************************************

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {    // 储存答案及下标
        cin >> q[i].first >> q[i].second;
        qq[q[i].first].push_back(i);
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


// https://ac.nowcoder.com/acm/contest/31084/B
// 2024年6月6日