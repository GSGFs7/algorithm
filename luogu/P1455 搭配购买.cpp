#include <chrono>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

void solve();

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}

/*****************************************************************************/

/*
  给出n个物品, 其中有些需要组合购买, 求可获得的最大价值

  思路:
    直接合并组合的物品, 然后01背包
*/

// #define int long long
typedef long long ll;
typedef pair<int, int> pii;

void debug() {
#ifdef __LOCAL__
#endif
}

/**
 * @brief 代码写这里!!!
 */
void solve() {
    int n, m, W;
    cin >> n >> m >> W;

    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        w[i] = x;
        v[i] = y;
    }

    vector<int> f(n + 1);
    iota(++f.begin(), f.end(), 1);

    function<int(int)> find = [&](int x) {
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    };

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        f[find(u)] = find(v);
    }

    for (int i = 0; i < n; i++) {
        if (f[i] != i) {
            w[find(i)] += w[i];
            v[find(i)] += v[i];
            w[i] = 0;
            v[i] = 0;
        }
    }

    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = W; j > 0; j--) {
            if (j >= w[i]) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[W] << '\n';
}


// https://www.luogu.com.cn/problem/P1455
// 2024年3月27日