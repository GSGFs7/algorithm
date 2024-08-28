#include <bits/stdc++.h>
using namespace std;

/*
 * 400的数据范围
 * 比赛的时候怎么没看到，难受
 * */

const int N = 410;
bool g[N][N];

int check(int x1, int y1, int x2, int y2)
{
    int cnt = 0;
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            if (g[i][j]) cnt ++;
    return cnt;
}

int main()
{
    int n, m, z;
    cin >> n >> m >> z;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = i; k <= n; k++)
                for (int l = j; l <= m; l++)
                    if (check(i, j, k, l) >= z)
                        ans = min(ans, (k - i + 1) * (l - j + 1));

    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/B3724