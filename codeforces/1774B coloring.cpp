#include <iostream>
using namespace std;

// 抽屉原理，每个抽屉不能放相同的物品，只要相同物品数量不超过抽屉个数就可以放下
// 题目保证个元素和为n，可用抽屉原理直接求解，根据抽屉原理，不同的不超过抽屉个数的可以直接不考虑

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int max_n;// 最大区间数
    if (n - n / k * k) max_n = n / k + 1;
    else max_n = n / k;
    int last;// 最后一个区间的大小
    if (n - n / k * k) last = n - n / k * k;
    else last = k;

    bool b = true;
    for (int i = 0, x; i < m; i++)
    {
        cin >> x;
        if (x > max_n) b = false;
        if (max_n == x) last --;// 如果最后一个区间被放满
        if (last < 0) b = false;// 可以放满，但不能溢出
    }
    if (b) puts("YES");
    else puts("NO");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://mirror.codeforces.com/contest/1774/problem/B