#include <iostream>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;

/// 二分 && 贪心

const int N = 2e5 + 10;
int a[N];
int n, c, d;

bool check(int mid)
{
    int res = 0;// 一个周期的值
    for (int i = n; i >= max(n - mid, 1LL); i --) res += a[i];
    int sum = 0;// 剩下的值
    for (int i = n, j = d % (mid + 1); j >= 1 && i >= max(n - mid, 1LL); i--, j--) sum += a[i];
    return d / (mid + 1) * res + sum >= c;
}

void solve()
{
    cin >> n >> c >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    if (a[n] * d < c) return puts("Impossible"), void();

    /// 二分查找答案
    int l = 0, r = INF;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (r < INF) cout << r << endl;
    else puts("Infinity");// 如果都可
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://mirror.codeforces.com/contest/1760/problem/F