#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 单调队列模板题
 * */

const int N = 1e6 + 10;
int a[N];
int maxQ[N], minQ[N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans1, ans2;
    int head1 = 0, head2 = 0, tail1 = -1, tail2 = -1;
    for (int i = 1; i < m; i++)
    {
        while (head1 <= tail1 && a[maxQ[tail1]] <= a[i]) tail1 --;
        maxQ[++ tail1] = i;
        while (head2 <= tail2 && a[minQ[tail2]] >= a[i]) tail2 --;
        minQ[++ tail2] = i;
    }
    for (int i = m; i <= n; i++)
    {
        while (head1 <= tail1 && a[maxQ[tail1]] <= a[i]) tail1 --;
        maxQ[++ tail1] = i;
        while (i - maxQ[head1] >= m) head1 ++;
        ans1.push_back(a[maxQ[head1]]);

        while (head2 <= tail2 && a[minQ[tail2]] >= a[i]) tail2 --;
        minQ[++ tail2] = i;
        while (i - minQ[head2] >= m) head2 ++;
        ans2.push_back(a[minQ[head2]]);
    }

    for (auto i : ans2) cout << i << ' ';
    cout << '\n';
    for (auto i : ans1) cout << i << ' ';
    return 0;
}


// https://www.luogu.com.cn/problem/P1886