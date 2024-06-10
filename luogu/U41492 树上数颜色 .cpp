#include <iostream>
#include <set>
#include <vector>

using namespace std;

// U41492 树上数颜色 
/* 
  子树类查询问题
    dsu on tree 和 长链剖分 都是解决子树类静态查询问题的统计类算法
    这类问题首先要是"子树"查询, 并且是静态的, 不可更改
    (有些问题是不需要 dsu on tree , 比如子树元素和, 子树最大值之类的)
    dsu on tree 和 长链剖分 解决问题的场景与线段树在很多情况下是相同的 (线段树合并)

  dsu on tree
    本质就是"优雅的暴力", 思想上有点接近莫队
    在复杂度证明和原理上接近轻重树链剖分
    别名: "树上启发式合并", "轻重树链分治"...

    相同的, 类似莫队的方法
    对于一棵树, 树上的子树间存在两种关系, 包含与不包含
    对于包含的关系, 可以直接由自己向上作为上层子树的一部分, 这部分看成不消耗复杂度
    (最后合并的就会被优化掉)
    那么就可以通过安排最优的顺序来优化大量的重复操作
    先从较小的子树开始向上推出上层子树, 剩下的部分通过长链合并尽量多的操作
    (也就是使相同两个操作间的公共区间最大化)
    最优复杂度可以达到O(nlogn)
    综上, 求最优序列的方法就是轻重树链剖分的倒置, 只需要在连首的部分init一次即可
    根据树链剖分的定理, 轻边的数量不超过O(logn)
*/

const int N = 1e5 + 10;
vector<int> g[N];
int a[N];
// dfs1
int siz[N];
int dfn[N];
int son[N];
int dep[N];
int f[N];
int cnt1 = 1;
// dfs2
int L[N];
int R[N];
int id[N];
int top[N];
int cnt2 = 1;
// dsu
int color[N];
set<int> st[N];

void dfs1(int u, int fa) {
    siz[u] = 1;
    dfn[u] = cnt1++;
    son[u] = -1;
    dep[u] = dep[fa] + 1;
    f[u] = fa;

    for (auto v : g[u]) {
        if (v == fa) continue;

        dfs1(v, u);
        siz[u] += siz[v];
        if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    id[u] = cnt2++;
    L[u] = id[u];
    R[u] = id[u];
    top[u] = t;

    if (son[u] == -1) return;
    dfs2(son[u], t);
    L[u] = min(L[u], L[son[u]]);
    R[u] = max(R[u], R[son[u]]);

    for (auto v : g[u]) {
        if (v == f[u]) continue;
        if (v == son[u]) continue;

        dfs2(v, v);
        L[u] = min(L[u], L[v]);
        R[u] = max(R[u], R[v]);
    }
}

// 歪门邪道用set暴力处理
void dsu(int u, int fa) {
    for (auto v : g[u]) {
        if (v == fa) continue;

        dsu(v, u);
        for (auto i : st[v]) st[u].insert(i);
    }

    st[u].insert(a[u]);    
    color[u] = st[u].size();
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];

    dsu(1, 0);

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << color[x] << '\n';
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


// https://www.luogu.com.cn/problem/U41492
// 2024年6月2日