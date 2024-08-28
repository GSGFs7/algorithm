#include <iostream>
using namespace std;

/*
 * DP计算方案数
 * 利用DP的路径表示，进行累加，加到最后一位就是结果
 * */

const int N = 110, mod = 1e6 + 7;
int f[N][N], a[N];

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // f[i][j]表示在计入第i盆花的情况下，容量位j的状态下的最大值
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for (int k = 0; k <= a[i] && k <= j; k++)// 规定范围，能够到这个点的所有路径，不能超过当前状态和最大使用量
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;// 加上从各个位置来的路径

    cout << f[n][m] << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1077