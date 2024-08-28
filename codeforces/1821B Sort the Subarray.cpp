#include <iostream>
using namespace std;

// 将一个数组的一个子区间升序排列，求最大子区间
// tips:前后元素值不一样的必定是经过排序的，只要找出这一部分在扩展一下最大值就可以求解

const int N = 2e5 + 10;
int a[N], b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int i;
    for(i = 0; i < n; i++)
        if (a[i] != b[i]) break;// 从前找到不同的数
    while (b[i - 1] <= b[i] && i > 0) i --;// 看前面那些数还能被包含进来
    int const l = i + 1;

    for (i = n - 1; i >= 0; i--)
        if (a[i] != b[i]) break;// 从后找到不同的数
    while (b[i] <= b[i + 1] && i < n - 1) i ++;// 看后面面哪些数还能被包含进来
    int const r = i + 1;

    cout << l << ' ' << r << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://mirror.codeforces.com/problemset/problem/1821/B