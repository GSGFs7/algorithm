#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

/*
  给出一个数组, 求有多少个连续的三个数中只有一个位置上的值不同

  思路:
    把有两个值相同的数全部放在一起, 排序后找有计算
*/

// #define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<piii, vector<int>> mp;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 2; i++) {    // n少了-2, 混进了奇怪的东西
        mp[{1, {a[i], a[i + 1]}}].push_back(a[i + 2]);
        mp[{2, {a[i], a[i + 2]}}].push_back(a[i + 1]);
        mp[{3, {a[i + 1], a[i + 2]}}].push_back(a[i]);
    }

    long long ans = 0;
    for (auto [t, v] : mp) {
        sort(v.begin(), v.end());
        int l = 0;
        while (l < v.size()) {
            int len = 1;    // 找到这个数有多少相同的数
            while (l + len < v.size() && v[l] == v[l + len]) len++;
            ans += (v.size() - len) * (len);
            l += len;
        }
        // cout << t.first << ' ' << t.second.first << ' ' << t.second.second <<
        // '\n'; cout << ans << '\n';
    }
    cout << ans / 2 << '\n';    // 正反算了两遍
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


// https://codeforces.com/contest/1974/problem/C
// 2024年5月21日