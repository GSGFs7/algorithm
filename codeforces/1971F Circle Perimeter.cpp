#include <cmath>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

/*
  给出一个值x, 求在平面直角坐标系上符合欧氏距离大于或等于x但小于x+1的点的个数
    欧氏距离: sqrt(x^2+y^2)

  思路:
    点不会很多, 只有最外层一圈, 直接暴力枚举
    直接暴力枚举x和y的值, 相应的需要设置另一个值的上限(也就是y)来优化
*/

typedef long long ll;

void solve() {
    ll x;
    cin >> x;
    ll r = x;    // 纵坐标y的上限
    ll ans = 0;
    for (ll i = 0; i <= x; i++) {    // 用i表示横坐标x
        // 如果超过了上限, 缩小范围
        while (i * i + r * r >= (x + 1) * (x + 1)) r--;

        // 在第一象限的范围内计算答案的个数
        ll j = r;                                    // 用b表示纵坐标y
        while (i * i + j * j >= x * x && j > 0) {    // 如果符合欧氏距离
            j--;      // x点不动, 看y值是不是还可以有更多的值
            ans++;    // 找到一个值
        }
    }
    cout << ans * 4 << '\n';    // 四个象限
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


// https://codeforces.com/contest/1971/problem/F
// 2024年5月14日