#include <bits/stdc++.h>

using namespace std;

/*
 * 每次给出两种操作 1.u和v间添加一条边 2.输出连通块中第k大的数
 *
 * 很明显的 并查集判连通块+set查询集合中第k大数
 * 并查集按秩合并写错了 直接贴了大佬的板子
 * */

const int N = 1e5 + 10;
int f[N];
int siz[N];
set<int> m[N];

// DSU
class dsu {
public:
    vector<int> p;
    vector<int> sz;
    vector<set<int>> node;    // 使用set作为节点
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        sz.resize(n);
        node.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        for (int i = 0; i < n; i++) {
            node[i].insert(i);
        }
    }

    inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if (sz[x] < sz[y]) swap(x, y);
            node[x].insert(node[y].begin(), node[y].end());
            p[y] = x;
            sz[x] += sz[y];
            return true;
        }
        return false;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    dsu d(n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;

            // 合并
            u--, v--;
            d.unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;

            // 查询
            v--;
            int fa = d.get(v);
            if (d.node[fa].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = d.node[fa].rbegin();
                advance(it, k - 1);    // 迭代器前进k-1位
                cout << *it + 1 << '\n';
            }
        }
    }

    // cout << "DEBUG!!!!!\n";
    // for (int i = 1; i <= n; i++) {
    //     for (auto j : m[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "------------\n";
    // for (int i = 1; i <= n; i++) cout << f[i] << ' ';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
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


// https://atcoder.jp/contests/abc372/tasks/abc372_e
// 2024-11-05
