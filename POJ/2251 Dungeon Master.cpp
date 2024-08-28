#include <iostream>
#include <queue>
#include <cstring>
#include <stdlib.h>
using namespace std;

/*
 * 三维版的BFS
 * 在原有的四个方向上在加上对应上下的Z轴
 * */

typedef pair<pair<int, int>, int> PIII;
const int N = 40;
int c, n, m;
char g[N][N][N];
int a[N][N][N];
PIII S, E;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs()
{
    queue<PIII> q;
    q.push(S);
    a[S.first.first][S.first.second][S.second] = 0;

    while (!q.empty())
    {
        PIII now = q.front();
        q.pop();

        // 前后左右
        for (int i = 0; i < 4; i++)
        {
            int const cur = now.first.first;
            int const xx = now.first.second + dx[i];
            int const yy = now.second + dy[i];

            if (xx == 0 || xx == n + 1 || yy == 0 || yy == m + 1) continue;

            if (g[cur][xx][yy] == '.' && a[cur][xx][yy] > a[cur][now.first.second][now.second] + 1)
            {
                a[cur][xx][yy] = a[cur][now.first.second][now.second] + 1;
                q.push({{cur, xx}, yy});
            }
        }

        // 上下
        for (int i = -1; i < 2; i += 2)
        {
            int const cur = now.first.first + i;
            int const xx = now.first.second;
            int const yy = now.second;

            if (cur < 1 || cur > c || g[cur][xx][yy] == '#') continue;

            if (a[cur][xx][yy] > a[now.first.first][xx][yy] + 1)
            {
                a[cur][xx][yy] = a[now.first.first][xx][yy] + 1;
                q.push({{cur, xx}, yy});
            }
        }
    }
}

void init()
{
    memset(&a, 0x3f, sizeof a);
}

void debug()
{
    for (int i = 1; i <= c; i++) {
        cout << "---debug---" << endl;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (a[i][j][k] != 0x3f3f3f3f) cout << a[i][j][k] << ' ';
                else cout << '-' << ' ';
            }
            cout << endl;
        }
    }
}

int main()
{
    while (true) {
        init();

        cin >> c >> n >> m;
        if (!c || !n || !m) exit(0);

        for (int i = 1; i <= c; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= m; k++)
                {
                    cin >> g[i][j][k];
                    if (g[i][j][k] == 'S') S = {{i, j}, k}, g[i][j][k] = '.';
                    if (g[i][j][k] == 'E') E = {{i, j}, k}, g[i][j][k] = '.';
                }

        bfs();
        //debug();

        int const ans = a[E.first.first][E.first.second][E.second];
        if (ans == 0x3f3f3f3f) cout << "Trapped!" << endl;
        else cout << "Escaped in "<< ans << " minute(s)." << endl;
    }
}


// http://poj.org/problem?id=2251