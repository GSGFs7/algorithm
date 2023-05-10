#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int l = 1, r = 1; r < n; r++)
    {
        ans += r;// 利用ans统计中间和
        while (ans > n) ans -= l++;// 超过时减去l端，匹配下一个值
        if (ans == n) cout << l << ' ' << r << endl;
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P1147