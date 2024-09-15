#include <iostream>
#include <vector>

using namespace std;
#define int long long

/*
  给出一个数组, 然后依次左右减一, 到0就删掉, 求最后删掉的数

  思路:
    求前缀和和后缀和, 看能够删掉多少的前后缀和
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (auto i = 1; i <= n; i++) cin >> a[i];

    // 前后缀和
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];

    // 如果不够的
    if (pre[n] <= k) return cout << n << '\n', void();

    // 看能走多远
    int l = (k + 1) >> 1, r = k >> 1;
    int p1 = 0, p2 = n + 1;
    for (int i = 1; i <= n; i++) {
        if (pre[i] <= l) p1++;
        if (suf[i] <= r) p2--;
    }
    cout << p1 + n - p2 + 1 << '\n';
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


// https://codeforces.com/contest/1955/problem/C
// 2024年5月17日