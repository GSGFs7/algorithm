#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一棵树 求树上任意两点间的简单路径上的极差之和

  DSU
  太智慧了
*/

#define int long long

const int N = 1e6 + 10;
vector<int> g[N];
int a[N];
int fa[N];     // 并查集祖宗节点
int siz[N];    // 并查集大小
int ansMax, ansMin;

struct edge {
    int from, to;
    int max, min;
} e[N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        siz[i] = 1;
    }
}

int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        fa[fy] = fx;
        siz[fx] += siz[fy];
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        e[i] = {u, v, max(a[u], a[v]), min(a[u], a[v])};
    }

    // 最大值从小到大 
    // 意义是什么？
    // 为什么可以这样？
    // 为什么是这样？
    sort(e + 1, e + n, [](edge x, edge y) { return x.max < y.max; });
    init(n);
    for (int i = 1; i < n; i++) {
        // 出现次数？
        // 边与两点的转化？ 为什么正确？
        ansMax += siz[find(e[i].from)] * siz[find(e[i].to)] * e[i].max;    // ?
        merge(e[i].from, e[i].to);
    }

    // 最小值从大到小
    sort(e + 1, e + n, [](edge x, edge y) { return x.min > y.min; });
    init(n);
    for (int i = 1; i < n; i++) {
        ansMin += siz[find(e[i].from)] * siz[find(e[i].to)] * e[i].min; 
        merge(e[i].from, e[i].to);
    }
    // cout << ansMax << ' ' << ansMin << '\n';
    cout << ansMax - ansMin << '\n';
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


// https://codeforces.com/contest/915/problem/F
// 2024-09-30