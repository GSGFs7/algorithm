#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
  ???
*/

#define ing long long
const int N = 3e5 + 100;
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    vector<int> f(N);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (1LL * f[i - 1] * i) % MOD;

    int res = f[n];
    for (int i = 0; i < 2; i++) {    // 两次排序，以第一个元素和第二个元素为依据
        sort(a.begin(), a.end());

        // 寻找相同的可以替换的数
        int d = 1;
        int l = 0;
        while (l < n) {
            int r = l + 1;
            while (r < n && a[l].first == a[r].first) r++;
            d = (1LL * d * f[r - l]) % MOD;
            l = r;
        }
        res = (res - d + MOD) % MOD;

        for (auto &i : a) swap(i.first, i.second);
    }

    sort(a.begin(), a.end());

    int l = 0;
    int d = 1;
    while (l < n) {
        int r = l + 1;
        while (r < n && a[l].first == a[r].first) r++;
        map<int, int> mp;
        for (int i = l; i < r; i++) mp[a[i].second]++;
        for (auto i : mp) d = (1LL * d * f[i.second]) % MOD;
        l = r;
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1].second > a[i].second) d = 0;
    }
    cout << (res + d) % MOD << '\n';
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


// https://codeforces.com/contest/1207/problem/D
// 2024-09-23