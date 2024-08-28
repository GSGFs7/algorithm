#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
  树上启发式合并
  一种基于人类的经验和直觉对算法经行优化

  栗子:
    并查集按秩合并
    对于两个大小不一样的集合, 将小的集合插入到大的中, 而不是将大的合并到小的中
    可以减少一定的计算量

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
    (类似并查集, 均摊O(logn)的复杂度)
    
    需要的操作:
        1、处理轻儿子
        2、处理重儿子
        3、把轻儿子的信息往重儿子上边并
        4、计算答案
        5、需要清空时清空统计用的数据结构

  长链剖分
    长链剖分是 dsu on tree 的一种特殊情况
    长链剖分不查子树, 而是给定深度, 合并子树深度相同的信息
      (如: 子树重deep[2]到deep[3]中间的信息)
    用于解决 "静态查询子树和深度有关信息" 是一种特殊的 "静态子树查询问题"
    相较原版 dsu on tree 长链剖分复杂度更加优秀, 基础复杂度为O(n)
      (长链剖+线段树 可以在相同的复杂度下实现更多功能)
    代码在另一个文件
*/

/*
  例题: CF600E
    给出一个树, 树上每个点都带一种颜色, 求每棵子树最多的颜色有多少
    (如果有多个最大值, 颜色相加)
*/

const int N = 1e5 + 10;
vector<int> g[N];
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
int a[N];      // 点的颜色
int cnt[N];    // 当前状态每个颜色的数量
int ans[N];    // 结果
int vis[N];    // 是否跳过这个点, 其实每次只有一个重儿子需要跳过, 用一个数就可以了
int maxCnt;    // 记录出现最多的颜色的次数
int sum;    // 记录出现最多的颜色的数量(可能存在多个相同的数量)

// 树剖
//****************************************
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
    R[u] = max(R[u], R[son[u]]);

    for (auto v : g[u]) {
        if (v == f[u]) continue;
        if (v == son[u]) continue;

        dfs2(v, v);
        R[u] = max(R[u], R[v]);
    }
}
//*******************************************

// 正向, 与下面的函数可以合并在一起
void add(int u) {
    cnt[a[u]]++;
    // cout << a[u] << ' ' << cnt[a[u]] << '\n';

    if (cnt[a[u]] == maxCnt) sum += a[u];    // 如果一样多就都算上
    if (cnt[a[u]] > maxCnt) sum = a[u], maxCnt = cnt[a[u]];

    for (auto v : g[u]) {
        if (v == f[u] || vis[v]) continue;    // 如果是父节点或是重儿子就要跳过
        add(v);
    }
}

// 反向
void del(int u) {
    cnt[a[u]]--;
    // cout << a[u] << ' ' << cnt[a[u]] << '\n';

    for (auto v : g[u]) {
        if (v == f[u] || vis[v]) continue;    // 如果是父节点或是重儿子就要跳过
        del(v);
    }
}

void dsu(int u, bool keep) {
    // 先轻儿子
    for (auto v : g[u]) {
        if (v == f[u]) continue;
        if (v == son[u]) continue;

        dsu(v, 0);
    }

    // 后重儿子
    if (son[u] != -1) {
        dsu(son[u], 1);
        vis[son[u]] = true;    // 重儿子先跳过, 因为当前的数据就是由重儿子留下的
    }

    // 查找颜色, 合并重儿子
    add(u);
    ans[u] = sum;
    if (son[u] != -1) vis[son[u]] = false;
    if (!keep) del(u), sum = maxCnt = 0;    // 链的链顶需要init
    // 上面不能使用memset, 复杂度是O(n)的, 会增加大量的复杂度
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 1);
    dsu(1, 1);

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
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


// https://codeforces.com/contest/600/problem/E
// 233 ms
// 2024年6月3日