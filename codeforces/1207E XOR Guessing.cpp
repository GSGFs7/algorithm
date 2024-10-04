#include <cstdio>
#include <iostream>

using namespace std;

/*
  交互题，求未知数x，一次查询输出一百个整数，得到x与其中一个数的异或，一共可以查询两次
  0<=x<=2e14-1

  x异或上0就可以得到对应位置上的值
  一次前面全是0，一次后面全是0，与起来就是结果了
*/

void solve() {
    // 后面全是0
    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << i * 128 << ' ';
    }
    cout << endl;

    int x;
    cin >> x;
    if (x == -1) return cout << -1 << endl, void();
    int ans1 = 127 & x;

    // 前面全是0
    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << i << ' ';
    }
    cout << endl;

    cin >> x;
    if (x == -1) return cout << -1 << endl, void();
    int ans2 = 16256 & x;

    cout << "! " << (ans1 | ans2) << endl;
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


// https://codeforces.com/contest/1207/problem/E
// 2024-09-23