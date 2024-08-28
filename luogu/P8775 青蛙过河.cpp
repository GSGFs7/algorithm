#include <iostream>
using namespace std;

/*
 * 对于步长j
 * 因为连续走2x次，所以不存在对于i~i+j小于2x的区间
 * */

const int N = 1e5 + 10;
int a[N], s[N];
int n, x;

// 往返x次与连续走2x次等价
bool check(int mid)
{
    for (int i = 1; i + mid - 1 < n; i++)
    {
        int const j = i + mid - 1;
        if (s[j] - s[i - 1] < x) return false;
    }
    return true;
}

signed main()
{
    cin >> n >> x;
    x <<= 1;
    for (int i = 1; i < n; i++)
        cin >> a[i], s[i] = a[i] + s[i - 1];// 前缀和

    int l = 1, r = n;
    while (l < r)// 二分答案
    {
        int const mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
    return 0;
}

// https://www.luogu.com.cn/problem/P8775
// https://www.acwing.com/problem/content/4650/