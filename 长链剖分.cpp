#include <iostream>
#include <vector>

using namespace std;

/*
  长链剖分
    长链剖分是 dsu on tree 的一种特殊情况
    长链剖分不查子树, 而是给定深度, 合并子树深度相同的信息
      (如: 子树重deep[2]到deep[3]中间的信息)
    用于解决 "静态查询子树和深度有关信息" 是一种特殊的 "静态子树查询问题"
    相较原版 dsu on tree 长链剖分复杂度更加优秀, 基础复杂度为O(n)
      (长链剖+线段树 可以在相同的复杂度下实现更多功能)

    与dsu相比, "重儿子"并不与节点的大小相关, 而是与链的最长长度相关 ("长儿子")
    同时, 两条链之间并不会有交集, 也就是说不会像子树那样存在包含关系
    也就是说不用重新清空, 轻儿子和重儿子的顺序没有什么关系

    指针太难辣!
*/

const int N = 1e6 + 10;
vector<int> g[N];
int maxDeep[N];
int dep[N];
int son[N];
int ans[N];
int tmp[N];    // tmp数组才是本体, 一般使用f数组在tmp上取一部分, 类似滑动窗口
int *f[N];     // N个int型指针, 在另一个数组tmp上滑动
int *id = tmp;    // 最开始指向tmp的头部, 用于定位不同重链在tmp上的起始位置
int n;

// 长链剖分
void dfs1(int u, int fa) {
    dep[u] = maxDeep[u] = dep[fa] + 1;
    for (auto v : g[u]) {
        if (v == fa) continue;

        dfs1(v, u);

        maxDeep[u] = max(maxDeep[u], maxDeep[v]);
        if (maxDeep[v] > maxDeep[son[u]]) son[u] = v;
    }
}

void dfs(int u, int fa) {
    f[u][0] = 1;    // f[u] 就表示顶点u的深度数组的起始位置

    // 重儿子
    if (son[u]) {
        f[son[u]] = f[u] + 1;    // f[u]? f[u][0]?
        dfs(son[u], u);
        ans[u] = ans[son[u]] + 1;
    }

    // 轻儿子
    for (auto v : g[u]) {
        if (v == fa || v == son[u]) continue;

        // 定位最大深度为起点开始从下往上爬树
        f[v] = id;                        // 这条链的起点
        id += maxDeep[v] - dep[v] + 1;    // 往后移这么多位, 让出位置给后面的链
        dfs(v, u);

        // 对于自己的每一层深度的子节点
        for (int j = 0; j <= maxDeep[v] - dep[v]; ++j) {
            f[u][j + 1] += f[v][j];
            // 如果这个点大于已知结果
            if (f[u][j + 1] > f[u][ans[u]]) ans[u] = j + 1;
            // 或是如果这个点的序号比较小
            else if ((f[u][j + 1] == f[u][ans[u]] && j + 1 < ans[u])) ans[u] = j + 1;
        }
    }
    if (f[u][ans[u]] == 1) ans[u] = 0;    // 如果自己没有子节点
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 标记长链
    dfs1(1, 0);

    // id是用来定位下一次的起始位置的
    f[1] = id;
    id += maxDeep[1];    // 往后移maxDeep[1]位, 防止干扰
    dfs(1, 0);

    // for (int i = 0; i < 100; i++) cout << tmp[i] << ' ';
    // cout << '\n';

    for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
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


// https://codeforces.com/contest/1009/problem/F
// 3609 ms 	190192 KB
// 2024年6月4日