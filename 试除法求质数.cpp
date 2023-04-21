#include <iostream>
using namespace std;

// 时间复杂度一定为O(sqrt(n))
inline bool is_prime(int a)
{
    // a如果是合数的话必定有两个成对出现的数 相乘等于这个数
    // 可以直接优化到 根号n
    // i * i可能会爆，最好用a / i
    for (int i = 3; i <= a / i; i += 2)
        if (!(a % i)) return false;
    return true;
}

void solve()
{
    int a;
    cin >> a;
    if (a == 1) { puts("No"); return ; }
    if (a == 2) puts("Yes");
    else if (!(a % 2)) puts("No");
    else if (is_prime(a)) puts("Yes");
    else puts("No");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/868/