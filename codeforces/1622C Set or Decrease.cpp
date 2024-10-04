#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个数组，可以对这个数组进行两种操作
  1.其中一个数减一
  2.将一个数的值赋给另一个
  求使数组的和不大于k需要的最小步骤

  贪心
  减小后再赋值可以得到更多的减少量
  每次减少都应该减少最小值，赋值操作每次都应该从大的开始选，保证最优贪心
  可以使用二分枚举答案进行优化
  但是check函数的复杂度过高，我的思路需要暴力枚举最小值减小量和计算数组和O(n^2)
  看别人代码直接前缀和优化掉了
  离出题就差个后缀和（难过）
*/

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), s(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    // 后缀和
    for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + a[i];

    // 如果直接就小于k
    if (s[0] < k) return cout << "0\n", void();
    // 只有一个数的情况
    if (n == 1) return cout << a[0] - k << '\n', void();

    // 是否可以小于k
    auto check = [&](int x) -> bool {
        // 枚举后缀有多少个数变成最小值
        for (int i = 0; i < n && i <= x; i++) {
            int t = a[0] - (x - i);                    // 减小后的值
            int del = s[n - i] - (t * i) + (x - i);    // 减小的量
            if (s[0] - k <= del) return true;          // 如果大于差值
        }
        return false;
    };    // 喵啊～

    // 二分
    int l = 0, r = s[0] - k;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
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
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1622/problem/C
// 2024-09-29