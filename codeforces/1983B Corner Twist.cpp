#include <bits/stdc++.h>

using namespace std;

/*
  给出两个矩形, 可以在矩形中选取一个小矩形区域, 使这个区域的一个对角加1并模上3,
  使另一个对角加上2并模上3, 求是否可以通过低一个矩形得到第二个矩形

  因为需要使一个一个对角+1, 一个+2, 然后模3
  对于一个相邻的角而言这一列(行)整体加上了三, 因为又是取模上三的结果
  直接从变化前后模上三是否依旧相等来判断即可
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    vector<vector<char>> b(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    // 求出行与列的值
    vector<int> ax(n + 1), ay(m + 1);
    vector<int> bx(n + 1), by(m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ax[i] += a[i][j] - '0';
            bx[i] += b[i][j] - '0';
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            ay[j] += a[i][j] - '0';
            by[j] += b[i][j] - '0';
        }
    }

    // for (int i = 1; i <= n; i++) cout << x[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= m; i++) cout << y[i] << ' ';
    // cout << "\n\n";

    // 看是否依旧保持原来模三的值
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (ax[i] % 3 != bx[i] % 3) flag = false;
    }
    for (int i = 1; i <= m; i++) {
        if (ay[i] % 3 != by[i] % 3) flag = false;
    }
    if (flag) return cout << "Yes\n", void();
    cout << "No\n";
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


// https://codeforces.com/contest/1983/problem/B
// 2024年7月12日