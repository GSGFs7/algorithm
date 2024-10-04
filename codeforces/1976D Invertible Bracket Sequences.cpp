#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
  给出一个括号序列，求将其中一段全部反过来后，整个序列依旧合法的情况数
*/

void solve() {
    string s;
    cin >> s;
    map<int, int> mp;
    vector<int> cnt(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); i++) {
        if (s[i - 1] == '(') {
            cnt[i] = cnt[i - 1] + 1;    // 记录状态
        } else {
            cnt[i] = cnt[i - 1] - 1;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= s.size(); i++) {
        ans += mp[cnt[i]];    // 组合，同样的状态有多少个
        mp[cnt[i]]++;
        if (cnt[i] > 0) mp[(cnt[i] - 1) / 2] = 0;    // ?
    }
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1976/problem/D
// 2024-09-28