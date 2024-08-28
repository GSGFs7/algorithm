#include <iostream>
#include <queue>
using namespace std;

/*
 * 求最短路，三维版
 * 先判四个方向再判上下
 * 找到大于 当前值+1 的位置就加入队列继续求最短路
 * 如果不加一的话可能会重新再算一遍原来就已经算过的最小值
 * */

const int N = 35, MAX = 0x3f3f3f3f;
int a[N][N][N];
int l, r, c;
int S_l, S_r, S_c;// 起点坐标
int E_l, E_r, E_c;// 终点坐标
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// 搜索答案
void search(int cur, int x, int y, int step)
{
    queue<pair<int, pair<int, int>>> q;// pair套pair达到三维
    q.push({cur, {x, y}});// 用q.emplace()会报错
    a[cur][x][y] = step;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        // 查找能够更新的值
        for (int i = 0; i < 4; i++)
        {
            int const xx = now.second.first + dx[i];
            int const yy = now.second.second + dy[i];
            // 过滤条件
            if (xx == 0 || xx == r + 1 || yy == 0 || yy == c + 1)
                continue;

            if (a[now.first][xx][yy] > a[now.first][now.second.first][now.second.second] + 1)
            {
                q.push({now.first, {xx, yy}});
                a[now.first][xx][yy] = 1 + a[now.first][now.second.first][now.second.second];
            }
        }

        // 查找上下能够更新的值
        for (int i = -1; i < 2; i += 2)
        {
            if (now.first + i == 0 || now.first + i == l + 1)
                continue;

            if (a[now.first + i][now.second.first][now.second.second] > a[now.first][now.second.first][now.second.second] + 1)
            {
                q.push({now.first + i, {now.second.first, now.second.second}});
                a[now.first + i][now.second.first][now.second.second] = a[now.first][now.second.first][now.second.second] + 1;
            }
        }
    }
}

int main()
{
    cin >> l >> r >> c;
    for (int i = 1; i <= l; i++)
    {
        char x;
        for (int j = 1; j <= r; j++)
            for (int k = 1; k <= c; k++)
            {
                cin >> x;
                if (x == '.') a[i][j][k] = MAX;// 可以走的路
                else if (x == '#') a[i][j][k] = -1;
                else if (x == 'S')
                    a[i][j][k] = MAX, S_l = i, S_r = j, S_c = k;
                else if (x == 'E')
                    a[i][j][k] = MAX, E_l = i, E_r = j, E_c = k;
            }
        getchar();// 读掉空行
    }

    search(S_l, S_r, S_c, 0);

    if (a[E_l][E_r][E_c] == MAX)
        cout << "Trapped!\n" << endl;// 注意感叹号
    else
        printf("Escaped in %d minute(s).\n", a[E_l][E_r][E_c]);

    /*
    // debug
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= r; j ++)
        {
            for (int k = 1; k <= c; k ++)
                cout << a[i][j][k] << ' ';
            cout << endl;
        }
        cout << endl;
    }
     */
    return 0;
}


// https://www.luogu.com.cn/problem/P2360