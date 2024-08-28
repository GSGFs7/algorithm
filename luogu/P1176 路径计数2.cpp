#include <iostream>
using namespace std;

/// 递推思想
/* 统计向右和向下的路径 */

const int N = 1010;
int a[N][N];
bool b[N][N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        b[x][y] = true;
    }

    // 递推式
    a[1][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = ((b[i - 1][j] ? 0 : a[i - 1][j]) + (b[i][j - 1] ? 0 : a[i][j - 1])) % 100003;

    cout << a[n][n] << endl;
    // debug
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
     */
    return 0;
}


// https://www.luogu.com.cn/problem/P1176