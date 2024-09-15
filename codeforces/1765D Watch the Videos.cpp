#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 双指针匹配
 * 前后同时开始，如果相加不大于m就减去这两个视频的观看时间
 * 当两个指针相遇时表示同一个数需要再减去1
 * 以及最后一个视频必须加上1
 * */

const int N = 2e5 + 10;
int a[N];

int main()
{
    int n, m;
    cin >> n >> m;
    long long ans = n;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += a[i];

    sort(a, a + n);

    int l = 0, r = n - 1;
    while (l < r)
    {
        if (a[l] + a[r] <= m) ans -= 2, l ++, r--;// 如果成功匹配 一起跳过
        else r --;// 那个数匹配不了就跳过，相当于加1的观看时间
    }
    if (l == r) ans --;
    cout << ans + 1 << endl;
    return 0;
}


// https://codeforces.com/contest/1765/problem/D