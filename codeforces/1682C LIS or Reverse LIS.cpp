#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

/*
  给出一个数组, 可以随便排列数组中的元素, 最大化正反两个LIS的较小值

  思路:
    对称, 多余2的没用
    为什么本地跑不了, 死循环
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]]++;

    long long ans = 0;
    int cnt = 0;
    for (auto &i : mp) {
        if (i.second == 1) ans++;
        if (i.second >= 2) ans += 2;
        // cout << i.second << '\n';
        // cnt++;
        // if (cnt == 10) break;
    }
    cout << max((ans + 1) / 2, 1LL) << '\n';
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


// https://codeforces.com/contest/1682/problem/C
// 2024年5月28日