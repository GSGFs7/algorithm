#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个数组, 任意选择一个区间, 将区间中所有值变成它的中位数, 求最后区间的最大值

  思路:
    题目可以看成从数组中选择一个区间, 求区间最大中位数
    只需要考虑两个数和三个数的情况
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int maxn = 0;
    for (int i = 1; i < n; i++) {    // 如果两个数相邻
        maxn = max(maxn, min(a[i - 1], a[i]));
    }
    for (int i = 0; i < n - 2; i++) {    // 如果是三个数取中间值
        maxn = max(maxn, min(a[i], a[i + 2]));
    }
    cout << maxn << '\n';
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


// https://codeforces.com/contest/1975/problem/C
// 2024年5月26日