#include <iostream>

using namespace std;

const int N = 110;
int z[N];

//! at most once !!!!!

// Z函数
void get_z(string s) {
    z[1] = s.size() - 1;
    for (int i = 2, l, r = 0; i < s.size(); i++) {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);    // 如果在盒子里, 在直接复制
        while (s[1 + z[i]] == s[i + z[i]]) z[i]++;        // 如果匹配, 向后移动
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;    // 如果超出了盒子的范围
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    // 没有用
    // get_z(s);

    // for (int i = 1; i <= n; i++) cout << z[i] << ' ';
    // cout << '\n';

    // int maxn = 0;
    // for (int i = 3; i <= n; i++) {
    //     if (z[i] + 1 >= i - 1) {
    //         maxn = max(maxn, min(z[i] + 1, i - 1) - 1);
    //     }
    // }
    // cout << n - maxn;

    int maxn = 0;
    for (int i = 1; i < n; i++) {
        if (i * 2 > n) break;
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if (s[j] != s[i + j]) {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        maxn = max(maxn, i);
        // cout << i << ':' << maxn << '\n';
    }
    cout << n - (maxn ? maxn - 1 : 0);
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

/*
4
aaaa

10
ababcababc
*/


// https://codeforces.com/contest/954/problem/B
// 2024-09-16