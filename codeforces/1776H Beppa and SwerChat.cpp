#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define int long long int
#define endl '\n'
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

/*
 * 给出两个按时间排序的数列，找出可能未在两个计时点间出现的数
 * 思路:b[]数组中最后一个数一定有未出现的可能性，依次从b[]最后开始向前找，a[]数组耗尽后还剩下的那些数 就是必定出现过的数
 * */

using namespace std;

const int N = 1e5 + 10;
int a[N];
int b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int x = n - 1;
    int y = n - 1;
    int ans = 0;// 可能未出现的个数
    while (true)
    {
        while (a[x] != b[y] && x >= 0) x--;// 从后面开始扫，找到一个相同的数，这个数就有可能是未出现的
        if (x < 0) break;// 需要判断a[0]的情况
        y --;
        ans ++;
    }
    cout << n - ans << endl;// 减去ans得到必定出现的个数
}

signed main()
{
    IOS

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/problemset/problem/1776/H