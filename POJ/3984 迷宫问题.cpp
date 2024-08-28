#include <iostream>
#include <queue>
#include <cstring>
#include <cstdlib>// c++98的exit函数在这个头文件里
using namespace std;

/*
 * 最短路走迷宫 + 路径记录
 * 因为不会路径记录，所以再dfs一遍得到路径（n=5的数据范围，怎么写都炸不了）
 *
 * c++98 CE了一片
 * */

typedef pair<int, int> PII;
const int N = 5;
int g[N][N];// 存图
int a[N][N];// 最短路步骤
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<PII> path;// 记录路径

void init()
{
    memset(&a, 0x3f, sizeof a);
    a[0][0] = 0;
    path.push_back(make_pair(0, 0));
}

void bfs()
{
    queue<PII> q;
    q.push(make_pair(0, 0));

    while (!q.empty())
    {
        PII now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            const int xx = now.first + dx[i];
            const int yy = now.second + dy[i];

            if (xx < 0 || xx == 5 || yy < 0 || yy == 5) continue;

            if (g[xx][yy] == 0 && a[xx][yy] > a[now.first][now.second] + 1)
            {
                a[xx][yy] = a[now.first][now.second] + 1;
                q.push(make_pair(xx, yy));
            }
        }
    }
}

void dfs(int x, int y)
{
    if (x == 4 && y == 4)
    {
        int len = path.size();
        for (int i = 0; i < len; i++)
            cout << '(' << path[i].first << ", " << path[i].second << ')' << endl;
        exit(0);
    }

    for (int i = 0; i < 4; i++)
    {
        const int xx = x + dx[i];
        const int yy = y + dy[i];

        if (a[xx][yy] == a[x][y] + 1)
        {
            path.push_back(make_pair(xx, yy));
            dfs(xx, yy);
            path.pop_back();// 回溯
        }
    }
}

void debug()
{
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }

}

int main()
{
    init();

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> g[i][j];

    // 得到最短路
    bfs();
    // debug();

    // 得到路径
    dfs(0, 0);
}


// http://poj.org/problem?id=3984