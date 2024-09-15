#include <iostream>
#include <vector>

using namespace std;

/*
  给出n个矩形，边长为a[i]和b[i]，规定一行或是一列填满后就可以获得一点价值
  求获得m点价值的最小填充的格子数

  首先在纸上手画一下，发现...好像没什么规律
  贪心的话可能行不通，因为一个矩形中剩下的格子是动态变化的，没有什么固定的贪心规律
  束手无策，直接看题解
  好家伙，DP，这也能D？
  
  还——真的可以
  首先，第一层，只考虑前i个矩阵的情况，也是DP的标准手段了
  第二层，枚举这个矩阵所贡献的价值
  第三层，计算最小花费，与第二层加起来也算是一个标准的01背包？
  这就……没了？
  简单粗暴，喵啊～
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;
    // 第一层，只考虑前i个
    for (int i = 0; i < n; i++) {
        int x = a[i], y = b[i];
        int mx = x + y;    // 这个矩阵可获得的最大价值
        int cost = 0;
        // 第二层，枚举这个位置的值所能贡献的价值
        for (int j = 0; j <= mx; j++) {    // 枚举价值，并使用枚举的价值进行更新，喵
            // 第三层，使用上一层枚举出的价值来更新当前的所有价值的最小花费
            for (int k = 0; j + k <= m; k++) {    // 总价值不会超过m
                dp[i + 1][k + j] = min(dp[i + 1][k + j], dp[i][k] + cost);
            }
            // 计算花费
            if (j < mx) {    // 贪心，优先填充短边
                if (x >= y) {
                    x--;
                    cost += y;
                } else {
                    y--;
                    cost += x;
                }
            }
        }
    }

    cout << (dp[n][m] == 1e9 ? -1 : dp[n][m]) << '\n';
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


// https://codeforces.com/contest/2000/problem/F
// 2024-08-30
// 62 ms 	100 KB