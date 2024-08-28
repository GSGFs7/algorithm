#include <iostream>
#define int long long
using namespace std;

int quick_power(int a, int b)
{
    int res = 1, base = a;
    while (b)
    {
        if (b & 1) res *= base;
        base *= base;
        b >>= 1;
    }
    return res;
}

/*
 * 快速乘的思路与上方的快速幂基本上是一致的
 * 都是将乘数（对于快速幂而言是指数）拆分成二进制
 *  原理是乘法分配律    20*15 = 20*(1111) = 20*2^0 + 20*2^1 + 20*2^2 + 20*2^3
 * 再根据二进制的关系计算分配律中的每一位
 * */

int quick_multiplication(int a, int b)
{
    int res = 0;
    while (b)
    {
        if (b & 1) res += a;
        b >>= 1;
        a <<= 1;// 右移几次就代表了是2的几次幂，从低位向高位递增
    }
    return res;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << quick_multiplication(a, b) << '\n';
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