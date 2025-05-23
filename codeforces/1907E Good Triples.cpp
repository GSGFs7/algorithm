#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出n，求a+b+c==n并且a，b，c的每一位相加等于n的每一位相加
 * 找规律题
 *
 * 暴力跑前面一些数据找规律
 *  1:3     2:6     3:10    4:15    5:21    6:28    7:36    8:45    9:55    10:3
 *  11:9    12:18   13:30   14:45   15:63   16:84   17:108  18:135  19:165  20:6
 *  21:18   22:36   23:60   24:90   25:126  26:168  27:216  28:270  29:330  30:10
 *  31:30   32:60   33:100  34:150  35:210  36:280  37:360  38:450  39:550  40:15
 *  41:45   42:90   43:150  44:225  45:315  46:420  47:540  48:675  49:825  50:21
 *  1:3=1*3
 *  2:6=2*3
 *  3:10=2*5
 *  当只有一位时 (n+1)*(n+2)/2
 *  10:3=1*3
 *  11=1*1:3*3
 *  12=1*2:3*6
 *  当有多位时，就是多个一位相乘
 */

void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    while (n)
    {
        ans *= (n % 10 + 1) * (n % 10 + 2) / 2;
        n /= 10;
    }
    cout << ans << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1907/problem/E