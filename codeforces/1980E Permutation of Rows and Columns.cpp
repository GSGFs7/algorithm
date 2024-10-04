#include <iostream>
#include <vector>

using namespace std;

/*
  给出两个矩阵，矩阵的内容是一个排列，每次可以交换一整行或是一整列
  问是否可以由一个矩阵得到另一个
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[x] = {i, j};
        }
    }
    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    // 直接大力跑每个点进行标记，看是否有重复
    vector<int> row(n + 1, -1);
    vector<int> col(m + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = b[i][j];
            int r = a[x].first;
            int c = a[x].second;
            if (row[r] != -1 && row[r] != i) return cout << "No\n", void();
            if (col[c] != -1 && col[c] != j) return cout << "No\n", void();
            row[r] = i;
            col[c] = j;
        }
    }
    cout << "Yes\n";
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


// https://codeforces.com/contest/1980/problem/E
// 2024-09-28