#include <iostream>
#include <cstring>
#define int long long
using namespace std;

/*
 * 斐波那契数列加速
 * 原时间复杂度O(n)，矩阵加速后为O(logn)     <-以2为底n的对数的缩写表示
 * 闲荡于转化为了快速幂
 *
 * 矩阵的乘法相当于在对应的每个位置用A的竖排乘以B的横排
 * {        {
 *  1 1      1 1
 *  1 0      1 0
 * }        }
 * 上面两个矩阵相乘得到的矩阵为
 * {
 *  2 1
 *  1 0
 * }
 * 多次递推（都与原来的值相乘，也就是B）
 * {        {       {
 *   3 2     5 3     8 5
 *   2 1     3 2     5 3
 * }        }       }
 *
 * 左上角的数因为每次都是由a11与a12相加得到，因为都是乘以1
 * 而左下角和右上角的数都是a11+0，所以都是上次递推的左上角
 * 符合斐波那契的规律
 * 得出公式 f(n)=
 * {
 *  a[n+1] a[n]
 *  a[n]   a[n-1]
 * }
 * a[n]就表示斐波那契递推中的第n个数
 * 这样就由O(n)的递推关系转化为B的幂次的关系，用快速幂可O(logn)实现
 * */

struct Matrix{
    int m[2][2];
    Matrix()
    {
        memset(&m, 0, sizeof m);
    }
};

const int mod = 1e4;

// 调了好久，原来是全局变量的锅，以后还是尽量少用全局变量吧
void debug(Matrix k)
{
    cout << k.m[0][0] << ' ' << k.m[0][1] << '\n';
    cout << k.m[1][0] << ' ' << k.m[1][1] << '\n';
}

Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
    return c;
}

Matrix quick_power(int n)
{
    Matrix res;
    for (int i = 0; i < 2; i++) res.m[i][i] = 1;
    Matrix A;
    A.m[0][0] = A.m[0][1] = A.m[1][0] = 1;

    while (n)
    {
        if (n & 1) res = res * A;

        A = A * A;
        n >>= 1;
    }
    return res;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    while (true)
    {
        cin >> n;
        if (n == -1) break;
        if (n == 0) { cout << 0 << '\n'; continue; }

        Matrix const ans = quick_power(n);

        //debug(ans);
        cout << ans.m[0][1] << '\n';
    }
    return 0;
}


// http://poj.org/problem?id=3070
// 跑poj的数据0ms？