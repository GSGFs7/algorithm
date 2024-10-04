#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> pos(n), a(n);
    for (int i = 0; i < n; i++) cin >> pos[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    // 本来就是有序的
    // sort(a.begin(), a.end());

    vector<int> sum(n);
    sum[0] = a[0];
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
    // partial_sum(a.begin(), a.end(), sum.begin());

    auto get_sum = [&](int L, int R) {
        if (L > R) return 0LL;
        return sum[R] - (L ? sum[L - 1] : 0);
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        auto R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
        cout << get_sum(L, R - 1) << '\n';
        // MD，跟这道题爆了，R-1是可能小于L的
        // 就差最后一个点，卡了好久
    }
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


// https://atcoder.jp/contests/abc371/tasks/abc371_d
// 2024-09-16