#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

/*
  给出两个数组, 求如何操作使同时交换两个数组相同下标位置的值后, a和b都单调不减

  思路:
    6, 暴力
    数据大小只有100
*/

typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pii> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.push_back({i, j});
            } else if (a[i] == a[j] && b[i] > b[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.push_back({i, j});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) return cout << -1 << '\n', void();
        if (b[i - 1] > b[i]) return cout << -1 << '\n', void();
    }

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
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


// https://codeforces.com/contest/1681/problem/C
// 2024年5月24日