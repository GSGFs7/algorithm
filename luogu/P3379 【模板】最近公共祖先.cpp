#include <iostream>
#include <vector>

#define int long long
using namespace std;

/*
  树链剖分
  将整棵树按照一定的规则切分成带有一定性质的链
  可以根据这些性质求LCA和维护线段树等

  一些概念:
    重儿子: 父节点所有儿子中子树节点最多的点
    轻儿子: 除重儿子以外的点
    重边: 父节点和重儿子连成的边
    轻边: 父节点和轻儿子连城的边
    重链: 由多条重边连成的路径
    轻链: 由多条轻边连成的路径

    一些性质:
        1.整棵树会被剖分成若干条重链
        2.轻儿子一定是每条重链的起点
        3.任意一条路径被切分成不超过logn条链

  数组:
    fa[u]: u的父节点
    sz[u]: 以u为根的子树的节点数
    dep[u]: u的深度
    son[u]: u的重儿子
    top[u]: u所在的重链的顶点 (唯一,类似并查集)
    id[u]: u剖分后的新编号, 编号的顺序是按照重链优先的DFS序 (同一条重链上的点一定是连续的)
    nw[u]: 新编号在树中的权值(new w)

  实现(LCA):
    dfs1: 求出fa,dep,son
    dfs2: 求出top
    LCA: 让两个游标向上跳, 跳到同一条重链时, 深度较小(在上面的)的游标指向的就是LCA
    复杂度: 两个dfs都是O(n), LCA是O(logn), 求LCA的总复杂度是O(n+logn)

  实现(树上修改和查询):
    树链剖分->线段树维护->树上修改和查询

*/

const int N = 5e5 + 10;
int fa[N], sz[N], dep[N], son[N], top[N];
vector<int> e[N];    // 不知道为什么会段错误(炸栈了)
// int head[N];
// int tot = 1;

// struct Edge {
//     int to, next;
// } e[N << 1];

// void add(int u, int v) {
//     e[tot].to = v;
//     e[tot].next = head[u];
//     head[u] = tot++;
// }

// 第一次DFS, 标记深度,父节点等
void dfs1(int u, int father) {
    fa[u] = father;              // 父节点
    dep[u] = dep[father] + 1;    // 深度
    sz[u] = 1;                   // 子节点大小
    for (int v : e[u]) {
        if (v == father) continue;    // 不能往回搜

        dfs1(v, u);

        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;    // 最大的子节点
    }
}

// 第二次DFS, 标记重链
void dfs2(int u, int t) {
    top[u] = t;    // 这个点的重链起点, 记录链头

    if (!son[u]) return;    // 如果没有重儿子(重链走到尽头了)

    dfs2(son[u], t);    // 如果有, 继续搜索重链

    for (int v : e[u]) {                              // 搜索轻边
        if (v != son[u] && v != fa[u]) dfs2(v, v);    // 轻儿子的top是自己
    }
}

// de了好久, 原来是这里错了, 少了个top
// int lca(int u, int v) {    // 求LCA
//     while (top[u] != top[v]) {
//         if (dep[u] < dep[v]) swap(u, v);    // 保证u的深度最深
//         u = fa[top[u]];                     // 直接爬到链头
//     }
//     return dep[u] < dep[v] ? u : v;    // 输出深度较小的
// }

int lca(int x, int y) {    // 求LCA
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);    // 保证u的深度最深(是top的深度)
        x = fa[top[x]];                               // 直接爬到链头
    }
    if (dep[x] > dep[y]) swap(x, y);    // 输出深度较小的
    return x;
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1(s, s);
    dfs2(s, s);

    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();
    return 0;
}


// https://www.luogu.com.cn/problem/P3379
// 2024年4月6日