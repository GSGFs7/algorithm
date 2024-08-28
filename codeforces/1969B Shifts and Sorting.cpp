#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
  给出一个01的字符串, 选择中间一段循环右移, 求最小花费

  思路:
    从最左边开始往后移1, 每次都只将一个0移到最前, 可以节省移动次数
    注意: 结果会炸int!!!!!!!!!
*/

void solve() {
    string s;
    cin >> s;
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') cnt ++;
        else {
            if (cnt) ans += cnt + 1;
        }
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


// https://codeforces.com/contest/1969/problem/B
// 2024年5月1日