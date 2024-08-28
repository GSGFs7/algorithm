// 01背包
// 枚举，用01串来表示是否取这个物品
// 当考虑了前i个物品取或不取时，有两组方案的总体积是一样的，那么只需要保留那个最大的
// 考虑前i个物品，总体积为j时的两种情况
//      1.第i个物品没取，问题变成考虑前i-1个物品，总体积为j时的情况
//      2.第i个物品取了，问题变成考虑前i-1个物品，总体积为j-v[i]时的情况
//
// 最优子结构
// 无后效性
// 状态

// 二维
#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N], v[N], w[N];// v价值,w重量,f最大价值

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    // 先循环个数
    // 再循环代价
    for (int i = 1; i <= n; i++)// 枚举前i的情况的最大值
        for (int j = 0; j <= m; j++)// j是容量大小,f[i][j]表示在前i个数中取不大于j重量的最大价值
            if (j < w[i])// 放不下的情况
                f[i][j] = f[i - 1][j];
            else// 取i和不取i的最大值
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);// 剩下那部分就是减i的重量，再对这部分求最大值

    // debug
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
     */

    cout << f[n][m] << endl;
    return 0;
}