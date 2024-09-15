#include <algorithm>
#include <cmath>
#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;

    sort(a.begin(), a.end());

    vector<int> presum(n);
    presum[0] = a[0].second;
    for (int i = 1; i < n; i++) presum[i] = presum[i - 1] + a[i].second;
    presum.push_back(presum.back());

    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = a[i].first;

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l > r || r < c.front() || l > c.back()) {
            cout << 0 << '\n';
            continue;
        }

        int L = lower_bound(c.begin(), c.end(), l) - c.begin();
        int R = upper_bound(c.begin(), c.end(), r) - c.begin() - 1;

        if (L == 0 && l == c.front()) {
            cout << presum[R] << '\n';
            continue;
        }

        cout << presum[R] - presum[L - 1] << '\n';
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