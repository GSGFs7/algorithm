// 区间DP
/*
 * 状态表示：所有的将第i堆石子到第j堆石子合并到一起的合并方式
 * 属性：Min
 * 状态计算：最后一条分界线来划分
 *
 * DP套DP
 * */

#include <iostream>
using namespace std;

const int N = 310, INF = 0x3f3f3f3f;
int s[N], f[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = 1; i <= n; i++) s[i] += s[i - 1];// 前缀和，快速统计区间内的值

    for (int len = 2; len <= n; len ++)// 枚举长度
    {
        for (int i = 1; i + len - 1 <= n; i++)// 枚举起点
        {
            int const l = i, r = i + len - 1;
            f[l][r] = INF;// 初始化
            for (int k = l; k < r; k++)// 计算终点的结果
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);// 状态转移方程
        }
    }

    cout << f[1][n] << endl;// 输出全部合并的最小值
    return 0;
}