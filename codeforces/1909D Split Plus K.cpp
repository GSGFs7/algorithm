#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出n个正整数和一个k，你可以把其中一个正整数加上k，然后拆成两个数，求所有值相等的最小操作次数
 *
 * 最后变成的数=(a[i]+m*k)/(m+1)
 * 化简=k+(a[i]-k)/(m+1)
 * 最后的数都满足这个条件，要求最小操作次数，也就是求最小公约数的
 * */

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int g = 0;
    int maxn = -1e9, minn = 1e9;
    int cnt = 0;
    for (auto& i : a)
    {
        cin >> i;
        g = gcd(g, i - k);
        maxn = max(maxn, i);// 最值
        minn = min(minn, i);
        cnt += i == k;// 0的最大公约数，直接输出-1
    }

    if (a == vector<int> (n, a[0])) return cout << 0 << '\n', void();// 如果不用拆分
    if (cnt) return cout << -1 << '\n', void();
    if (maxn > k && minn < k) return cout << -1 << '\n', void();// 如果k被包围在数据中，那么就是无法完成的

    int ans = 0;
    for (auto i : a)
        ans += abs(i - k) / g - 1;// 每次的花费
    cout << ans << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int start = clock();

    int t;
    cin >> t;
    while (t--)
        solve();

//    cout << clock() - start << '\n';
    return 0;
}


// https://codeforces.com/contest/1909/problem/D