#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出a,b,c这3组值，其中各取一个，要求下标不能重复，求最大和
 * 直接暴力排序，将得到的序列按要求前三个排列组合（三个for循环），暴力得出最大值
 * */

typedef pair<int, int> PII;

bool cmp(PII a, PII b)
{
    return a.first > b.first;
}

void solve()
{
    int n;
    cin >> n;
    vector<PII> a[3];// first是权重，second是下标
    for (auto & i : a)
    {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            i.emplace_back(x, j);
        }
    }

    sort(a[0].begin(), a[0].end(), cmp);
    sort(a[1].begin(), a[1].end(), cmp);
    sort(a[2].begin(), a[2].end(), cmp);

    // 排列组合，当时怎么没想到，写了几十行的if
    int ans = 0;
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (a[0][i].second != a[1][j].second && a[0][i].second != a[2][k].second && \
                a[1][j].second != a[2][k].second)// 下标不能重复
                    ans = max(ans, a[0][i].first + a[1][j].first + a[2][k].first);

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


// https://codeforces.com/contest/1914/problem/D