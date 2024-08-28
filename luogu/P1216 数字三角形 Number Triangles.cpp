#include <iostream>
using namespace std;

/*
 * DP | 记忆化搜索
 * 用二维数组从上到下扫一遍
 * 对于当前的选择，每次都选择最大值
 * 扫到底层时就是结果
 *
 * 还有很大的可优化空间
 * */

const int N = 1010;
int a[N][N], f[N][N];

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i + 1; j++)
            cin >> a[i][j];

    /*
    // debug
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i + 1; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
     */

    for (int i = 1; i <= n; i++)// 用i表示层数
    {
        for (int j = 1; j <= n; j++)// 用j表示哪一个
        {
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);// 表示路径，从左上来还是从右上来
        }
    }

    /*
    // debug
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << f[i][j] << ' ';
        cout << '\n';
    }
     */

    // 找到最大值最后落在哪
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    cout << ans << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1216