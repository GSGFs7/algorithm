#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
  两次离散化
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (int &i : a) {
        cin >> i;
        mp[i]++;
    }

    vector<int> b;
    for (auto i : mp) {
        if (i.second >= k) b.push_back(i.first);
    }
    sort(b.begin(), b.end());

    // for (auto i : b) cout << i << ' ';
    // cout << '\n';

    if (b.size() == 0) return cout << -1 << '\n', void();

    int cnt = 1;
    int ans = 1;
    int l = b.front(), r = b.front();
    int ansL = b.front(), ansR = b.front();
    for (int i = 1; i < b.size(); i++) {
        if (b[i - 1] + 1 == b[i]) {
            cnt++;
            r = b[i];
        } else {
            cnt = 1;
            l = r = b[i];
        }
        if (cnt > ans) {
            ans = cnt;
            ansL = l;
            ansR = r;
        }
    }
    // cout << ans << '\n';
    cout << ansL << ' ' << ansR << '\n';
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


// https://codeforces.com/contest/1676/problem/F  1300
// 2024-09-17