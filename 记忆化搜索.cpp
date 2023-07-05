#include <iostream>
using namespace std;

/*
 * DP
 * 记忆化搜索
 * 要想求一个值就先要求出他的子集(子集中的一个值就是DP的一个状态)
 * 再根据子集求出这个数
 * 必须无环
 * */

const int N = 310;
int a[N][N];
int f[N][N];// f[i][j]从i,j开始的最大值
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int dp(int x, int y)
{
    if (f[x][y] != 0) return f[x][y];

    int res = 1;// 初始化为1，至少都能取得1
    for (int i = 0; i < 4; i++)// 向四个方向搜索，取最大值
    {
        int const xx = x + dx[i];
        int const yy = y + dy[i];

        if (xx == 0 || xx == n + 1 || yy == 0 || yy == m + 1) continue;
        if (a[xx][yy] < a[x][y]) res = max(res, dp(xx, yy) + 1);
    }

    return f[x][y] = res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, dp(i, j));

    cout << res << endl;
    return 0;
}


// https://www.acwing.com/problem/content/903/