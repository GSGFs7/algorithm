#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个图 问在一个连通的三元组中可以添加的边数
 *
 * 因为在同一个连通块中的点最后肯定是两两之间都有一条边的
 * 这应该很好证明 因为需要最大化边的数量 （但是我连这个都没有想到...）
 * 那么对于一个连通块而言可以添加的边就是最大的可能边数减去已经存在的边数
 * 对所有连通块求解相加即可
 * */

#define int long long    // 不开longlong见祖宗
const int N = 2e5 + 10;
vector<int> g[N];
int f[N];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        if (f[u] != f[v]) {
            f[find(u)] = find(v);
        }
    }

    // siz连通块的大小 e已经存在的边数
    map<int, int> siz, e;
    for (int i = 1; i <= n; i++) {
        siz[find(i)]++;
        e[find(i)] += g[i].size();
    }

    int ans = 0;
    for (auto x : siz) {
        // 因为两个点之间之连了一条边 e也不用除以二了
        ans += x.second * (x.second - 1) / 2 - e[x.first];
    }
    cout << ans << '\n';
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


// https://atcoder.jp/contests/abc350/tasks/abc350_d
// 2024-10-18
