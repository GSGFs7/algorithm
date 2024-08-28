#include <iostream>
using namespace std;

/* 模拟 */

typedef long long LL;

// 以二为底的快速幂
LL quick_Power(int x)
{
    LL res = 1, base = 2;
    while (x)
    {
        if (x & 1) res *= base;
        base *= base;
        x >>= 1;
    }
    return res;
}

int main()
{
    string s;
    while (cin >> s)
    {
        int k = 1, ans = 0;
        while (!s.empty())
        {
            ans += (s.back() - '0') * (quick_Power(k ++) - 1);// string是可以用STL的pop和push的
            s.pop_back();
        }
        cout << ans << endl;
    }
    return 0;
}