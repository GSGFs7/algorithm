#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
  给出一个 n*m 的网格和 w 个权重，将所有的权重放入网格中，用一个 k*k 的子矩阵统计区间价值
  求子矩阵的价值之和。

  很明显相对靠近中心的点会得到更多的重复次数，如果知道了每个点的重复次数就可以得到每个位置的最大价值
  也就是最大的价值放在重复次数最多的点（大的乘大的一定比几个小的乘大的要大）
  至于怎么求每个点的重复次数，直接用差分就可以了

  完全就是英语题，看不懂题面
 */

#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    // cout << n << m << k << '\n';
    int w;
    cin >> w;
    vector<int> a(w);
    for (int i = 0; i < w; i++) cin >> a[i];

    // 差分
    vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            diff[i][j] += 1;
            diff[i + k][j] -= 1;
            diff[i][j + k] -= 1;
            diff[i + k][j + k] += 1;
            // cout << i << '\t' << j << '\n';
        }
    }

    // 还原差分
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            pq.push(diff[i][j]);
        }
    }

    sort(a.begin(), a.end(), greater());

    // 最大的放在访问最多次的位置
    int ans = 0;
    int l = 0;
    while (!pq.empty() and l < w) {
        ans += pq.top() * a[l++];
        // cout << pq.top() << ' ' << a[l - 1] << '\n';
        pq.pop();
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


// https://codeforces.com/contest/2000/problem/E
// 2024-08-30