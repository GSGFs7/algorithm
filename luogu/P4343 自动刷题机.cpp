#include <iostream>
#define int long long
using namespace std;

/// 三区间二分
/*
 * n越小得到的k切题树越大，可在范围内二分
 * check()<k时二分右边的数
 * check()>k时二分左边的数
 * check()=k时根据是找左端点还是右端点进行划分，如果找左端点右边部分就不要，反之亦然
 * */

const int N = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int a[N];
int l, k;

/// 模拟
int check(int mid)
{
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= l; i++)
    {
        sum += a[i];
        if (sum < 0) sum = 0;
        if (sum >= mid) sum = 0, cnt ++;
    }
    return cnt;
}

signed main()
{
    cin >> l >> k;
    for (int i = 1; i <= l; i++)
        cin >> a[i];

    /// 二分左端点
    int left = 1, right = INF;
    int mid;
    int ans = INF;// ans不可能取到INF，如果最后的ans为INF就表示不存在这样的区间
    while (left <= right)// 加上=
    {
        mid = (left + right) >> 1;
        if (check(mid) > k) left = mid + 1;
        else if (check(mid) < k) right = mid - 1;
        else ans = mid, right = mid - 1;// 找到可行答案继续找左端点
    }

    /// 判是否无解
    if (ans == INF) { cout << -1 << endl; exit(0); }
    else cout << ans << ' ';

    /// 二分右端点
    left = 1, right = INF;
    while (left <= right)// 加上=，因为最后的答案有变量接收，left和right错位也没关系，不然会出问题
    {
        mid = (left + right) >> 1;
        if (check(mid) > k) left = mid + 1;
        else if (check(mid) < k) right = mid - 1;
        else ans = mid, left = mid + 1;
    }
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P4343