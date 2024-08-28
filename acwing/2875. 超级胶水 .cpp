//#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

/*
 * 题目描述:
 *  给出n个石子，每个石子有一个重量，你可以选择两个相邻的石子，然后将它们合并成一个石子，
 *  合并后的新石子的重量为合并前的两个石子的重量之和。现在需要将所有的石子合并成一个石子，问最少需要花费多少胶水，
 *  假设需要的胶水在数值上等于两个石子的重量之积。
 * 输入描述:
 *  第一行一个整数n，表示石子的个数。
 *  第二行n个整数，表示每个石子的重量。
 * 输出描述:
 *  一个整数，表示最少需要花费的胶水。
 *
 * 思路:
 *  纯猜...
 *  贪心
 *  所需的胶水的多少明显和石子的重量有关，所以可以先对石子进行排序，然后从左到右遍历，
 *  每次选择两个相邻的石子合并，并更新当前的胶水重量。
 *  没想到真的是这样...
 * */

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    sort(a.begin(), a.end());

    int w = a[0];// 已经合并的石子的重量
    int ans = 0;// 总花费
    for (int i = 1; i < n; i++) {
        ans += w * a[i];
        w += a[i];
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/2878/
// 第十一届蓝桥杯省赛第一场C++ A组