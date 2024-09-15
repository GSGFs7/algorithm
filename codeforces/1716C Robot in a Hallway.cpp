#include <cstring>
#include <iostream>

using namespace std;

/*
  给出2行n列的网格, 第(i,j)位置的网格在a[i][j]时刻解锁, 问走完全部格子最短的时间
  
  思路:
    首先, 在这个网格中只有两种走法
        1. 先左右的U形走法
        2. 先上下的蛇形走法
    但是前面的路可能走蛇形, 然后变成U形
*/

#define int long long
const int N = 2e5 + 10;
const int INF = 1e18;
int a[2][N];
int max1[2][N];
int max2[2][N];
bool vis[2][N];

void solve() {
    int n;
    cin >> n;
    memset(&vis, 0, sizeof vis);
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // 初始化
    for (int i = 0; i < 2; i++) {
        max1[i][n + 1] = max2[i][n + 1] = -INF;
        for (int j = n; j; j--) {
            max1[i][j] = max(max1[i][j + 1], a[i][j] - j);
            max2[i][j] = max(max2[i][j + 1], a[i][j] + j);
        }
    }

    int x = 0, y = 1;
    int ans1 = INF;
    int ans2 = 0;
    vis[0][1] = true;
    while (true) {
        if (!vis[x ^ 1][y]) {
            int tmp = max(ans2 + n - y, max1[x][y + 1] + n + 1);
            ans1 = min(ans1, max(tmp + n - y + 1, max2[x ^ 1][y] - y + 1));
            x ^= 1;
        } else {
            y++;
        }

        if (y > n) break;
        vis[x][y] = true;
        ans2 = max(ans2 + 1, a[x][y] + 1);
    }

    cout << min(ans1, ans2) << '\n';
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


// https://codeforces.com/contest/1716/problem/C
// 2024年6月22日