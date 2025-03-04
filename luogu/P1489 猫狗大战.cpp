#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个数组 将数组中的元素分成两组 两组数量上最大相差1 两组之相差最小的和
 *
 * 布尔DP
 * 直接计算插入所有数的情况 最后再使用固定的n/2这一位置的所有情况来求解
 * 设f[i][j][k]表示考虑前面i个数 选入j个数加入一组 最后和为k的情况 是否可行
 * 使用滚动数组压掉第一维 （还可以使用bitset来压掉最后一维）
 * */

void solve() {
    int n;
    cin >> n;
    int tot = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    // f[i][j]表示选出i个来 总和为j的情况 （前面还有一维被滚掉了）
    vector<vector<int>> f(n + 1, vector<int>(tot + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {                   // 枚举考虑前面i个数的情况
        for (int j = (n >> 1) + 1; j >= 1; j--) {    // 枚举选入组中的情况
            for (int k = tot; k >= a[i]; k--) {      // 枚举可能的和
                // 这个点可以由前面一个位置上k-a[i]这个点得到
                f[j][k] |= f[j - 1][k - a[i]];
            }
        }
    }

    // 查找最优解
    for (int i = tot >> 1; i >= 0; i--) {
        if (f[n >> 1][i]) {
            cout << i << ' ' << tot - i << '\n';
            exit(0);
        }
        // 前面的和可能比较小 但是选的数可能多一个
        if (n % 2 && f[(n >> 1) + 1][i]) {
            cout << i << ' ' << tot - i << '\n';
            exit(0);
        }
    }
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


// https://www.luogu.com.cn/problem/P1489
// 2024-10-28
