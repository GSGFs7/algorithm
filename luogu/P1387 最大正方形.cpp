#include <iostream>
using namespace std;

/// 动态规划 || 前缀和
// b数组表示这个点对应的最大正方形
// 当左上方的三个点都为正方形时（包括1），他们能够拼出的的最大正方形取决于最短的那条边
// 所以找出最短边就能找到最大正方形

// 如：
// 1 1 1
// 1 1 1
// 0 1 1
// 左上角和上方都为2，但是左边为1，最大正方形为1+1


// a[]
// 0 1 1 1
// 1 1 1 0
// 0 1 1 0
// 1 1 0 1

// b[]
// 0 1 1 1
// 1 1 2 0
// 0 1 2 0
// 1 1 0 1

const int N = 110;
int a[N][N], b[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                b[i][j] = min(min(b[i-1][j-1], b[i][j-1]), b[i-1][j]) + 1;
                ans = max(ans, b[i][j]);
            }
        }
    cout << ans;
    return 0;
}

// https://www.luogu.com.cn/problem/P1387