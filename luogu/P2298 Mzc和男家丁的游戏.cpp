#include <iostream>
#include <queue>
using namespace std;

/*
 * 简单的BFS
 * */

const int N = 2010, MAX = 0x3f3f3f3f;
int a[N][N];
int n, m;
pair<int, int> M, D;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<int, int>> q;
    q.emplace(M.first, M.second);

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '.') a[i][j] = MAX;
            else if (c == 'm') M.first = i, M.second = j, a[i][j] = 0;
            else if (c == 'd') D.first = i, D.second = j, a[i][j] = MAX;
            else a[i][j] = -1;
        }

    bfs();

    if (a[D.first][D.second] != MAX) cout << a[D.first][D.second] << endl;
    else cout << "No Way!" << endl;

    /*
    //debug
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m ; j++)
            if (a[i][j] != MAX) cout << a[i][j] << ' ';
            else cout << '-' << ' ';
        cout << endl;
    }
     */

    return 0;
}


// https://www.luogu.com.cn/problem/P2298