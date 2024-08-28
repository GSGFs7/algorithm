#include <iostream>
#define ll long long
using namespace std;

// 每四次跳跃都会回到0，所以只需要计算最后四次即可

void solve()
{
    ll x, n;
    cin >> x >> n;
    ll k = n / 4 * 4;// 向下取整，找到小于n的最大4的倍数
    for (ll i = k + 1; i <= n; i++)// 从k+1开始，k为4的倍数所以为回到0的那个点
    {
        // 题目要求
        if (x % 2) x += i;
        else x -= i;
    }
    cout << x << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://codeforces.com/problemset/problem/1607/B