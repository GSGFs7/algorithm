#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

bool check(int mid)
{
    int const res = (mid + 1) * mid / 2;

    if (res - (n - mid) < m) return true;
    else return false;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;

    int l = 0, r = n;
    while (l < r)
    {
        int const mid = (l + r) >> 1;// mid表示相加了多少次
        if (check(mid)) l = mid + 1;
        else r = mid;
    }

    int const res = (r + 1) * r / 2;
    cout << res - m << '\n';
    return 0;
}
/**********************************************************************
	Problem: 1213
	User: chenjiahui
	Language: C++
	Result: TLE
**********************************************************************/
