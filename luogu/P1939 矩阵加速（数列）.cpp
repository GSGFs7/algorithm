#include <iostream>
#include <cstring>
#define int long long
using namespace std;

/*
 * 矩阵加速
 * 代码部分基本与斐波那契的矩阵加速一致
 * 重要的是初始矩阵的确定
 *
 * 假设我们需要的矩阵是
 * f[i+1]=
 * {
 *  f[i]
 *  f[i-1]
 *  f[i-2]
 * }
 * 由题目给出的公式
 * f[i]=f[i]*1+f[i-1]*0+f[i-2]*1 (题目要求f[x]=f[x-1]+f[x-3]，f[i]对应矩阵中的f[i]，不是第i个数)
 * f[i-1]=f[i]*0+f[i-1]*1+f[i-2]*0
 * f[i-2]=f[i]*0+f[i-1]*0+f[i-2]*1
 * 对应得到的初始值为
 * {
 *  1 0 1
 *  0 1 0
 *  0 0 1
 * }
 * */

const int mod = 1e9 + 7;

/// 矩阵的结构体
struct Matrix{
    int m[3][3];
    Matrix()
    {
        memset(&m, 0, sizeof m);// 初始化
    }
};

/// 重载*操作
Matrix operator * (Matrix const &A, Matrix const & B)
{
    Matrix res;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                res.m[i][j] = (res.m[i][j] + A.m[i][k] * B.m[k][j]) % mod;
    return res;
}

/// 矩阵快速幂
Matrix quick_power(int n)
{
    Matrix res;// 得到的结果
    for (int i = 0; i < 3; i++) res.m[i][i] = 1;
    Matrix base;// 对应的每一个位置的值
    base.m[0][0] = base.m[0][2] = base.m[1][0] = base.m[2][1] = 1;// 初始值

    // 快速幂
    while (n)
    {
        if (n & 1) res = res * base;

        base = base * base;
        n >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    if (n < 4) return cout << 1 << '\n', void();// 别忘了换行，WA了一发
    cout << quick_power(n).m[1][0] << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.luogu.com.cn/problem/P1939