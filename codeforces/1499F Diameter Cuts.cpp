#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一棵树，删掉一些边后使剩下的部分直径不超过k，问这样的方法有多少个

  树上DP
*/

#define int long long
const int N = 5010;
const int MOD = 998244353;
vector<int> g[N];
int dp[N][N];    // dp[i][j]表示以i为根长度为j的子树的方案数
int k;

int dfs(int u, int fa) {
    dp[u][0] = 1;
    int l = 0;    // 长度
    for (auto v : g[u]) {
        if (v == fa) continue;

        int vl = dfs(v, u);
        vector<int> tmp(max(l, vl + 1) + 1, 0);
        for (int i = 0; i <= l; i++) {
            for (int j = 0; j <= vl; j++) {
                // 只取不大于k的长度，就不需要再考虑k的限制了
                if (i + j + 1 <= k) {    // 如果i和j相接后依旧没有达到k的长度限制
                    tmp[max(i, j + 1)] += dp[u][i] * dp[v][j] % MOD;
                    tmp[max(i, j + 1)] %= MOD;
                }
                if (i <= k && j <= k) {    // i与b不相接
                    tmp[i] += dp[u][i] * dp[v][j] % MOD;
                    tmp[i] %= MOD;
                }
            }
        }

        l = max(l, vl + 1);

        for (int i = 0; i <= l; i++) dp[u][i] = tmp[i];
    }
    return l;
}

void solve() {
    int n;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);

    int ans = 0;
    for (int i = 0; i <= k; i++) ans = (ans + dp[0][i]) % MOD;
    cout << ans << '\n';
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


// https://codeforces.com/contest/1499/problem/F
// 2024-10-01