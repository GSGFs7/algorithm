#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

/*
  软件包管理器
*/

const int N = 4e5 + 10;
vector<int> g[N];
// dfs1部分
int dfn[N];
int siz[N];
int son[N];
int f[N];
int dep[N];
int cnt1 = 1;
// dfs2部分
int top[N];
int id[N];
int sd[N];
int cnt2 = 1;
// 线段树部分
int tree[N << 2];
int lazy[N << 2];
int n;

void dfs1(int u, int fa) {
    f[u] = fa;
    dfn[u] = cnt1++;
    siz[u] = 1;
    son[u] = -1;
    dep[u] = dep[fa] + 1;

    for (auto v : g[u]) {
        if (v == fa) continue;
        if (u == v) continue;

        dfs1(v, u);

        siz[u] += siz[v];
        if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int fa, int t) {
    id[u] = cnt2++;
    sd[u] = id[u];
    top[u] = t;

    if (son[u] == -1) return;
    dfs2(son[u], u, t);
    sd[u] = max(sd[u], sd[son[u]]);

    for (auto v : g[u]) {
        if (v == fa) continue;
        if (v == son[u]) continue;

        dfs2(v, u, v);
        sd[u] = max(sd[u], sd[v]);
    }
}

inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }

void pushUp(int p) { tree[p] = tree[ls(p)] + tree[rs(p)]; }

// // de了三天的bug原来是这里出逝了
// void pushDown(int p, int l, int r) {
//     if (lazy[p] == -1) return;

//     int mid = (ls(p) + rs(p)) >> 1;
//     tree[ls(p)] = lazy[p] * (mid - ls(p) + 1);
//     tree[rs(p)] = lazy[p] * (rs(p) - mid);

//     lazy[ls(p)] = lazy[rs(p)] = lazy[p];
//     lazy[p] = -1;
// }

// 明白了, 向下传递懒标记的时候, 这个父节点的范围可能会伸到另一条链上去, 但是范围却没有那么大
void pushDown(int p, int l, int r) {    // 标记下传, 必须要l和r框定范围
    if (lazy[p] == -1) return;

    int mid = (l + r) >> 1;              
    lazy[ls(p)] = lazy[rs(p)] = lazy[p];    // 全部安装或全部卸载
    tree[ls(p)] = lazy[p] * (mid - l + 1);
    tree[rs(p)] = lazy[p] * (r - mid);
    lazy[p] = -1;
}

void build(int p, int l, int r) {    // 貌似不需要
    if (l == r) {
        tree[l] = 0;
        lazy[l] = -1;
        return;
    }

    int mid = (l + r) >> 1;
    if (l <= mid) build(ls(p), l, mid);
    if (mid < r) build(rs(p), mid + 1, r);
    pushUp(p);
}

int query(int p, int L, int R, int l, int r) {
    if (L <= l && r <= R) return tree[p];

    int res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) res += query(ls(p), L, R, l, mid);
    if (mid < R) res += query(rs(p), L, R, mid + 1, r);
    return res;
}

void update(int p, int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) {
        lazy[p] = x;
        tree[p] = (r - l + 1) * x;
        return;
    }

    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(ls(p), L, R, l, mid, x);
    if (mid < R) update(rs(p), L, R, mid + 1, r, x);
    pushUp(p);
}

// 爬LCA
void install(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u] < dep[top[v]]]) swap(u, v);
        update(1, id[top[u]], id[u], 1, n, 1);
        u = f[top[u]];
    }
    if (dep[u] > dep[v]) swap(u, v);
    update(1, id[u], id[v], 1, n, 1);
}

void change(int u, int v) {
    int fu = top[u], fv = top[v];
    while (fu != fv) {              // 不在同一条重链上
        if (dep[fu] < dep[fv]) {    // 选择深度大的往上跳
            swap(u, v);
            swap(fu, fv);
        }
        update(1, 1, n, id[fu], id[u], 1);    // 路径fu->u节点全部赋值为1,表示安装
        u = f[fu];
        fu = top[u];
    }
    if (dep[u] > dep[v]) swap(u, v);    // 已经跳到同一条重路径上了
    update(1, id[u], id[v], 1, n, 1);    // 路径u->v节点全部赋值为1,表示安装
}

void uninstall(int u) { update(1, id[u], id[u] + siz[u] - 1, 1, n, 0); }

void solve() {
    memset(&lazy, -1, sizeof lazy);
    memset(&tree, 0, sizeof tree);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g[x + 1].push_back(i + 1);
        g[i + 1].push_back(x + 1);
    }

    dfs1(1, 0);
    dfs2(1, 0, 1);

    // for (int i = 1; i <= n; i++) cout << i << '_' << son[i] << '\n';
    // for (int i = 1; i <= n; i++) cout << i << '_' << id[i] << '\n';
    // for (int i = 1; i <= n; i++) cout << i << '_' << sd[i] << '\n';
    // for (int i = 1; i <= n; i++) cout << i << '_' << siz[i] << '\n';
    // for (int i = 1; i <= n; i++) cout << i << '_' << id[i] + siz[i] - 1 << '\n';

    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        string op;
        int x;
        cin >> op >> x;
        x++;
        if (op == "install") {
            int before = query(1, 1, n, 1, n);
            install(1, x);
            int after = query(1, 1, n, 1, n);
            // cout << before << ' ' << after << ' ';
            cout << after - before << '\n';
        } else {
            int before = query(1, 1, n, 1, n);
            uninstall(x);
            int after = query(1, 1, n, 1, n);
            // cout << before << ' ' << after << ' ';
            cout << before - after << '\n';
        }
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


// https://www.luogu.com.cn/problem/P2146
// 2024年6月2日