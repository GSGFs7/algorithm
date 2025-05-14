#include <bits/stdc++.h>

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
