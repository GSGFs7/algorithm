#include <iostream>
using namespace std;

/// 线性DP
/*
 * 递推有一定线性关系
 * 动态规划：
 *  1.状态表示
 *      集合：所有从起点走到(i,j)的路径
 *      属性：路径上数字之和的最大值
 *  2.状态计算
 *      从左上方和右上方来的路径加上当前值的最大值
 *      左上方：f[i-1,j-1]+a[i,j]
 *      右上方：f[i-1,j]+a[i,j]
 *      状态转移方程：f[i][j]=max(f[i-1][j-1]+a[i][j],a[i-1][j]+a[i][j]);
 * 时间复杂度一般为：状态数量*转移计算量 (1*n^2)
 * */
// 例题：数字三角形  https://www.acwing.com/problem/content/900/
// 给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，
// 一直走到底层，要求找出一条路径，使路径上的数字的和最大。

const int N = 510, INF = 1e9;
int a[N][N], f[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)// 边界需要多初始化一列，因为取最大值的时候可能会被这不存在的一列干扰
            f[i][j] = -INF;

    f[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)// i不能取1，取1的话会覆盖掉f[i][j]=a[i][j]
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);

    int ans = -INF;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[n][i]);
    cout << ans << endl;

    // debug
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }*/
    return 0;
}