#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出从1到n的排列 每个位置给出一个数组 如果数组第i个位置上的值为1就表示可以往后走i个位置
  问在不经过某个点的情况下到最后一个点的最小距离
*/

const int N = 3e5 + 10;
string s[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];

    // DP找到每个点的最短距离
    vector<int> dis1(n, 1e9), dis2(n, 1e9);
    // 从前往后
    dis1[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m && j + i + 1 < n; j++) {
            if (s[i][j] == '1') dis1[i + j + 1] = min(dis1[i + j + 1], dis1[i] + 1);
        }
    }
    // 从后往前
    dis2[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m && j + i + 1 < n; j++) {
            if (s[i][j] == '1') dis2[i] = min(dis2[i], dis2[i + j + 1] + 1);
        }
    }

    // 大力枚举不经过某个点的情况，其实就是看前后能不能走得通
    for (int i = 1; i < n - 1; i++) {
        int ans = 1e9;
        for (int j = max(0, i - m + 1); j < i; j++) {
            for (int k = i - j; k < m; k++) {
                if (s[j][k] == '1') ans = min(ans, dis1[j] + dis2[j + k + 1] + 1);
            }
        }
        if (ans == 1e9) ans = -1;
        cout << ans << ' ';
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


// https://atcoder.jp/contests/abc291/tasks/abc291_f
// 2024-10-04