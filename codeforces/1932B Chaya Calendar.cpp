#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个数组, 需要将每个数扩大若干倍, 同时后面的数严格大于前面的, 求最后一个数的最小值
*/

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int last = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = 1e9;// 1e9?!
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[i] * mid > last) r = mid;
            else l = mid + 1;
        }
        if (a[i] * (l - 1) > last) last = (l - 1) * a[i];
        else if (a[i] * l > last) last = l * a[i];
        else last = (l + 1) * a[i];
    }
    cout << last << '\n';
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


// https://codeforces.com/contest/1932/problem/B
// 2024年5月20日