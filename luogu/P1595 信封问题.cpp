#include <iostream>
using namespace std;

// 错排问题模板题
// 递推求解
// 第一步：考虑第n个元素，放在k位置
// 第二步：考虑k的位置
//      1.放到位置n，那么除了n以外的n-2个元素，全部错排即可
//      2.不放到位置n，那么对于n-1个元素错排
// 结果为相乘关系，递推式为：D[n] = (n-1)(D[n-1] + D[n-2])/

unsigned long long d[25];

int main()
{
    int n;
    cin >> n;
    d[1] = 0, d[2] = 1;
    for (int i = 3; i <= n; i++) d[i] = (i - 1) * (d[i - 1] + d[i - 2]);// 错排公式
    cout << d[n];
    return 0;
}

// https://www.luogu.com.cn/problem/P1595