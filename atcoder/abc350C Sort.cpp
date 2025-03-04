#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个数组 问如何在交换两个数的情况下进行排序 使操作数最小
 *
 * 直接模拟交换的操作即可
 * 傻B题 差点红了
 * */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> f, p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]] = i;
        p[i] = a[i];
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) {
            ans.push_back({i, f[i]});

            // 根据题意进行模拟
            int tmp = p[i];
            p[f[i]] = tmp;    // 把这个位置上的数换到其他地方
            p[i] = i;         // 变成i
            f[tmp] = f[i];
            f[i] = i;
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first << ' ' << i.second << '\n';
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


// https://atcoder.jp/contests/abc350/tasks/abc350_c
// 2024-10-18
