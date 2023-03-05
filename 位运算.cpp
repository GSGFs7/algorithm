#include <iostream>
using namespace std;

int lowBit(int x)
{
    return x & -x;
    // & 位与运算 当两个值都为1时结果为1 0&0为0
    // 可获得x二进制的最后一位
    // -x 等于 ~x+1 取反加1
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        int res = 0;
        while (x) x -= lowBit(x), res++;
        // 每次都减去最后一位

        cout << res << ' ';
    }
    return 0;
}

// AcWing 801. 二进制中1的个数
// https://www.acwing.com/problem/content/803/