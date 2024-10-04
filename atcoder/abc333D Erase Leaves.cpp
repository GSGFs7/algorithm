#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

/*
   给出一张图，每次可以删除图上一个叶子节点，问删多少次才可以把节点1删掉

   误区：并不是寻找最小子树，找到最小子树后1可能不一定是叶子节点
   需要删除除了最大子树外所有节点
*/

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

    // 寻找最大子树
    vector<int> siz(n + 1), maxn(n + 1);
    auto dfs = [&](auto self, int u, int fa) -> void {
        siz[u] = maxn[u] = 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            self(self, v, u);

            siz[u] += siz[v];
            maxn[u] = max(maxn[u], siz[v]);
        }
    };

    dfs(dfs, 1, 0);

    cout << siz[1] - maxn[1];
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


// https://atcoder.jp/contests/abc333/tasks/abc333_d
// 2024-09-25