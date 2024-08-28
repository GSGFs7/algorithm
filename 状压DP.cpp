#include <iostream>
#include <limits>
#include <vector>

using namespace std;

/*
  状态压缩的DP

  可以直接用二进制表示每位对应的状态, 0表示不取, 1表示取
  直接用(n<<1)个数就能表示出所有的状态, 根据初始状态赋值
  再跑一遍类似01背包的东西, 根据子集的状态更新当前值
*/

void solve() {
    int W, n;
    cin >> W >> n;
    int S = 1 << n;    // 一共n位，每位都表示这个位置上的状态（1和0，取与不取）
    vector<int> ts(S, 0), ws(S, 0);
    for (int i = 0; i < n; i++) {
        int t, w;
        cin >> t >> w;
        for (int j = 1; j < S; j++) {     // 枚举所有的情况，看取不取
            if (j & (1 << i)) {           // 如果这个状态要取这个值
                ts[j] = max(ts[j], t);    // 时间取最大
                ws[j] += w;               // 重量相加
            }
        }
    }

    vector<int> dp(S, numeric_limits<int>::max() / 2);
    for (int i = 0; i < S; i++) {                // 枚举每种状态
        if (ws[i] <= W) dp[i] = ts[i];           // 如果直接满足条件
        for (int j = i; j; j = i & (j - 1)) {    // 降序遍历掩码对应的全部子集
            if (ws[j ^ i] <= W) {                // 如果删去一些后的子状态满足要求
                // 子状态加上从子状态到原本状态的补集（异或求对称差）
                dp[i] = min(dp[i], dp[j] + ts[i ^ j]);
            }
        }
    }

    cout << dp[S - 1] << '\n';

    // for (int i = 1; i < S; i++) cout << i << ' ' << dp[i] << '\n';
    // for (int i = 1; i < S; i++) cout << i << ' ' << ts[i] << ' ' << ws[i] << '\n';
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


// https://www.luogu.com.cn/problem/P5911
// 2024年4月2日
// 179ms  1.23MB