#include <iostream>
#include <cstring>

using namespace std;

int  a[15][15];

int main()
{
    int n;
    cin >> n;
    int cnt = 1;
    memset(a, 0, sizeof a);
    a[0][0] = 1;
    int x = 0, y = 0;

    while (cnt < n * n)// 没走完再来一遍
    {
        while (a[x][y + 1] == 0 && y < n - 1) a[x][++y] = ++cnt;// 向右走到头，不能为y < n - 1会超出边界
        while (a[x + 1][y] == 0 && x < n - 1) a[++x][y] = ++cnt;// 向下走到头
        while (a[x][y - 1] == 0 && y > 0) a[x][--y] = ++cnt;// 向左走到头
        while (a[x - 1][y] == 0 && x > 0) a[--x][y] = ++cnt;// 向上走到头
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", a[i][j]);
        }
        puts("");
    }
    return 0;
}