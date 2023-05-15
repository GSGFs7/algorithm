#include <iostream>
using namespace std;

/// 最大公约数 欧几里得算法
/*
 * 辗转相除法
 *
 * 前置知识:
 * 如果：
 *  a % d == 0
 *  b % a == 0
 * 那么：
 *  (a + b) % d == 0
 *  并且 (a*x + b*y) %d == 0
 *
 *  可推导出：
 *  gcd(a, b) = gcd(b, a mod b)
 * */

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b);
    }
    return 0;
}