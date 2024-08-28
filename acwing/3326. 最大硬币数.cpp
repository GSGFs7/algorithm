#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 求（反）对角线上数字的和 */

const int N = 1010;
int a[N][N];
int cases = 0;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    long long  ans = 0;

    // 先比较一边，y不变，比较右上角
    for (int i = 0; i <= n; i++)
    {
        long long x = i, y = 0, sum = 0;
        while (x <= n && y <= n) x ++, y ++, sum += a[x][y];
        ans = max(ans, sum);
    }

    // 再比较另一边，x不变，比较左下角
    for (int i = 1; i <= n; i++)
    {
        long long x = 0, y = i, sum = 0;
        while (x <= n && y <= n) x ++, y ++, sum += a[x][y];
        ans = max<long long>(ans, sum);// 强制使用long long类型比较
    }

    cout << "Case #" << ++ cases << ": " << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/3329/