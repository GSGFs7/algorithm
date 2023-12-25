#include <bits/stdc++.h>
using namespace std;

/*
 * 有依赖的背包问题
 *
 * */

const int N = 100010;
int f[55][N];

signed main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(&f, 0, sizeof f);
        for (int i = 1; i <= n; i++)
        {
            int b, V;
            scanf("%d %d", &b, &V);
            for (int j = 0; j < b; j++) f[i][j] = -1;// 买不起箱子的情况
            for (int j = b; j <= m; j++) f[i][j] = f[i - 1][j - b];// 如果取这箱子的东西，给个初值

            for (int k = 1; k <= V; k++)// V个箱子
            {
                int v, w;
                scanf("%d %d", &w, &v);
                for (int j = m; j >= w; j--)// 01背包
                    if (f[i][j - w] != -1)// 需要一个前提条件，能够在买这个物品前买下箱子
                        f[i][j] = max(f[i][j], f[i][j - w] + v);
            }

            for (int j = 0; j <= m; j++)// 如果真的要买这个箱子里的东西是否会更便宜
                f[i][j] = max(f[i][j], f[i - 1][j]);
        }
        printf("%d\n",f[n][m]);// 找了好久，原来是这个到循环外面去了
    }
    return 0;
}


// https://acm.hdu.edu.cn/showproblem.php?pid=3449