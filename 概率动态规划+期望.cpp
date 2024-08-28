#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/* 概率动态规划加期望 */

const int N = 110, p = 1000000007;
long long f[N][N];

long long rp(long long now, int k)
{
    long long res = 1;
    for (; k; k >>= 1, now *= now, now %= p)
        if (k & 1)
            res *= now, res %= p;
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a[N];
    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
    }

    /* 三重循环的实际复杂度为 O(n*mlogp) 每条边都只会被循环一次 */
    memset(&f, 0, sizeof(f));
    f[1][0] = 1;
    for (int i = 1; i < n; i++)// 枚举起点
    {
        int const l = a[i].size();
        for (int k = 0; k < n; k++)// 枚举走过的路
            if (f[i][k])
                for (int j = 0; j < l; j++)// 枚举终点
                    f[a[i][j]][k + 1] += f[i][k] * rp(l, p - 2), f[a[i][j]][k + 1] %= p;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans += f[n][i] * i, ans %= p;
    printf("%d", ans);
    return 0;
}