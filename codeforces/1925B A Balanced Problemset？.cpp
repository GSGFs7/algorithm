#include <iostream>
#include <vector>

using namespace std;
#define int long long

/*
 * 题目描述:
 *  给出一个x, 将x划分为n个数, 求这n个数的最大gcd
 * 输入:
 *  一行两个整数x, n
 * 输出:
 *  一行一个整数, 表示答案
 *
 * 思路:
 *  设划分出来的(k1,k2...kn)的gcd是g, 那么就会有以下规律
 *  x模上g会得到一个整数, 并且这个整数是不小于n的(不然不够分)
 *  因为k1,k2...kn都是g的倍数,那他们的和也会是g的倍数
 *  然后就解出来了?
 * */

void solve() {
    int x, n;
    cin >> x >> n;

    int ans = 0;
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            if (x / i >= n) ans = max(ans, i);
            if (i >= n) ans = max(ans, x / i);
        }
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}