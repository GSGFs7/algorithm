#include <iostream>
#include <vector>

using namespace std;

/*
  dp
*/

typedef long long ll;

void solve() {
    ll m, x;
    cin >> m >> x;
    vector<ll> c(m + 1), h(m + 1);
    int sum = 0;
    for (int i = 1; i <= m; i++) cin >> c[i] >> h[i], sum += h[i];

    vector<ll> f(sum + 1, 1e18);
    f[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = sum; j >= h[i]; j--) {
            if (f[j - h[i]] + c[i] <= (i - 1) * x)
                f[j] = min(f[j], f[j - h[i]] + c[i]);
        }
    }

    for (int i = sum; i >= 0; i--) {
        if (f[i] <= (m - 1) * x) {
            return cout << i << '\n', void();
        }
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


// https://codeforces.com/contest/1974/problem/E
// 2024年6月10日