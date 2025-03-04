#include <iostream>
#include <vector>

using namespace std;

/*
 * 给出n个人，中间有m对仇敌，分成t组，仇敌不再同一组的方法有多少个
 * n<=10
 *
 * 数据范围极其之小。直接大力枚举所有方案
 * */

void solve() {
    int n, t, m;
    cin >> n >> t >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    int ans = 0;
    vector<int> c(n);

    // 深搜，枚举各种方案
    auto dfs = [&](auto self, int x, int y) {
        if (x == n) {
            if (y != t) return;

            bool ok = true;
            for (int i = 0; i < m; i++) {
                if (c[a[i]] == c[b[i]]) ok = false;
            }
            ans += ok;
            return;
        }

        // 看第x个人分到哪一个组里
        // y的作用是剪枝，最后如果没有达到t组的话直接返回
        for (int i = 0; i <= y; i++) {
            c[x] = i;
            self(self, x + 1, max(y, i + 1));
        }
    };

    dfs(dfs, 0, 0);
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


// https://atcoder.jp/contests/abc310/tasks/abc310_d
// 2024-10-10
