#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
  给出一个图，可以在图上一个地方买东西，在另一个地方卖掉，求最大收获

  思路：
    因为图上岔路很多，直接DFS或是BFS必炸
    可以先预处理一遍，
    处理出到每个点的最小价值（买入点）和最大价值（卖出点）
    对于同一个点，它的最大值和最小值必定是可以相互抵达的（如果有更好的情况也会被扩散过来）
    直接用点来判断即可

    正着跑一遍SPFA，求出到每个点携带的最小价值
    再反着跑一遍SPFA，求出到每个点携带的最大价值
    最后每个点最大值减去最小值
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> g(n + 1), gf(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, op;
        cin >> u >> v >> op;
        g[u].push_back(v);
        gf[v].push_back(u);
        if (op == 2) {
            g[v].push_back(u);
            gf[u].push_back(v);
        }
    }

    // 最小值
    vector<int> minn(n + 1, 1e9);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        minn[u] = min(minn[u], a[u]);    // 带上这个点原本的值是否会更小

        for (auto i : g[u]) {
            if (minn[i] > minn[u]) {
                minn[i] = minn[u];    // 向可通向的大边扩散
                q.push(i);
            }
        }
    }

    // 最大值
    vector<int> maxn(n + 1, 0);
    q.push(n);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        maxn[u] = max(maxn[u], a[u]);

        for (auto i : gf[u]) {
            if (maxn[i] < maxn[u]) {
                maxn[i] = maxn[u];
                q.push(i);
            }
        }
    }

    // 不用在乎起点和终点是谁，因为会扩散最大值和最小值
    // 最大和最小的地方如果真的可以相遇的话，肯定会在一个点重叠
    // 我们要找的就是这个点，也就是说它的路径我们并不知晓
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, maxn[i] - minn[i]);    // 在可达的情况下的最大差值
    }
    cout << ans << '\n';

    // for (int i = 1; i <= n; i++) cout << maxn[i] << '\t';
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << minn[i] << '\t';
    // cout << '\n';
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


// https://www.luogu.com.cn/problem/P1073
// 2024年4月2日