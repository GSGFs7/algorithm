#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using ii = pair<ll, ll>;
using vii = vector<ii>;

void tc() {
    ll n, m;
    cin >> n >> m;
    vector<vll> ve(n, vll(m));    // 原数组
    for (vll &ve2 : ve) {
        for (ll &i : ve2) cin >> i;
    }

    vll vsum(n, 0);    // 这一列的和
    for (ll i = 0; i < n; i++) {
        for (ll j : ve[i]) vsum[i] += j;
    }

    vll th(n);    // 第几大
    iota(th.begin(), th.end(), 0);
    sort(th.begin(), th.end(), [&](ll a, ll b) { return vsum[a] > vsum[b]; });

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += vsum[th[i]] * (n - 1 - i) * m;
    }
    for (vll ve2 : ve) {
        for (ll i = 0; i < m; i++) {
            ans += ve2[i] * (m - i);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll T;
    cin >> T;
    while (T--) {
        tc();
    }
    return 0;
}