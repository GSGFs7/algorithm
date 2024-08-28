#include <iostream>

/*
  树链剖分
  将整棵树按照一定的规则切分成带有一定性质的链 (链分解)
  可以根据这些性质求LCA和维护线段树等
  利用轻重链的性质, 可以避免在DFS的过程中被树上的毛刺带偏DFS
  剖分后得到的链大概是 O(N)的  最差情况下二叉树的链大概为 (n+1)/2
  将树链缩点后得到树剖结构树(也就是说图中点完全由重链形成), 边全部为原本的轻边
    关于树剖结构树与原图的对比:
    1.树上点 都是O(n)
    2.树上边 都是O(n)
    3.深度  原图最坏情况下为n  树剖结构树为logn (参考下面的定理的扩展)
  综上, 树链剖分的剖分的本质就是对结构树的压缩重构,
  使得在结构树上移动时的复杂度不高于log级 (树的直径也变为logn),
  同时, 树链剖分不具备任何信息维护的功能, 话句话说树剖不是数据结构,
  只是用dfs对树进行整理的过程

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

  定理:
    轻儿子上的size必定小于等于当前子树的一半
  定理的扩展:
    树上每经过一条轻边后, 子树的尺寸减小一半  (非常优秀的时间复杂度)

  数组:
    fa[u]: u的父节点
    sz[u]: 以u为根的子树的节点数
    dep[u]: u的深度
    son[u]: u的重儿子
    top[u]: u所在的重链的顶点 (唯一,类似并查集)
    id[u]: u剖分后的新编号, 编号的顺序是按照重链优先的DFS序
  (同一条重链上的点一定是连续的) nw[u]: 新编号在树中的权值(new w)

  实现(LCA):
    dfs1: 求出fa,dep,son
    dfs2: 求出top
    LCA: 让两个游标向上跳, 跳到同一条重链时, 深度较小(在上面的)的游标指向的就是LCA
    复杂度: 两个dfs都是O(n), LCA是O(logn), 求LCA的总复杂度是O(n+logn)
    (LCA的暴力写法, 如果数的深度可控, 复杂度就是树的深度, 还是树剖优化比较好)

  实现(树上修改和查询):
    树链剖分->线段树维护->树上修改和查询
    线段树的维护: 原树->序列->线段树
    对于不同的链之间, 子线段树是不存在关联的, 需要把线段树的不同的子段全部拼接起来
    类似于树套树的的结构

    使用线段树的时候可能会求路径, 问你从u到v经过了那些点, 这个时候可能会出一点小问题
    例如左下一条边1 2 3和右下一条边5 4 3相连, 形成一个人字形的树 (从下往上看)
    按照树剖的DFS序, 结果可能是3 2 1 4 5, 也就是先走完左边三个点, 再走右边两个点
    正确的顺序是1 2 3 4 5, 也就是说前面那段需要倒过来
    在处理这种问题的时候可以正反维护两个线段树
*/

using namespace std;
const int N = 1e6;    // 有坑, 可能是哪里开1e5太小了

/* 尽量这样写好点
// dfs1部分
int dfn[N];
int siz[N];
int son[N];
int dep[N];
int cnt1 = 1;
// dfs2部分
int top[N];
int id[N];
int sd[N];
int cnt2 = 1;
// 线段树部分
int tree[N];
int lazy[N];
*/

int n, m, r;    // 点, 边, 起点
int MOD;        // 模数
int w[N];       // 点的权重
int id[N];      // 剖分后的编号
int sd[N];      // ? 子节点最大的编号, 划定子线段树的范围
int sz[N];      // 子树大小
int fa[N];      // 父节点
int dep[N];     // 深度
int son[N];     // 最大的子节点
int top[N];     // 重链链顶
int cnt = 0;

// 前向星
struct Edge {
    int to, next;
} e[N];
int head[N];
int tot = 0;

void add(int u, int v) {
    e[++tot] = {v, head[u]};
    head[u] = tot;
}

// 树链剖分
// 第一次DFS, 记录size, 轻重链
void DFS1(int u, int f) {
    son[u] = -1;            // 先标记为没有子节点
    sz[u] = 1;              // 节点大小为1
    fa[u] = f;              // 父节点
    dep[u] = dep[f] + 1;    // 深度

    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == f) continue;

        DFS1(v, u);
        sz[u] += sz[v];    // 回溯更新整棵子树的大小
        if (son[u] == -1 || sz[v] > sz[son[u]]) {
            son[u] = v;    // 最大的子树
        }
    }
}

// 第二次DFS, 链分解
void DFS2(int u, int t) {
    top[u] = t;       // 链顶
    id[u] = ++cnt;    // 编号, 同一条重链上的编号从上到下是连续的
    sd[u] = id[u];    // 子树的终点, 子树中编号最大的点, 重链剖分后子树的编号是连续的
                      // 而线段树也只能更新连续的节点, 妙啊~, 太妙了

    if (son[u] == -1) return;          // 如果没有子节点
    DFS2(son[u], t);                   // 否则搜索重儿子
    sd[u] = max(sd[u], sd[son[u]]);    // 最深的地方

    // 搜索轻儿子
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa[u] || v == son[u]) continue;

        DFS2(v, v);                   // 轻儿子是重链的链顶
        sd[u] = max(sd[u], sd[v]);    // 子树中最大的编号
    }
}

