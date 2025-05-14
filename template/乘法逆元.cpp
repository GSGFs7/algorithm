/*
 * 同余
 * a≡b(mod p)表示a和b模p的值相等 （除以p后余数相等）
 *
 * 裴蜀定理
 * 若a,b都是整数，且gcd(a,b)=d，对于任意的整数x,y，ax+by一定是d的倍数（x，y一定存在）
 * a,b互质的充要条件ax+by=1
 *
 * 乘法逆元
 * ax=1，x就是a的乘法逆元   （可理解为倒数，或者-1次幂）
 * 一般用于求a/b mod p
 * ax mod p≡1，称x为a关于模b的逆元  （代码表示a*x%p==1）
 * 2^{-1} mod 7 = 4     （-1次也可以表示为乘法逆元的意思）
 * 2^{-1} mod 5 = 3
 * 上述的式子可写为 2x mod 7=1 mod 7 求x，可得到x=4，故最后的结果也就是4
 *
 * 乘法逆元是相互的
 * a的乘法逆元是z=a^{-1}
 * z的乘法逆元是a
 * 因为z^{-1}=(a^{-1})^-1=a
 *
 * 互质时才有乘法逆元
 *
 * 逆元有很多种求法
 *  费马小定理
 *  欧拉定理
 *  扩展欧几里得 （解方程）
 *  线性递推
 * */

#include <bits/stdc++.h>
using namespace std;

// 辗转相除法求最大公约数
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int exgcd(int a, int b, int& x, int& y) {
    if(a < b) return exgcd(b, a, y, x);
    int m = 0, n = 1;
    x = 1; y = 0;
    while(b != 0) {
        int d = a / b, t;
        t = m; m = x - d * t; x = t;
        t = n; n = y - d * t; y = t;
        t = a % b; a = b; b = t;
    }
    return a;
}

int inv(int n, int p) {
    int x, y;
    if(exgcd(n, p, x, y) == 1) {
        x = x % p;
        return x >= 0 ? x : p + x;
    } else {
        return -1;
    }
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif


}