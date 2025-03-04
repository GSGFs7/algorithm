#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    // 检查这个点开始的字符串是否是 "ABC"
    auto check = [&](int x) {
        for (int i = 0; i < 3; i++) {
            if (x + i < 0 || n <= x + i || s[x + i] != 'A' + i) {
                return false;
            }
        }
        return true;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) ans += check(i);    // 初始状态的答案
    while (q--) {
        int x;
        string c;
        cin >> x >> c;
        x--;
        // 删除原有的
        for (int i = x - 2; i <= x; i++) {
            ans -= check(i);
        }
        // 添加新增的
        s[x] = c[0];
        for (int i = x - 2; i <= x; i++) {
            ans += check(i);
        }
        cout << ans << '\n';
    }
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
