#include <iostream>
#include <cstring>
#define int long long
using namespace std;

/*
 * 矩阵快速幂模板
 *
 * 假设A尺寸为m*n，的尺寸为n*u
 * 矩阵乘法的公式为
 * C[i,j]=∑A[i][k]*B[k][j]
 * 用代码表示就直接为i,j,k三重循环
 * */

const int N = 110;
const int mod = 1e9 + 7;

struct matrix {
    int m[N][N];
};

matrix operator * (const matrix &a, const matrix &b) { // 重载*操作符为矩阵乘法，注意const
    matrix c{};
    memset(&c.m, 0, sizeof c.m);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
    return c;
};

matrix pow_matrix(matrix a, int n) // 矩阵快速幂，代码几乎和普通的快速幂一模一样
{
    matrix res{};
    memset(&res.m, 0, sizeof res.m); // 初始化单位矩阵，类似普通快速幂的ans=1
    for (int i = 0; i < N; i++) res.m[i][i] = 1;
    while (n)
    {
        if (n & 1) res = res * a;// 因为重载的原因不能使用res *= a;
        a = a * a;
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

    int n, m;
    cin >> n >> m;
    matrix a{};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a.m[i][j];

    matrix const ans = pow_matrix(a, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans.m[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P3390