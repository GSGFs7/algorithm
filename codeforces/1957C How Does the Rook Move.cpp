#include <iostream>
#include <vector>

using namespace std;

/*
  有一个n*n的空棋盘, 已经预先放置了k个棋子, 每个棋子独占一行一列, 求有多少种放法

  思路:
    DP
    官方题解, 看不懂.
    对于剩下的格子, 有两种放法
        1.对于(i,i)位置的棋子, 只会占据一行一列
        2.对于(i,j)位置的棋子, 因为对手的镜像, 会额外占据一行一列
    因为对称的行列的顺序是对手的镜像, 所以不用考虑, 只有行数才是配置数的关键
    对于每一行同样的存在两种方案
        1.放置在(i,i), 删除一行一列, 退化为(n-1)*(n-1)的棋盘, 贡献为dp[i-1]
        2.放置在(i,j), 删除两行两列, 退化为(n-2)*(n-2)的棋盘, 贡献为2*(i-1)*dp[i-2]

    不管官方题解, 自己照着状态转移方程还原
*/

int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int used = 0;    // 已经使用的行数
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        used += 2 - (r == c);
    }

    int m = n - used;    // 剩下的行数, 直接删掉那些行数, 表示剩下的矩阵大小
    vector<int> dp(m + 1, 0);
    dp[0] = dp[1] = 1;    // 就算没有位置可放也是有一种现成的方案
    // i表示前i*i的矩阵, dp就表示在这样的矩阵下的值
    for (int i = 2; i <= m; i++) {    // 剩下的m行
        // 状态转移方程, (i,i)的情况加上(i,j)的情况
        dp[i] = (dp[i - 1] + 2ll * (i - 1) * dp[i - 2] % MOD) % MOD;    // 真推不出来
    }
    cout << dp[m] << "\n";
    // for (auto i : dp) cout << i << ' ';
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1957/problem/C
// 2024年4月24日