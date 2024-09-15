#include <bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_cxx;

/*
 * 给出两个数，这两个数是一个数的最大因子，求这个数
 * 最先想到的应该就是最小公倍数了，但是会出现一个问题，
 * 如果a是b的一个因子，得到的最小公倍数就是b，不符合题目要求
 * 但是，因为a是b的一个因子，b/a就是也是一个因子，b*(b/a) 即为这种情况下的解（Why？）
 * */

void solve()
{
    int a, b;
    cin >> a >> b;
    int c = lcm(a, b);
    if (b == c) cout << b * b / a << '\n';
    else cout << c << '\n';
}

signed main(){
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1916/problem/B