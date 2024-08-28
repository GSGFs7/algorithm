#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出很多个水滴，求花盆摆在哪个位置,可以用最小的直径接到高度差大于m的两个水滴
 *
 * 例如：
 * 4 5
 * 6 3
 * 2 4
 * 4 10
 * 12 15
 * 这组数据中最小直径是2，由(2,4)和(4,10)这两个点得到
 *
 * 以x为标准从小到大排序，方便计算处在x轴上的花盆的直径
 * 如果一个点一个点向后暴力搜索，时间复杂度是O(n^2)一定会超时
 * 可以用两个单调队列分别求最大值和最小值，当单调队列找了了符合条件的数就开始缩小花盆的左端点
 * 以求得最小的花盆直径，每个点都进入队列常数次，时间复杂度为O(n)
 * */

typedef pair<int, int> PII;
const int N = 1e5 + 10;
int maxQ[N], minQ[N];   // maxQ求最大值，minQ求最小值

bool cmp(PII a, PII b)
{
    return a.first < b.first;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<PII> a(n);
    for (int i = 0, x, y; i < n; i++) cin >> x >> y, a[i] = {x, y};

    sort(a.begin(), a.end(), cmp);  // 以x轴从大到小排序
//    cout << a[0].first << endl;

    int ans = 0x3f3f3f3f3f3f3f3f;
    int L = 0;   // 花盆的左端点
    int head1, head2, tail1, tail2;
    head1 = head2 = 0;
    tail1 = tail2 = -1;
    for (int i = 0; i < n; i++) // 先遍历一遍，看是否右符合条件的两个数，i即为右端点
    {
        /// 同时维护两个单调队列
        // 求最大值的单调队列
        while (head1 <= tail1 && a[maxQ[tail1]].second <= a[i].second) tail1 --;
        maxQ[++ tail1] = i;
//        cout << a[maxQ[head1]].second << '\n';
        // 求最小值的单调队列
        while (head2 <= tail2 && a[minQ[tail2]].second >= a[i].second) tail2 --;
        minQ[++ tail2] = i;
//        cout << a[minQ[head2]].second << '\n';

        // 如果已经包括了符合条件的两个数，缩小范围
        while (L < i && a[maxQ[head1]].second - a[minQ[head2]].second >= m)
        {
            ans = min(ans, a[i].first - a[L].first);
            L ++;   // 左端点向中间缩小
            while (head1 <= tail1 && maxQ[head1] < L) head1 ++; // 弹出
            while (head2 <= tail2 && minQ[head2] < L) head2 ++;
        }
    }

    if (ans < 0x3f3f3f3f3f3f3f3f) cout << ans << '\n';
    else cout << -1 << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P2698