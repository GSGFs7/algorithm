#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*
 * 向十二个反向搜索
 * 没什么变化
 * 貌似可以打表？
 * */

const int N = 30, p_MAX = 0x3f, MAX = 0x3f3f3f3f;
int a[N][N], b[N][N];
int x1, y1, x2, y2;
int dx[12] = {1, 1, 2, 2, 2, 2, \
    -1, -1,-2, -2, -2, -2};
int dy[12] = {2, -2, 2, 1, -1, -2, \
    2, -2, 2, 1, -1, -2};

void search()
{
    queue<pair<int, int>> q;
    q.emplace(1, 1);
    a[1][1] = 0;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 12; i++)
        {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];

            if (xx < 1 || xx > 20 || yy < 1 || yy > 20)
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
    memset(&a, p_MAX, sizeof a);
    memset(&b, p_MAX, sizeof b);
    cin >> x1 >> y1 >> x2 >> y2;

    search();

    cout << a[x1][y1] << endl <<  a[x2][y2] << endl;

    /*
    // debug
    for (int i = 1; i <= 20; i++)
    {
        for (int j =1; j <= 20; j++)
            if (a[i][j] != MAX) cout << a[i][j] << ' ';
            else cout << '-' << ' ';
        cout << endl;
    }
     */

    return 0;
}



// https://www.luogu.com.cn/record/111646753