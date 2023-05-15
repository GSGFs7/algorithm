#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

/// 最大公约数
/*
 * 思路：
 * 想要求得 i-j=k && 只能swap(i,j)的排序
 * 就要求出原位置与目标位置的最大公约数
 * 这个公约数就表示位置互换的最大步长
 * */

// 比STL慢？  46ms
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;// 0与其他数的最大公约数是那个数本身
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        ans = gcd(abs(x - i), ans);// 找到与目标位置的差值 __gcd求最大公约数
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
// 时间：31ms


// https://codeforces.com/contest/1828/problem/B