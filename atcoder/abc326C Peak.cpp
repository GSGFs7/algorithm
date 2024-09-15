#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int l = 0, r = -1;
    int ans = 0;
    while (r < n - 1)// 这里超出范围！！！
    {
        r ++;
        while (a[r] - a[l] >= m) l ++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}