#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
  有1~n张牌, 第一次选择所有的奇数牌, 第二次选择所有奇数的2倍, 第三次3倍, 求第k个数

  然后?
*/

void solve() {
    int n, k;
    cin >> n >> k;
    int a = 1, b = 2;
    while (true) {
        int cnt = (n - a) / b + 1;     // 这一层的个数
        // cout << "_:" << cnt << ' ';    // 每次都是上一次的二分之一
        if (cnt >= k) {                // 如果这一层达到全部k个数
            cout << (k - 1) * b + a << '\n';
            return;
        }
        k -= cnt;
        a *= 2, b *= 2;
    }
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


// https://codeforces.com/contest/1926/problem/E
// 2024年5月10日