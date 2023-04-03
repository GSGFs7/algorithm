#include <iostream>
using namespace std;

// 快速幂
// a^8 为 a -> a^2 -> a^4 -> a^8
// 将a的b次转换为a^1+a^2...
// 如：
// a的9次幂为a^1+a^8      只需4次运算
// 9的二进制为1001
// 对应二进制各位上的1都要相乘（寻找最大偶数，简化运算）

int quickPower(int a, int b)// 快速处理a的b次方，时间复杂度为O(log2 n)
{
    int ans = 1, base = a;// ans为输出的结果，base为a的2^n次幂
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