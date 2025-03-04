#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<string> s(3);
    for (auto &i : s) cin >> i;

    int ans = 1e9;
    for (int i = 0; i < 10; i++) {    // 枚举是哪个数被选中了
        array<int, 3> id;
        iota(id.begin(), id.end(), 0);
        do {
            int cur = 0;
            int tot = 0;
            for (auto &j : id) {
                if (s[j].find('0' + i) == string::npos) {
                    tot = 1e9;
                    break;
                }

                while (s[j][cur] - '0' != i) {
                    cur = (cur + 1) % m;
                    tot++;
                }
                cur = (cur + 1) % m;
                tot++;
            }
            ans = min(ans, tot);
        } while (next_permutation(id.begin(), id.end()));
    }

    if (ans == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << ans - 1 << '\n';
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


// https://atcoder.jp/contests/abc320/tasks/abc320_c
// 2024-10-23
