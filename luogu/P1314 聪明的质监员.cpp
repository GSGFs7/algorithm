#include <iostream>
#define int long long// 不开long long见祖宗
using namespace std;

/*
 * 求一个W，使得|s-y|的值最小
 * 因为答案单调
 * 用二分枚举答案
 * 通过二分靠近y=s的那个点
 * */

const int N = 2e5 + 10, INF = 0x3f3f3f3f, LL_INF = 0x3f3f3f3f3f3f3f3f;// int的INF对于long long来说太小了
int w[N], v[N], l[N], r[N];
int pre_n[N], pre_v[N];// 两个前缀和数组
int n, m;
int s;
int sum;// 与标准值的差值

bool check(int mid)
{
    for (int i = 1; i <= n; i++)// 前缀和，方便快速查找，因为加入前缀和的标准会变化，所以每次都要重新求
        if (w[i] >= mid) pre_n[i] = pre_n[i - 1] + 1, pre_v[i] = pre_v[i - 1] + v[i];
        else pre_n[i] = pre_n[i - 1], pre_v[i] = pre_v[i - 1];

    int y = 0;
    for (int i = 1; i <= m; i++)// 按照题目给出的公式相加
        y += ((pre_n[r[i]] - pre_n[l[i] - 1]) * (pre_v[r[i]] - pre_v[l[i] - 1]));

    sum = llabs(s - y);// long long的abs()
    return y > s;
}

signed main()
{
    cin >> n >> m >> s;
    int left = INF, right = 0;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i], left = min(left, w[i]), right = max(right, w[i]);
    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i];

    /// 二分查找
    // 因为随着w的增加，y的值会减小，在范围内单调
    int mid;
    int ans = LL_INF;
    while (left < right)
    {
        mid = (left + right + 1) >> 1;
        if (check(mid)) left = mid;
        else right = mid - 1;
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

// https://www.luogu.com.cn/problem/P1314