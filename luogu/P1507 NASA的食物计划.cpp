#include <iostream>
using namespace std;

/*
 * 题目有两个限制条件，那就创建两个记录点（二维数组）
 * 从这两个记录点开始进行优化版的01背包
 * */

const int N = 60, M = 510;
int a[N], b[N], c[N], f[M][M];

int main()
{
    int h, t, n;
    cin >> h >> t >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];

    for (int i = 1; i <= n; i++)
        for (int j = h; j >= a[i]; j--)
            for (int k = t; k >= b[i]; k--)
                f[j][k] = max(f[j][k], f[j - a[i]][k - b[i]] + c[i]);

    cout << f[h][t] << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1507