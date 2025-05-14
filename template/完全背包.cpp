// 动态规划
//  1.状态表示
//      集合：只考虑前i个物品，且总体积不大于j的所有选法
//      属性：最大
//  2.状态计算
//      集合的划分
//
// 假设第一个物品取k个
// 去掉k个i物品
// 对剩下的部分求最大值 f[i-1,j-k*v[i]]
// 再加回j个物品i f[i-1,j-k*v[i]]+k*w[i])
// 得出方程f[i,j]=f[i-1,j-v[i]*k]+w[i]*k

/// 朴素做法
/*
#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N], w[N], v[N], l[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);// 为什么第一个不是f[i-1][j]

    cout << f[n][m] << endl;
    return 0;
}
 */

/// 优化版
/*
#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N], w[N], v[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j ++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    // 最后那一部分可化简为01背包
    cout << f[n][m] << endl;
    return 0;
}
 */

/// 再次优化版(一维)
#include <iostream>
using namespace std;

const int N = 1010;
int f[N], v[N], w[N], n, m;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // 解绑反而变慢了1ms?

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    // 完全背包从小到大
    // 01背包从大到小

    cout << f[m] << endl;
    return 0;
}