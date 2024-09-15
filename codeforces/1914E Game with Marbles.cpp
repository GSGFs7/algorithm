#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * a[i]花费1的消耗可以可以使b[i]变成0，反之亦然，a要使结果最大，吧要使结果最小
 * 求两个人在最优操作中，最后的结果的a[i]-b[i]的和
 *
 * 对于a的一次操作 a获得了a[i]-1的得分，让b的得分减少了b[i]，得到的总权重为a[i]+b[i]-1
 * 对于b来说也是如此
 * 这样可以得到操作优先级是取 a[i]+b[i] 结果大的
 *
 * 那么直接对 a[i]+b[i] 的结果排序，用排序后的顺序来计算就是他们的最优解
 * */

typedef pair<int, int> PII;

bool cmp(PII a, PII b)
{
    return a.first > b.first;// 从大到小
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<PII> c(n);
    for (int i = 0; i < n; i++)
        c[i] = {a[i] + b[i], i};// 带上序号

    sort(c.begin(), c.end(), cmp);

    int ans = 0;
    bool rt = true;
    for (int i = 0; i < n; i++)
    {
        if (rt)
        {
            ans += a[c[i].second] - 1;// c[i].second 就是高权重的下标了
            rt = false;
        }
        else
        {
            ans -= b[c[i].second] - 1;// b要使结果最小，直接减去
            rt = true;
        }
    }

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

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1914/problem/E1
// https://codeforces.com/contest/1914/problem/E2