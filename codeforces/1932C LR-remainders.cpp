#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个数组和一个字符串, 字符串L表示删掉数组最左边一个数, R表示右边
  求在每次删数组之前的状态下的数组元素之积对m取模的结果

  反过来!!!
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    string s;
    cin >> s;
    int l = 1, r = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') l++;
        if (s[i] == 'R') r--;
    }

    int mul = 1;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            mul *= a[--l];
            mul %= m;
            ans.push_back(mul);
        } else {
            mul *= a[++r];
            mul %= m;
        ans.push_back(mul);
        }
    }
    for (auto i = ans.rbegin(); i != ans.rend(); i++) cout << *i << ' ';
    cout << '\n';
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


// https://codeforces.com/contest/1932/problem/C
// 2024年5月20日