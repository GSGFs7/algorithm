#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出n个范围，求一个最小的k满足从0开始可以走完n个范围
 * 二分枚举答案
 * */

const int N = 2e5 + 10;
int l[N], r[N];

// 每次找到最大范围，只要范围存在就表示其中有答案可以取到
bool check(int x, int n)
{
    int left = 0, right = 0;// 最开始在0的位置

    for (int i = 0; i < n; i++)
    {
        left -= x, right += x;// 能到达的最大长度

        if (left > r[i] || right < l[i])// 如果够不着这个点的范围
            return false;
        else
            left = max(left, l[i]), right = min(right, r[i]);//这个点必须同时满足两个条件
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    // 二分
    // log2(1e9)的结果大概是29.8974，可以直接看成常数级
    // 时间复杂度大概就是t*30*n
    int L = 0, R = 1e9;
    while (L < R)
    {
        int const mid = (L + R) >> 1;
        if (check(mid, n)) R = mid;
        else L = mid + 1;
    }

    cout << L << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1907/problem/D