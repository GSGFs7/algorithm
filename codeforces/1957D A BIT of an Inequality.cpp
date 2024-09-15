#include <bits/stdc++.h>

using namespace std;

/*
  给出一个数组, 求a[x]到a[y]的异或 异或上 a[y]到a[z]的异或 的最大数量
  要求上述异或和大于a[x]到a[z]的异或

  思路:
    a[x]到a[y]的异或 异或上 a[y]到a[z]的异或 就是a[x]到a[z]的异或去掉a[y]
    也就是说, 题目要求a[x]到a[y]的异或中删掉a[y]的最大数量
*/

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);    // 原数组
    vector<int> s(n + 1);    // 前缀异或
    vector<vector<int>> c(30, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
        for (int j = 0; j < 30; j++) {
            // 将前缀异或右移j位后的值
            c[j][i] = c[j][i - 1] + (s[i] >> j & 1);    // 预处理s在第j位的1的个数
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = 29;
        while (k >= 0 && (a[i] >> k & 1) == 0) k--;    // 找到最高位的1
        if (k == -1) continue;// 如果没有1

        // 前面可取的范围是0到i-1, 后面可取的范围是i到n
        // 可取的所有情况就是0的个数乘以1的个数
        ans += (c[k][n] - c[k][i - 1]) * c[k][i - 1];
        ans += (n - i + 1 - (c[k][n] - c[k][i - 1])) * (i - c[k][i - 1]);
    }
    cout << ans << '\n';
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


// https://codeforces.com/contest/1957/problem/D
// 2024年4月28日