// 线段树
int tree[N];    // N直接开1e6了, 不用乘4了
int lazy[N];

// 快速寻找左右儿子
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }

// 向上传递更新
void pushUp(int p) {
    tree[p] = tree[ls(p)] + tree[rs(p)];
    tree[p] %= MOD;
}

// lazy标记向下更新
void pushDown(int p, int l, int r) {
    if (!lazy[p]) return;

    // 懒标记
    lazy[ls(p)] += lazy[p];
    lazy[rs(p)] += lazy[p];

    // 节点值
    int mid = (l + r) >> 1;
    tree[ls(p)] += lazy[p] * (mid - l + 1) % MOD;
    tree[rs(p)] += lazy[p] * (r - mid) % MOD;

    lazy[p] = 0;
    lazy[ls(p)] %= MOD;
    lazy[rs(p)] %= MOD;
    tree[ls(p)] %= MOD;
    tree[rs(p)] %= MOD;
}

// 更新子树
void update(int p, int l, int r, int L, int R, int d) {
    if (L <= l && r <= R) {    // 如果当前范围被待修改的区间覆盖
        lazy[p] += d;
        tree[p] += (r - l + 1) * d % MOD;
        lazy[p] %= MOD;
        tree[p] %= MOD;
        return;
    }

    // 计算子节点的值
    pushDown(p, l, r);

    // 继续分叉查找
    int mid = (l + r) >> 1;
    if (L <= mid) update(ls(p), l, mid, L, R, d);
    if (mid < R) update(rs(p), mid + 1, r, L, R, d);
    pushUp(p);    // 回溯的时候更新这个点的值, 一直更新到根节点
}

// 更新整条链, 一个暴力LCA爬树, 抄板子记得改这里 (记得id[])
void updates(int x, int y, int d) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);    // 让x为较深的点
        update(1, 1, n, id[top[x]], id[x], d);    // 更新x到重链连顶的这条连续的路径
        x = fa[top[x]];                           // 向上爬
    }

    // 最后还要让他们会和
    if (dep[x] > dep[y]) swap(x, y);     // x是较浅的点
    update(1, 1, n, id[x], id[y], d);    // 从浅点到深点
}

// 统计连续编号范围内的值
int query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) {    // 如果被目标区间完全覆盖直接返回这个节点的值
        return tree[p];
    }

    pushDown(p, l, r);

    // 继续向下
    int res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) res = (res + query(ls(p), l, mid, L, R)) % MOD;
    if (mid < R) res = (res + query(rs(p), mid + 1, r, L, R)) % MOD;
    return res;
}

// 统计一整条链上的值
int querys(int x, int y) {
    int res = 0;
    while (top[x] != top[y]) {    // 如果两者不在同一条重链上, 也就是说编号不连续
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res = (res + query(1, 1, n, id[top[x]], id[x])) % MOD;    // 找连续的编号更新
        x = fa[top[x]];
    }

    // 抵达同一条重链后再让他们会和
    if (dep[x] > dep[y]) swap(x, y);
    res = (res + query(1, 1, n, id[x], id[y])) % MOD;
    return res;
}

void solve() {
    cin >> n >> m >> r >> MOD;
    for (int i = 1; i <= n; i++) cin >> w[i];

    // 边
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    // 树链剖分
    DFS1(r, r);
    DFS2(r, r);

    // 直接再空树上修改节点, 也相当于建图
    for (int i = 1; i <= n; i++) {
        update(1, 1, n, id[i], id[i], w[i]);
    }
    // Q: 有一点不太明白, w[]不是对应未被剖分的节点编号嘛
    //    为什么可以直接用剖分后的编号赋值
    // A: 这些点都表示的是线段树上的点 (所以为什么不能直接用线段树求解?)

    // for (int i = 1; i <= n; i++) cout << id[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << sd[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << w[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << tree[i] << ' ';
    // cout << '\n';

    while (m--) {
        int op, x, y, z;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            updates(x, y, z);    // 更新一条链
        } else if (op == 2) {
            cin >> x >> y;
            cout << querys(x, y) << '\n';
        } else if (op == 3) {
            cin >> x >> z;
            update(1, 1, n, id[x], sd[x], z);
        } else if (op == 4) {
            cin >> x;
            cout << query(1, 1, n, id[x], sd[x]) << '\n';
            // id[x]是子树的根节点, 节点编号最小
            // sd[x]是子树的编号最大的节点, id[x]到sd[x]都是连续的
            // 可以完整表示一整棵子树, 让线段得以实现
            // op==3的update()同理
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


// https://www.luogu.com.cn/problem/P3384
// 2024年4月19日