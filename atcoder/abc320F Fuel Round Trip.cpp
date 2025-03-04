#include <bits/stdc++.h>

using namespace std;

// 三维DP
/*
 * 在一条数轴上有n+1个点 有n个加油站 可以花钱在加油站加油
 * 问从0开始到最后一个点然后在回到0的最小花费
 *
 *
 * */

#define int long long
const int N = 310;
// dp[i][j][k] 表示路过第i个加油站的时候 出发的油量为j 返回的油量为k 时的最小花费
int dp[N][N][N];

void solve() {
    memset(&dp, 0x3f, sizeof(dp));

    int n, h;
    cin >> n >> h;
    vector<int> x(n + 1);
    vector<int> p(n), f(n);
    for (int i = 1; i <= n; i++) cin >> x[i];           // 点位
    for (int i = 1; i < n; i++) cin >> p[i] >> f[i];    // 花费 加油量
    for (int i = 0; i <= h; i++) dp[n][i][i] = 0;

    for (int i = n - 1; ~i; i--) {
        for (int j = 0; j <= h; j++) {
            for (int k = 0; k <= h; k++) {
                int dis = x[i + 1] - x[i];
                if (j + dis > h) continue;
                if (k < dis) continue;

                int tmp = dp[i + 1][j][k];
                // 啥事不干
                dp[i][j + dis][k - dis] = min(dp[i][j + dis][k - dis], tmp);
                // 去的时候加油
                dp[i][max(j + dis - f[i], 0ll)][k - dis] =
                    min(dp[i][j + dis - f[i]][k - dis], tmp + p[i]);
                // 回的时候加油
                dp[i][j + dis][min(k - dis + f[i], h)] =
                    min(dp[i][j + dis][min(k - dis + f[i], h)], tmp + p[i]);
            }
        }

        for (int j = 1; j <= h; j++) {
            for (int k = h; k; k--) {
                dp[i][j][k] = min(
                    {dp[i][j][k], dp[i][j - 1][k + 1], dp[i][j][k + 1], dp[i][j - 1][k]});
            }
        }
    }

    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i <= h; i++) ans = min(ans, dp[0][h][i]);
    cout << (ans == 0x3f3f3f3f3f3f3f3f ? -1 : ans) << '\n';
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


// https://atcoder.jp/contests/abc320/tasks/abc320_f
// 2024-10-27
