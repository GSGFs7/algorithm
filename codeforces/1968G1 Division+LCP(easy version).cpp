#include <cstring>
#include <iostream>

using namespace std;

/*
  给出一个字符串, 求分成k块的情况下的最长公共前缀
    如: abababcab 就可以分成 ab|ab|abc|ab 相同的前缀是ab

  思路:
    K函数+二分
    k函数O(n), 二分O(nlogn), 总复杂度O(nlogn)
    题目要求最长公共前缀(LCP), 可以直接用Z函数求出从每个位置开始与原串的LCP, 然后二分枚举答案
*/

const int N = 3e5 + 10;
int z[N];

void solve() {
    int n, k;
    cin >> n >> k >> k;    // 需要截成k段
    string temp;
    cin >> temp;
    string s = ' ' + temp;

    // Z函数
    z[1] = n;
    for (int i = 2, l, r = 0; i <= n; i++) {
        if (i <= r)
            z[i] = min(z[i - l + 1], r - i + 1);
        else
            z[i] = 0;
        while (s[i + z[i]] == s[1 + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;    // 漏了个l=i, T了三发
    }

    for (int i = 1; i <= n; i++) cout << z[i] << '\t';
    cout << '\n';

    // 二分
    int L = 1, R = n / k + 1;
    while (L < R) {
        int mid = (L + R) >> 1;    // 二分距离, 假设前缀就是mid
        int cnt = 0;
        for (int i = 1; i <= n; i++) {    // 如果没有找到, 将其视为上一个串的一部分, 继续向后
            if (z[i] >= mid) {            // 如果这里开始的后缀满足条件, 超过了待匹配的数量
                i = i + mid - 1;          // 跳到下一个开始的位置
                cnt++;
            }
        }
        if (cnt < k)
            R = mid;    // 如果不匹配就缩小范围
        else
            L = mid + 1;
    }
    cout << L - 1 << '\n';
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


// https://codeforces.com/contest/1968/problem/G1
// 2024年5月9日