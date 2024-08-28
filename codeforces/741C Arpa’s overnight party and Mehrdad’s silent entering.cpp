#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个圆环，有黑白两种颜色，a[i]和b[i]之间颜色必须不同
  同时在环上相邻的三个点也不能全都是同一个颜色，求可行的方案

  很明显的二分图，使用黑白染色来处理图上的每个节点
  只是在处理环上相邻三个点的时候有点麻烦，因为是三个人不能全部相同
  也就是说必须有两个人之间存在一条边，使这两个人不是同一种颜色
  因为边只表示这两个点颜色不相同，在三个相邻的点中可以任选两个连边
*/

const int N = 2e5 + 10;
vector<int> G[N];
bool vis[N];
int col[N];

// dfs染色
void dfs(int u, int fa) {
    if (col[u] != 0) {
        if (col[u] == col[fa]) {
            cout << -1 << '\n';
            exit(0);
        }
    }

    if (col[fa] == 1) {
        col[u] = 2;
    } else {
        col[u] = 1;
    }

    for (auto v : G[u]) {
        if (v == fa) continue;
        if ((col[u] == 1 && col[v] == 2) || (col[u] == 2 && col[v] == 1)) continue;

        dfs(v, u);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = {u, v};
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // 每间隔一个位置连一条边
    for (int i = 1; i <= n << 1; i += 2) {
        G[i].push_back(i + 1);
        G[i + 1].push_back(i);
    }

    // 所有点都需要被染上色
    for (int i = 1; i <= 2 * n; i++) {
        if (col[i] == 0) {
            dfs(i, 0);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << col[a[i].first] << ' ' << col[a[i].second] << '\n';
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


// https://codeforces.com/contest/741/problem/C
// 2024年7月28日