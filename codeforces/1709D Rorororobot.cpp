#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个n*m的区域, 第i列有高度为a[i]的障碍物, 一次需要走k步, 问是否可以从s走到t

  思路:
    线段树维护区间最大值, 如果最大能到达的高度没有障碍物高就不能抵达
    关于k, x和y的距离必须使k的整数倍, 不然也不能到达
*/

const int N = 2e5 + 10;
int tree[N << 2];
int a[N];

inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
inline void pushUp(int p) { tree[p] = max(tree[ls(p)], tree[rs(p)]); }

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushUp(p);
}

// 大写表示范围, 小写表示指针
int query(int p, int L, int R, int l, int r) {
    if (L <= l && r <= R) return tree[p];

    int res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) res = query(ls(p), L, R, l, mid);
    if (mid < R) res = max(res, query(rs(p), L, R, mid + 1, r));
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];

    build(1, 1, m);

    int q;
    cin >> q;
    while (q--) {
        int sx, sy, tx, ty, k;
        cin >> sx >> sy >> tx >> ty >> k;

        // 就算没有障碍物都到达不了终点
        if (abs(sx - tx) % k || abs(sy - ty) % k) {
            cout << "NO\n", void();
            continue;
        }

        // 想复杂了, 不用考虑左右的狭道, 一定可以直上直下
        sx += (n - sx) / k * k;                                 // 最高高度
        int maxn = query(1, min(sy, ty), max(sy, ty), 1, m);    // 障碍物最高高度
        // cout << maxn << ' ' << sx << ' ';
        cout << (maxn < sx ? "YES\n" : "NO\n");
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


// https://codeforces.com/contest/1709/problem/D
// 2024年5月24日