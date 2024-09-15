#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define int long long

void solve() {
    int mod = 998244353;

    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]]++;

    sort(a.begin(), a.end());

    int ans1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans1 += a[j] - a[i];
        }
    }

    vector<int> b(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        b[i] = (b[i - 1] * i) % mod;
    }
    // for (auto i : b) cout << i << ' ';
    // cout << endl;

    __int128 ans2 = min((int)mp.size(), 2LL);    // 从小到大和从大到小两个方向
    for (auto i : mp) {
        ans2 = ((__int128)1 * ans2 * b[i.second]) % mod;
    }

    cout << ans1 << ' ' << (int)ans2 % mod << '\n';
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


// https://codeforces.com/gym/105336
// 2024-09-11