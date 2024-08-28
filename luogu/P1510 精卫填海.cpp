#include <iostream>
#define endl '\n'
using namespace std;

const int N = 10010;
int v[N], w[N], f[N];

inline long long read()
{
    long long n = 0, F = 1, ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();// 搞半天原来快读写错了，要吃掉所有非数字的字符（题目中也没有负数）
    while (ch >= '0' && ch <= '9')
    {
        n = (n << 3) + (n << 1) + ch - '0';// 位运算版乘十
        ch = getchar();
    }
    return F * n;
}

signed main()
{
    long long V, n, c;// V最大价值，看能否超过 c背包总体积
    V = read(), n = read(), c = read();

    for (int i = 1; i <= n; i++)
    {
        w[i] = read();
        v[i] = read();
    }

    /// 状态转移方程
    for (int i = 1; i <= n; i++)
        for (long long j = c; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    /// 要求最大体力剩余！！！
    for (int i = 1; i <= c; i++)
        if (f[i] >= V) { cout << c - i << endl; exit(0); }
    puts("Impossible");

    // debug
    // cout << endl;
    // for (int i = 1; i <= c; i++)
    //     cout << f[i] << ' ';
    return 0;
}


// https://www.luogu.com.cn/problem/P1510