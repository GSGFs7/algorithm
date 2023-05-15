#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

// 中间点左侧的穿衣相当于坐标左移，右边相当于坐标右移
// 求出两个极坐标即可求出中间点
// 这俩个极坐标代表两个方向上的最大距离
// 中间的所有值都不会大于这两个值
// 只需要考虑这两个极值点即可
// 使所选点离这两个点最近

const int N = 1e5 + 10;
int a[N], b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int ms = INF, mx = -1 * INF;
    for (int i = 0; i < n; i++)
    {
        mx = max(a[i] + b[i], mx);
        ms = min(a[i] - b[i], ms);
    }

    printf("%.6lf\n", (ms + mx) * 1.0 / 2);
    // printf("%.6lf\n", (long double)(ms + mx) / 2); 会精度不够
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://codeforces.com/problemset/problem/1730/B