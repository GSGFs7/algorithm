#include <bits/stdc++.h>

using namespace std;

/*
  给出一个矩形的三条边和另一个矩形的体积, 求存在多少种方案将后面一个矩形放入前面的内部
*/

typedef long long ll;

void solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll ans = 0;
    for (ll i = 1; i <= x; i++) {    // 暴力枚举其中发两条边
        for (ll j = 1; j <= y; j++) {
            ll sum = i * j;
            if (k % sum == 0) {    // 如果可以整除, 也就是说存在第三条边
                ll a = k / sum;
                // 所有可能法案全部相乘
                ans = max(ans, (x - i + 1) * (y - j + 1) * (z - a + 1));
            }
        }
    }
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


// https://codeforces.com/contest/1985/problem/E#include <bits/stdc++.h>

using namespace std;

/*
  给出一个矩形的三条边和另一个矩形的体积, 求存在多少种方案将后面一个矩形放入前面的内部
*/

typedef long long ll;

void solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll ans = 0;
    for (ll i = 1; i <= x; i++) {    // 暴力枚举其中发两条边
        for (ll j = 1; j <= y; j++) {
            ll sum = i * j;
            if (k % sum == 0) {    // 如果可以整除, 也就是说存在第三条边
                ll a = k / sum;
                // 所有可能法案全部相乘
                ans = max(ans, (x - i + 1) * (y - j + 1) * (z - a + 1));
            }
        }
    }
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


// https://codeforces.com/contest/1985/problem/E
// 2024年6月12日