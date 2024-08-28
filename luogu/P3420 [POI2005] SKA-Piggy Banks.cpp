#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

/*
  并查集板子
*/

using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    iota(++a.begin(), a.end(), 1);

    function<int(int)> find = [&](int x) {
        if (a[x] != x) a[x] = find(a[x]);
        return a[x];
    };

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = find(x);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == a[i]) ans ++;
    }
    cout << ans << '\n';
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


// https://www.luogu.com.cn/problem/P3420
// 2024年4月14日