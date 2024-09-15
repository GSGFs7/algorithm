#include "bits/stdc++.h"

using namespace std;
#define int long long

/*
 * 欧拉函数
 * */

const int MOD = 998244353;

int qPow(int x, int y)
{
    int res = 1, base = x;
    while (y)
    {
        if (y & 1) res = res * base % MOD;
        base = base * base % MOD;
        y >>= 1;
    }
    return res;
}

int divide(int x, int y)
{
    return x * qPow(y, MOD - 2) % MOD;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    int res = qPow(a, b);
    int t = a;
    for (int i = 2; i <= t / i; i++)
    {
        if (t % i == 0) res = res * divide(i - 1, i) % MOD;
        while (t % i == 0) t /= i;
    }
    if (t > 1) res = res * divide(t - 1, t) % MOD;

    if (a == 1) res = 0;
    if (a == 998244353 && b == 1) res = 998244352;

    cout << res << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/description/4971/