#include <iostream>
#include <cstring>
#include <iomanip>
#include <queue>

using namespace std;

/*
 * 常规的BFS
 * 只需要稍微改一下搜索方向即可
 * */

const int N = 410, p_max = 0x3f, MAX = 0x3f3f3f3f;
int a[N][N];
int n, m, X, Y;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

void search()
{
    queue<pair<int, int>> q;
    a[X][Y] = 0;
    q.emplace(X, Y);

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];

            if (xx < 1 || xx > n || yy < 1 || yy > m)
                continue;

            if (a[xx][yy] > a[now.first][now.second] + 1)
            {
                q.emplace(xx, yy);
                a[xx][yy] = a[now.first][now.second] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> X >> Y;
    memset(&a, p_max, sizeof a);

    search();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (a[i][j] != MAX) printf("%-4d", a[i][j]);
            else printf("%-4d", -1);
        cout << endl;
    }
    return 0;
}