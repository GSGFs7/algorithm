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
 * 可推导出：
 * gcd(a, b) = gcd(b, a mod b)
 *
 * 稍微推导一下
 * a = 6, b = 24;
 * 第一轮：24，6
 * 第二轮：6，0
 * 第三轮：返回a (6)
 * 辗转相除
 * */

// b为0时直接返回，不会因为对0取模导致程序异常
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
        cout << a % b;
    }
    return 0;
}