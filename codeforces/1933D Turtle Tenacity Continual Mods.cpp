#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

/*
  给出一个数组, 可以将其重新排列, 求是否有一种方法使所有数依次取模后不为0

  思路:
    第一个样例说的很清楚, 只要是单调递增的, 后面就可以省略
    因此, 只需要找出一个只出现一次的最小的数(可以是两个数取模的结果)
    如果这个数存在, 那么就存在一个可行解
    无论后面比这个数大的数怎么取模自己都不会有变化
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());

    // 如果已经存在了
    if (a[0] < a[1]) return cout << "YES\n", void();

    for (int i = 1; i < n; i++) {
        // 正反都需要
        if (a[0] % a[i] < a[0] && a[0] % a[i]) return cout << "YES\n", void();
        if (a[i] % a[0] < a[0] && a[i] % a[0]) return cout << "YES\n", void();
    }
    
    cout << "NO\n";
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


// https://codeforces.com/contest/1933/problem/D
// 2024年5月20日