#include <iostream>
#include <vector>
using namespace std;

/*
 * 依次二分答案
 * 标记符合条件的数 找到最大值
 * */

const int N = 1e6 + 10;
vector<int> a[N], b[N];
int n, m;

// TODO 二分控制
bool check(int mid)
{
    // 上标记
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] >= mid) b[i][j] = 1;
            else b[i][j] = 0;

    // 统计达到要求的个数
    // DP 寻找最大正方形 洛谷P1387 https://www.luogu.com.cn/problem/P1387
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (b[i][j]) b[i][j] = min(min(b[i - 1][j], b[i][j - 1]), b[i - 1][j - 1]) + 1, ans = max(ans, b[i][j]);

/*
    // debug
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= m; j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }
*/

    return ans >= mid;
}

void solve()
{
    /// 读入
    cin >> n >> m;
    int x;
    for (int i = 0; i <= m; i++) a[0].push_back(0), b[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        a[i].clear(), b[i].clear(), a[i].push_back(0), b[i].push_back(0);
        for (int j = 1; j <= m; j++)
            cin >> x, a[i].push_back(x), b[i].push_back(0);
    }

    // 查找答案
    int l = 0, r = N;
    int mid;
    while (l < r)
    {
        mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
// 耗时 1653 ms
// cin，cout加速 和 ans取值并入DP后 264ms

// https://codeforces.com/contest/1731/problem/D