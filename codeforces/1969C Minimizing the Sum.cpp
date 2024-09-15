#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
#define int long long

/*
  给出一个数组, 每次操作可以使其中一个元素变成旁边那个数, 求最小数组和

  思路:
    DP
    找到可以更新的最小值, 然后以之前的结果为基础更新
*/

const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {                    // 只考虑前i个数的情况
        for (int j = 0; j <= min(i - 1, m); j++) {    // 操作的下标
            for (int k = 0; k <= j; k++) {            // k的循环, 表示操作次数
                // 在k的范围内找到最小值并更新
                int minn = a[i];
                for (int t = i; t >= i - k; t--) minn = min(a[t], minn);    // 向前找最小的值
                dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + (k + 1) * minn);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= m; i++) ans = min(ans, dp[n][i]);    // 所有操作中的最小值
    cout << ans << endl;
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1969/problem/C
// 2024年5月3日