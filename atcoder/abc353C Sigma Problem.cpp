#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出n个数, 求(a[i]+a[j])%1e8的和

  思路:
    对每个数二分, 看后面有多少个数是需要减去1e8的, 计算最大结果后减去即可
    赛后秒出
*/

#define int long long

void solve() {
    int n, m = 100000000;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());
    // cout << a.back() << '\n';

    // auto find = [&](int x){// 不含
    //     int l = 0, r = n;
    //     int mid = (l + r) >> 1;
    //     while (l < r) {
    //         if (a[mid] >= x) r = l;
    //         else l = r + 1;
    //     }
    //     return l - 1;
    // };
    // cout << find(2);

    int ans = 0;
    int cnt = 0;
    for (auto i = a.begin(); i != a.end(); i++) {
        // 不含
        // cout << max(n - (lower_bound(i, a.end(), m - *i) - a.begin()) - 1, 0LL) << '\n';
        if (*i * 2 < m) cnt += max(n - (lower_bound(i, a.end(), m - *i) - a.begin()), 0LL);
        else cnt += max(n - (lower_bound(i, a.end(), m - *i) - a.begin()) - 1, 0LL);
    }

    for (int i = 0; i < n; i++) {
        ans += a[i] * (n - 1);
    }
    // cout << ans << '\n';
    // cout << cnt << '\n';
    cout << ans - cnt * m << '\n';
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


// https://atcoder.jp/contests/abc353/tasks/abc353_c
// 2024年5月11日