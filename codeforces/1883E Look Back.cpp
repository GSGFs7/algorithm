#include <bits/stdc++.h>
#define int long long
using namespace std;

/// 前缀和
// 求单调递增需要的操作数
/*
 * 对于一个数列，可以选择一个数乘上2，求最少需要多少次这样的操作使数列单调递增
 *
 * 以第一个数为准，进行前缀和计算
 * 每次统计下一个数对于前一个数而言的前缀和（能被2乘多少次）
 * 因为需要单调递增，所以前缀和操作必须不能小于0
 * 将所有的前缀和相加得到了最后的值即为结果
 * （脑子转不过来，根本想不到这个思路，打死没想到前缀和还能这么用）
 *
 * 解释：
 *  因为当前的前缀和是针对前面最大的一个数而言的
 *  每一位上的前缀和都是随当前数值的变化而变化的
 *  如果一个数大于前面的数
 *  那么这个数就不用计算了，并且前缀和计数器归0
 *  这个数后面的数的起点都会被强行拉高
 *  对应的，需要操作的次数也会被拉高
 *
 * 最开始我的思路：
 *  求前面的数是后面的数的2的几次方倍(log2)，是几次就左移几次
 *  but，题目的数据会造成re（除以0，也就是说会将所有的非零数都会被移除范围），不知道为什么
 *
 * 看到别人有用二分的，我当时怎么没想到
 * (试了下，CF直接告诉我溢出了，还是不能直接存处理后的数据（或许可以前期就处理完成？）)
 * */

const int N = 1e5 + 10;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

    int ans = 0;    // 最终的答案
    int cnt = 0;    // 用于计算前缀和
    for (int i = 1; i < n; i++)
    {
        int l = a[i - 1], r = a[i];
        int rt = 0; // 记录这个数需要操作多少次

        // 对于前缀和而言是减还是增
        while (l < r) l *= 2, rt --;
        while (l > r) r *= 2, rt ++;

        cnt = max(0LL, cnt + rt);   // 不能为0
        ans += cnt;                 // 对于起点而言的操作数
    }
    cout << ans << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t --)
        solve();
    return 0;
}


// https://codeforces.com/contest/1883/problem/E
// 202 ms	800 KB