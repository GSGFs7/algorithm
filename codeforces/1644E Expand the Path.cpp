#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个n*n矩形和一个字符串表示运动方向，从左上角开始，只有右和下两种方向
 * 每次运动只能走一格，现在可以任意的将一个方向在原位复制一份，问图上有多少个点是可以抵达的
 *
 * 模拟
 * 每次找最小需要删除的点，从两个方向来计算
 */

#define int long long

int find(string s, int n) {
    int l = s.find('R');
    int res = l * (n - 1);    // 抵达不了的地方
    int cnt = 0;
    // 从后面向前开始找，找出最的方法使覆盖最大
    for (int i = s.length() - 1; i > l; i--) {
        if (s[i] == 'D') {
            res += cnt;
        } else {
            cnt++;    // 最小化损耗
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // 如果根本无法进行操作
    if (s == string(s.size(), s[0])) {    // 如果不能进行操作
        cout << n << "\n";
        return;
    }


    int ans = n * n;
    ans -= find(s, n);

    // 换个方向
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'R') {
            s[i] = 'D';
        } else {
            s[i] = 'R';
        }
    }
    ans -= find(s, n);
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
