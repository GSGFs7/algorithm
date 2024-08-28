#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个n-1位的数组, 表示原数组后一位与前一位取模的结果, 求原数组

  思路:
    对于a>b的两个数, 存在(a+b) mod a=b
    直接第一个数给个大常数, 然后无脑加上模数
    从后面往前看就是一个大数模上一个小数, 结果就是两者的差值(因为很大, 不会出现两倍的情况)
*/

void solve() {
    int n;
    cin >> n;
    int sum = 114514;
    cout << sum << ' ';
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        cout << sum << ' ';
    }
    cout << '\n'; 
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


// https://codeforces.com/contest/1968/problem/C
// 2024年5月3日