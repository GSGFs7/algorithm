#include <iostream>

using namespace std;

/*
  有n粒沙子，两个人轮流取，一次最多不能取超过k个，且后面取的数量必须为前面的公因数。

  先手取只需要取 lowbit(n) ，然后跟着后手取一样的数量就可以直接卡死后手，
  那么只需要判断k是否大于 lowbit(n) 就可以了
*/

void solve() {
    int n, k;
    cin >> n >> k;
    auto lowbit = [&](int x) { return x & -x; };
    if (lowbit(n) <= k) return cout << "Alice\n", void();
    cout << "Bob\n";
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


// https://codeforces.com/gym/105336
// 2024-09-11