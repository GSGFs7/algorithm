#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

void solve() {
    int n, m;
    cin >> n >> m;
    int Sx, Sy;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                Sx = i;
                Sy = j;
            }
        }
    }

    /// 判断S位于矩形的上下边界的情况
    // S所在的这一列可以取的范围
    vector<pii> row(n + 1);
    for (int i = 1; i <= n; i++) {
        int left = Sy, right = Sx;
        while (--left > 0&& g[i][left] != '#');
        while (++right <= m && g[i][right] != '#');
        row[i] = {left, right};
    }

    // 如果S位于上边界, 枚举矩形的下边界
    int left = row[Sx].first, right = row[Sx].second;
    for (int i = Sy + 1; i <= n; i++) {
        int left = row[i].first, right = row[i].second;
        
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}