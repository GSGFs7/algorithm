#include <iostream>
using namespace std;

/*
 * DP
 * 从左上走到右下
 * f[i][j]的值由左边的数(f[i][j-1])或者上边的数(f[i-1][j])得到
 * 每一步都取最大值，最后在f[n][m]处集合，这个点就是最终的答案
 * */

const int N = 110;
int a[N][N], f[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 这个点由上方的数或者左方的数得到
            f[i][j] = max(f[i - 1][j] + a[i][j], f[i][j - 1] + a[i][j]);
        }
    }

    cout << f[n][m] << '\n';
}

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.luogu.com.cn/problem/U280643