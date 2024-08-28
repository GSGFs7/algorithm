#include <bits/stdc++.h>

using namespace std;

/*
  使用线段树求区间最大子段和（对静态数组求最大子段和其实用ST表更简单）

  最大连续子段和表示的是在数组中取连续的一段，这段的和最大
  使用线段树求解这个问题需要维护多个变量，对于每个节点而言需要存储多个变量
  需要存储这个点的 区间和 最大前缀和 最大后缀和 最大区间和
  其中最大前缀和和最大和在区间和并时使用，表示前后两个区间合并后可能出现的最大值
  其中 最大前缀和和最大后缀和 可能在合并后更新
    需要对 前面节点的最大前缀 和 前面节点的综合+后面节点的最大前缀取最大值
  这份代码给出的查询操作与一般的线段树也不相同
    返回的不是查询值，而是一个线段树节点，表示一整个完整的区间
    （返回最大值会出问题，会将其他点也包括进来）
*/

class SegmentTree {
private:
    struct Node {
        int maxSum, prefixSum, suffixSum, totalSum;
        Node() : maxSum(0), prefixSum(0), suffixSum(0), totalSum(0) {}
        Node(int val) : maxSum(val), prefixSum(val), suffixSum(val), totalSum(val) {}
    };

    vector<Node> tree;
    int n;

    Node combine(Node left, Node right) {
        Node parentNode;
        parentNode.totalSum = left.totalSum + right.totalSum;
        parentNode.prefixSum = max(left.prefixSum, left.totalSum + right.prefixSum);
        parentNode.suffixSum = max(right.suffixSum, right.totalSum + left.suffixSum);
        parentNode.maxSum =
            max({left.maxSum, right.maxSum, left.suffixSum + right.prefixSum});
        return parentNode;
    }

    void build(const vector<int> &arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = Node(arr[tl]);
        } else {
            int mid = (tl + tr) >> 2;
            build(arr, v * 2, tl, mid);
            build(arr, v * 2 + 1, mid + 1, tr);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return Node(INT_MIN);
        if (l == tl && r == tr) {
            return tree[v];
        }
        int mid = (tl + tr) >> 2;
        Node leftQuery = query(v * 2, tl, mid, l, min(r, mid));
        Node rightQuery = query(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
        if (l > mid) return rightQuery;
        if (r <= mid) return leftQuery;
        return combine(leftQuery, rightQuery);    // 最后合成一个完整的目标区间
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = Node(new_val);
        } else {
            int mid = (tl + tr) >> 2;
            if (pos <= mid) {
                update(v * 2, tl, mid, pos, new_val);
            } else {
                update(v * 2 + 1, mid + 1, tr, pos, new_val);
            }
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        tree.resize(n * 4);
        build(arr, 1, 1, n);
    }

    int query(int l, int r) {
        Node result = query(1, 1, n, l, r);
        return result.maxSum;
    }

    void update(int pos, int new_val) { update(1, 1, n, pos, new_val); }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    a.insert(a.begin(), 0);
    SegmentTree tree(a);

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            if (x > y) swap(x, y);
            cout << tree.query(x, y) << '\n';
        } else {
            tree.update(x, y);
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


// https://www.acwing.com/problem/content/description/246/
// 2024年7月27日