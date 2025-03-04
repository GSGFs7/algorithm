#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个数组，选取其中所有的区间，问区间中不同数字数量之和是多少
 *
 * ?
 * */

#define int long long

void solve() {
    int n;
    cin >> n;
    map<int, int> last;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ans += (i - last[x]) * (n - i + 1);
        last[x] = i;
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
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


// https://atcoder.jp/contests/abc371/tasks/abc371_e
// 2024-11-26
