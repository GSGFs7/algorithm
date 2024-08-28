#include <iostream>
#include <queue>
using namespace std;

/*
 * 简单的bfs
 * 直接从起点搜索即可
 * */

const int N = 1010, MAX =   0x3f3f3f3f;
int a[N][N];
int x1, x2, y1, y2;
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<int, int>> q;
    q.emplace(x1, y1);
    a[x1][y1] = 0;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++)
        {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];

            if (xx < 1 || xx > n || yy < 1 || yy > n)
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
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == '0') a[i][j] = MAX;
            else a[i][j] = -1;
        }
    cin >> x1 >> y1 >> x2 >> y2;

    bfs();

    cout << a[x2][y2] << endl;
    return 0;
}