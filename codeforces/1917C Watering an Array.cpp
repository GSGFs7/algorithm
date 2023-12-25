#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 暴力+贪心
 * 给出数组a和数组b，可以进行两种操作
 *  1.在第i天给a中前b[i]个数加上1
 *  2.统计a中a[j]==j的数量，得到这个数量的分值
 *
 * 考虑a中全是0的情况，在每天加1的情况下，数组a肯定是递减的，
 * 所以不会出现统计时得到的统计值大于2的情况出现，也就是说每两天固定得到1的分值才是最优解
 * 得到了这个结论，直接暴力处理a，看a[j]==j数量最大的情况就可以了
 * */

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n), b(m);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    int ans = 0;
    for (int i = 0; i < 2 * n && i < d; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)// 统计与自己位置相同的数的个数
            cnt += (j + 1) == a[j];

        // 两次操作才可以增加1的价值
        ans = max(ans, cnt + (d - i - 1) / 2);// 减去在a上消耗的天数

        int t = b[i % m];
        for (int j = 0; j < t; j++)// 加1
            a[j] += 1;
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

    int start = clock();

    int t;
    cin >> t;
    while (t--)
        solve();

//    cout << clock() - start << '\n';
    return 0;
}


// https://codeforces.com/contest/1917/problem/C