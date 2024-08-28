#include <iostream>
#include <queue>
using namespace std;

const int N = 22;
char a[N][N];
bool vis[N][N];
int w, h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/// 判连通块
int search(int x, int y)
{
    int ans = 0;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    vis[x][y] = true;// 第一块不能判重

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        ans ++;// 块数

        for (int i = 0; i < 4; i++)
        {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];
            if (xx == 0 || xx == h + 1 || yy == 0 || yy == w + 1)
                continue;

            if (a[xx][yy] != '#' && !vis[xx][yy])// 不能走和已经走过的
                q.emplace(xx, yy), vis[xx][yy] = true;
        }
    }

    return ans;
}

int main()
{
    cin >> w >> h;
    pair<int, int> start;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> a[i][j];
            // 记录开始位置
            if (a[i][j] == '@') start = {i, j};
        }

    cout << search(start.first, start.second) << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1683