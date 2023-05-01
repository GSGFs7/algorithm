/*
 * 01背包问题
 * 给出n个物体和容量为v的背包，存在两个权重v,w，每个物体最多只能使用一次，挑出一些物品，使价值和最大
 *
 * 完全背包问题
 * 每件物品可以用无限次
 *
 * 多重背包问题
 * 每个物品个数不一样
 *
 * 分组背包问题
 * 有n组物品，每组只能选一个
 * */

/*
 * DP
 *  状态表示 f(i,j)
 *      集合
 *          所有选法
 *          条件：1.从前i个物品中选 2.总体积不超过j
 *      属性 (max,min,数量)
 *  状态计算
 *      集合划分（含i，不含i）
 *      1.不重 2.不漏
 * */

// 二维
#include <iostream>
using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    f[0][0-m] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);// 右边不一定存在
        }

    cout << f[n][m] << endl;
    return 0;
}