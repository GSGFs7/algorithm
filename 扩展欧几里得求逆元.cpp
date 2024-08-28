#include <iostream>
using namespace std;

/// 扩展欧几里得
/*
 * 对于三个自然数a,b,c，求ax+by=c的整数解
 *
 * 朴素欧几里得
 *  gcd(a,b)=gcd(b,a mod b)
 *  辗转相除法的原理
 *  证明：
 *      假设a=k*b+r，有r=a mod b，设a,b的一个公约数为d，有a≡b≡0(mod d)
 *      由于同余的性质a-kb≡r≡0(mod d)，因此d是b和a mod b的公约数
 *  时间复杂度O(logn)
 *
 * 扩展欧几里得
 *  ax+by=gcd(a,b)
 *  当b=0时，gcd(a,b)=a，此时x=1,b=0为一组解
 *  当b不等于0时，设
 *      ax1+by1=gcd(a,b)
 *  由朴素欧几里得的辗转相除法可知
 *      gcd(a,b)=gcd(b,a%b)
 *  设bx2+ay2=gcd(b,a%b)=gcd(a,b)
 *  则bx2+ay2=ax1+by1
 *
 *  ax+by=gcd(a,b)
 *       =gcd(b,a mod b)
 *       ⇒bx+(a mod b)y
 *       =bx+(a−⌊a/b⌋b)y
 *       =ay+b (x−⌊a/b⌋y)
 *  得出公式
 *  x=y
 *  y=x-⌊a/b⌋y
 * */

/// 朴素欧几里得
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

/// 扩展欧几里得
int ex_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)// 如果辗转相除法得到了最后的答案
    {
        x = 1;
        y = 0;
        return a;
    }

    int const r = ex_gcd(b, a % b, x, y);// 一直递归下去，直到找到最终的答案
    int const t = x;
    x = y;
    y = t - (a / b) * y;
    return r;
}

/// 简化版
typedef long long ll;
void ExGcd(ll a, ll b, ll &x, ll &y) {
    if (!b) x = 1, y = 0;
    else ExGcd(b, a % b, y, x), y -= a / b * x;
}

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif


    int a, b, x, y;
    cin >> a >> b;  // 求a关于模b的逆元
    cout << (ex_gcd(a, b, x, y) == 1 ? (x % b + b) % b : -1) << '\n';  // -1表示逆元不存在
    return 0;
}
