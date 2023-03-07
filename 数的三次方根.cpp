#include <iostream>
using namespace std;

int main()
{
    double x;
    cin >> x;

    double l = -10000, r = 10000;
    while (r-l > 1e-8)// 设置计算精度，无法精确计算
    {
        double mid = (l+r) / 2;
        if (mid*mid*mid >= x) r = mid;
        else l = mid;
    }
    printf("%lf", l);
    return 0;
}

// 二分
// https://www.acwing.com/problem/content/792/