#include <iostream>
using namespace std;

// 费马小定理求逆元
/*
 * 当a与p互质时
 * a^(p-1)≡1(mod p)
 * a*a^(p-2)≡1(mod p)
 * 此处的a^(p-2)就是a的逆元了，直接快速幂暴力求解
 * */

long long quick_power(int a, int b, int p)
{
    long long res = 1, base = a;
    while (b)
    {
        if (b & 1) res = (res * base) % (p);

        base = (base * base) % (p);
        b >>= 1;
    }
    return res;
}

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    // 输出从1到n的模p下的乘法逆元
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cout << quick_power(i, p - 2, p) << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P3811
// 5个点后面两个TLE
