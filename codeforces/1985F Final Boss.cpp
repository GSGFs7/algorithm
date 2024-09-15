#include <iostream>
#include <vector>

using namespace std;

/*
  BOSS共有h的血量, 第i次攻击可以造成a[i]的伤害和b[i]的后摇问几个回合击败BOSS

    直接二分暴力
*/

#define int long long

void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    auto check = [&](int mid) {
        __int128_t res = 0;    // 经过mid回后合造成的总伤害
        for (int i = 0; i < n; i++) {
            res += __int128_t(1) * a[i] * ((mid - 1) / b[i] + 1);    // 计算伤害
        }
        return res >= h;    // 是否满足要求
    };

    int l = 1, r = 1e18;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
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


// https://codeforces.com/contest/1985/problem/F
// 2024年6月12日