#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个整数N有两种操作
 *  1. 将N变成 N/A 并向下取整
 *  2. 掷出骰子，将N除以点数并向下取整
 *
 * 概率DP
 * 设将i变成0的最小期望花费为dp[i]
 * 操作1的期望： dp[i]=dp[i/A]+x
 * 操作2的期望： dp[i]=(dp[i]+dp[i/2]+dp[i/3]+dp[i/4]+dp[i/5]+dp[i/6])/6+y
 * 操作2化简可以得到： dp[i]=(dp[i/2]+dp[i/3]+dp[i/4]+dp[i/5]+dp[i/6])*5+y/6*5
 * 上式可以通过移相dp[i]得到左边就变成了 5/6*dp[i]
 * 也就是对于每次DP操作都需要取上述两个操作的较小值
 * */

#define int long long
map<int, double> dp;
map<int, int> vis;
set<int> st;
int n, A, x, y;

// 记忆化搜索
void dfs(int u) {
    st.insert(u);    // 加入到小根堆中
    vis[u] = 1;      // 标记出现
    for (int i = 2; i <= 6; i++) {
        if (u / i > 0 && !vis[u / i]) dfs(u / i);    // 继续向下
    }
}

void solve() {
    cin >> n >> A >> x >> y;

    // 记忆化记录所有可能的情况
    dfs(n);

    dp[0] = 0;
    while (!st.empty()) {
        int u = *st.begin();    // 从小的数开始向后DP
        st.erase(u);

        // 是否已经得到答案
        if (u > n) break;

        // 使用操作一的情况
        dp[u] = dp[u / A] + x;

        // 使用操作二的情况
        double sum = 0;
        for (int i = 2; i <= 6; i++) {
            sum += dp[u / i] / 5;
        }
        sum += (6.0 * y) / 5;
        dp[u] = min(dp[u], sum);
    }

    cout << fixed << setprecision(9) << dp[n] << '\n';
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


// https://atcoder.jp/contests/abc350/tasks/abc350_e
// 2024-10-19
