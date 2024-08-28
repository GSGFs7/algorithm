#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

/*
  线段树求区间最大连续子段和

  相较普通线段树, 需要记录最大前缀和与最大后缀和
  在pushUp时需要通过这两个值来计算出合并后的区间最大子段和
*/

class SegTreeNode {
public:
    int l, r;          // 两个子节点的位置
    int lmax, rmax;    // 当前区间的最大前缀和和后缀和
    int sum;           // 区间和
    int max;           // 最大子区间和
    SegTreeNode() {}
    SegTreeNode(int l_, int r_, int sum_, int max_, int lmax_, int rmax_) {
        l = l_;
        r = r_;
        sum = sum_;
        max = max_;
        lmax = lmax_;
        rmax = rmax_;
    }
};

const int N = 5e5 + 10;
int a[N];
SegTreeNode tree[N];

void push_up(int root, int ls, int rs) {
    // 把可能的结果全拼起来试试, 取其中的最大值
    tree[root].sum = tree[ls].sum + tree[rs].sum;
    tree[root].lmax = max(tree[ls].lmax, tree[ls].sum + tree[rs].lmax);
    tree[root].rmax = max(tree[rs].rmax, tree[ls].rmax + tree[rs].sum);
    tree[root].max =
        max(max(tree[ls].max, tree[rs].max), tree[ls].rmax + tree[rs].lmax);
}

void build(int root, int l, int r) {
    tree[root].l = l, tree[root].r = r;

    if (l == r) {
        tree[root].sum = a[l];
        tree[root].max = a[l];
        tree[root].lmax = a[l];
        tree[root].rmax = a[l];
        return;
    }

    int ls = root << 1;
    int rs = root << 1 | 1;
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(root, ls, rs);
}

void update(int root, int idx, int val) {
    if (tree[root].l == tree[root].r) {
        tree[root].sum = val;
        tree[root].max = val;
        tree[root].lmax = val;
        tree[root].rmax = val;
        return;
    }

    int ls = root << 1;
    int rs = root << 1 | 1;
    int mid = tree[root].l + tree[root].r >> 1;

    // push_down();
    if (idx <= mid) {
        update(ls, idx, val);
    } else {
        update(rs, idx, val);
    }
    push_up(root, ls, rs);
}

SegTreeNode query(int root, int ql, int qr) {
    if (ql <= tree[root].l && tree[root].r <= qr) return tree[root];

    int ls = root << 1;
    int rs = root << 1 | 1;
    int mid = tree[root].l + tree[root].r >> 1;

    SegTreeNode L = SegTreeNode();
    SegTreeNode R = SegTreeNode();
    SegTreeNode res;
    L.sum = L.max = L.lmax = L.rmax = -(1 << 30);
    R.sum = R.max = R.lmax = R.rmax = -(1 << 30);
    res.sum = 0;

    if (ql <= mid) {
        L = query(ls, ql, qr);
        res.sum += L.sum;
    }
    if (mid + 1 <= qr) {
        R = query(rs, ql, qr);
        res.sum += R.sum;
    }

    res.max = max(max(L.max, R.max), L.rmax + R.lmax);

    res.lmax = max(L.lmax, L.sum + R.lmax);
    if (mid + 1 <= ql) {
        res.lmax = max(res.lmax, R.lmax);
    }

    res.rmax = max(R.rmax, L.rmax + R.sum);
    if (qr <= mid) {
        res.rmax = max(res.rmax, L.rmax);
    }

    return res;
}


int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    for (int _ = 0; _ < m; _++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            if (l > r) swap(l, r);
            cout << query(1, l, r).max << endl;
        } else {
            int idx, val;
            cin >> idx >> val;
            update(1, idx, val);
        }
    }
    return 0;
}
