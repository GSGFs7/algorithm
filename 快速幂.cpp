#include <iostream>
using namespace std;

/// 快速幂
// 反复平方法
// a^k=a^2^i+a^2^j+a^2^k...
// 化简:a^(2^i+2^j+2^k...)
// 上式可理解为k的二级制表示，如果为1加上该位，否则不加
// 妙啊

// 预处理出6^2^0~6^2^k，然后相加
// 如：
// a的9次幂为a^1+a^8      只需4次运算
// 9的二进制为1001
// 对应二进制各位上的1都要相乘（寻找最大偶数，简化运算）

long long quickPower(int a, int b)// 快速处理a的b次方，时间复杂度为O(log2 n)
{
    long long  ans = 1, base = a;// ans为输出的结果，base为a的2^n次幂
    while (b)// 当b未耗尽时
    {
        // &位与 都为true(1)时返回true
        if (b & 1) ans *= base;// 对应二进制的每位相乘

        base *= base;// 自增
        b >>= 1;// 移向下一位
    }
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << quickPower(a, b);
    return 0;
}