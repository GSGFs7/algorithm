#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出n条跑道, 每条跑道有a[i]段, 第一段可以增加u的权值, 第二段u-1...求最大权值
*/

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

    auto calc = [&](int l, int r, int u) {
        int c = pre[r] - pre[l - 1];
        return c * (u + u - c + 1) / 2;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, u;
        cin >> l >> u;

        // 如果可以直接超过右边界
        if (pre[l - 1] + u >= pre[n]) {
            cout << n << ' ', void();
            continue;
        }
        // 如果连一个都跑不完
        if (pre[l - 1] + u < pre[l]) {
            cout << l << ' ', void();
            continue;
        }

        // 二分找到分界点, upper_bound找一个大于的位置(也就是不包含)
        int r = upper_bound(pre.begin(), pre.end(), pre[l - 1] + u) - pre.begin();
        if (calc(l, r, u) > calc(l, r - 1, u)) {
            cout << r << ' ';
            continue;
        } else {
            cout << r - 1 << ' ';
            continue;
        }
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


// https://codeforces.com/contest/1933/problem/E
// 2024年5月20日