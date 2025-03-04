#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个以节点1为根的树 向上走需要花费体力（根节点方向）
 * 现在有m个查询
 * 问以v点为起点 有k点体力 最远能走多远
 *
 * 因为向上的过程需要消耗体力 向下则没有任何限制
 * 那么树上的行动就考虑上下两个方向可以获得的最大值
 * 向下的结果很好求 只需要跑一次dfs就可以求出所有点向下的最大结果
 * 向上可以抵达的结果就不好求了
 * 可以通过线段树快速求区间极值
 * 然后和向下的去最大值即可
 * 挺不错的题目
 * */

const int INF = 0x3f3f3f3f;

// 树上标记
struct Tag {
    int change = -INF;

    void apply(Tag t) { change = t.change; }
};

// 树上节点信息
struct Info {
    int max = -INF;

    void apply(Tag t) & {
        if (t.change != -INF) {
            max = t.change;
        }
    }

    Info() {}
    Info(int x) : max(x) {}

    // 重载 + 运算符作为节点合并的操作
    Info operator+(Info x) {
        Info res;
        res.max = std::max(max, x.max);
        return res;
    };
};

template <class Info, class Tag> struct SegTree {
    const int n;               // 数组大小
    std::vector<Info> info;    // 线段树节点信息
    std::vector<Tag> tag;      // 懒标记

    inline int ls(int p) { return p << 1; }
    inline int rs(int p) { return p << 1 | 1; }

    // 分配空间
    SegTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}

    // 初始化线段树
    SegTree(std::vector<Info> init) : SegTree(init.size()) { build(1, 0, n, init); }

    // 建树
    void build(int p, int l, int r, std::vector<Info> &init) {
        if (l == r) {
            info[p] = init[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(ls(p), l, mid);
        build(rs(p), mid + 1, r);
        pushUp(p);
    }

    // 向上更新
    void pushUp(int p) { info[p] = info[ls(p)] + info[rs(p)]; }

    // 应用标签到节点上
    void apply(int p, const Tag &v) {
        info[p].apply(v);    // 更新节点信息
        tag[p].apply(v);     // 更新懒标记
    }

    // 向下更新懒标记
    void pushDown(int p) {
        apply(ls(p), tag[p]);    // 左子树
        apply(rs(p), tag[p]);    // 右子树
        tag[p] = Tag();          // 清空
    }

    // 更新某个点
    void update(int p, int l, int r, int x, const Info &v) {
        if (l == r) {
            info[p] = v;
            return;
        }

        pushDown(p);
        int mid = (l + r) >> 1;
        if (x <= mid) {
            update(ls(p), l, mid, x, v);
        } else {
            update(rs(p), mid + 1, r, x, v);
        }
        pushUp(p);
    }

    // 更新某个点 对外接口
    void update(int p, const Info &v) { update(1, 0, n, p, v); }

    // 区间查询
    Info query(int p, int l, int r, int x, int y) {
        // 如果范围不相交 返回默认值
        if (l > y || r < x) {
            return Info();
        }
        // 如果完全包含在范围内
        if (l >= x && r <= y) {
            return info[p];
        }

        pushDown(p);
        int mid = (l + r) >> 1;
        return query(ls(p), l, mid, x, y) + query(rs(p), mid + 1, r, x, y);
    }

    // 区间查询 对外接口
    Info query(int l, int r) { return query(1, 0, n, l, r); }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dep(n + 1);       // 这个点的深度
    vector<int> maxDep(n + 1);    // 这个点可以向下抵达的最大深度
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        maxDep[u] = 0;
        for (auto v : g[u]) {
            if (v == fa) continue;

            dep[v] = dep[u] + 1;
            dfs1(v, u);
            // 有点类似于tarjan缩点中的low值
            maxDep[u] = max(maxDep[u], maxDep[v] + 1);
        }
    };
    dfs1(1, 0);

    int m;
    cin >> m;
    vector<vector<pair<int, int>>> q(n + 1);
    for (int i = 0; i < m; i++) {
        int v, k;
        cin >> v >> k;
        q[v].push_back({k, i});
    }

    // 万能线段树！
    SegTree<Info, Tag> tree(n);

    vector<int> ans(m);
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        // 统一处理当前节点的所有查询 类似启发式合并
        for (auto &now : q[u]) {
            int k = now.first;
            int id = now.second;    // 查询的编号
            // 不向上走能抵达的最大值
            ans[id] = max(ans[id], maxDep[u]);
            // 向上走能抵达的最大值 （消耗体力）
            ans[id] = max(ans[id], tree.query(max(0, dep[u] - k), dep[u]).max + dep[u]);
        }

        // 最大深度和次大深度
        int max1 = 0, max2 = 0;
        for (auto v : g[u]) {
            if (v == fa) continue;

            if (maxDep[v] + 1 > max1) {
                max2 = max1;
                max1 = maxDep[v] + 1;
            } else if (maxDep[v] + 1 > max2) {
                max2 = maxDep[v] + 1;
            }
        }

        // 遍历整棵树
        for (auto v : g[u]) {
            if (v == fa) continue;

            // 如果当前节点的深度就是最大的max1 只能选次大点
            int d = maxDep[v] + 1 == max1 ? max2 : max1;
            // 在线段树中添加u节点向下可以走的最大深度
            tree.update(dep[u], Info(d - dep[u]));
            dfs2(v, u);
            tree.update(dep[u], -INF);    // 回溯时撤销操作
        }
    };
    dfs2(1, 0);

    for (auto i : ans) cout << i << ' ';
    cout << endl;
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/2033/problem/G
// 2024-10-26
