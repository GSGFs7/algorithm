#include <iostream>
#include <vector>

using namespace std;

/*
  给出一排卡牌，卡牌两面都写有数字，可以任意翻转卡牌，问卡牌间两两间不相同的情况有多少个

  艹，读错题了，因为是所有的都不相同
  简单DP
*/

#define int long long
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &i : a) cin >> i.first >> i.second;

    vector<int> dp(2, 1);
    for (int i = 1; i < n; i++) {    // 从前往后递推
        vector<int> tmp(2, 0);
        // 如果可以从这一面翻转得到的话就继承这里的结果
        if (a[i].first != a[i - 1].first) tmp[0] += dp[0];
        if (a[i].first != a[i - 1].second) tmp[0] += dp[1];
        if (a[i].second != a[i - 1].first) tmp[1] += dp[0];
        if (a[i].second != a[i - 1].second) tmp[1] += dp[1];
        tmp[0] %= MOD;
        tmp[1] %= MOD;
        dp.swap(tmp);
    }
    cout << (dp[0] + dp[1]) % MOD << '\n';
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


// https://atcoder.jp/contests/abc291/tasks/abc291_d
// 2024-10-02