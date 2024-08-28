#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*
 * 求连通块
 * 海水上涨，与海相邻的块会被海水淹没，求有多少个岛会被完全淹没
 *
 * 注意：一个大岛可能会被分割成几个小岛！！！
 * 用两次BFS会得到错误答案
 * 因为这个WA了好好多发
 * 可以直接BFS判连通块，然后再判断连通块中是否有未被淹没的地方，改完后一遍过
 * */
/* 数据
7
.......
.##.##.
.#####.
.##.##.
.......
...##..
.......
 */

typedef pair<int, int> PII;
const int N = 1010;
char g[N][N];
bool vis[N][N];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;

bool check(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        const int xx = x + dx[i];
        const int yy = y + dy[i];

        if (g[xx][yy] == '.') return false;
    }
    return true;
}

void bfs(int x, int y)
{
    queue<PII> q;
    q.emplace(x, y);
    bool flag = false;
    vis[x][y] = true;

    while (!q.empty())
    {
        PII now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];

            if (xx < 1 || xx > n || yy < 1 || yy > n || vis[xx][yy]) continue;

            if (g[xx][yy] == '#')
            {
                q.emplace(xx, yy);
                vis[xx][yy] = true;
            }
        }

        if (check(now.first, now.second)) flag = true;
    }

    if (!flag) ans ++;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] == '#' && !vis[i][j]) bfs(i, j);

    cout << ans << endl;
    return 0;
}


// https://www.lanqiao.cn/problems/178/learning/
// https://www.luogu.com.cn/problem/P8662


// 《算法竞赛》给出的解 DFS
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char mp[N][N];
int vis[N][N] = {0};
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int flag;

void dfs(int x, int y)
{
    vis[x][y] = true;
    if (mp[x][y + 1] == '#' && mp[x][y - 1] == '#' &&
        mp[x + 1][y] == '#' && mp[x - 1][y] == '#')
        flag = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + d[i][0], ny = y + d[i][1];
        if (vis[nx][ny] == 0 && mp[nx][ny] == '#')
            dfs(nx, ny);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> mp[i]; // 直接读入char*字符串 妙啊

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (mp[i][j] == '#' && vis[i][j] == 0)
            {
                flag = false;
                dfs(i, j);
                if (flag == 0) ans ++;
            }

    cout << ans << endl;
    return 0;
}
 */