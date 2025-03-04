#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个n 求1/x+1/y=1/n的解的个数 x和y都是正整数
 *
 * 转化为求n^2的质因子的组合的个数
 * */

void solve() {
    int n;
    cin >> n;
    int ans = 1;
    int m = sqrt(n);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {    // 寻找质因子
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            ans *= (cnt * 2 + 1);    // 可行的方案数
        }
    }
    if (n > 1) ans *= 3;
    cout << ans / 2 + 1 << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
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


// https://ac.nowcoder.com/acm/contest/93583/C
// 2024-10-22
