#include <iostream>
#include <queue>
using namespace std;

/*
 * 求连通块
 * 将枚举到的油田压入队列开始搜索
 * 通过队列里的值开始向每个方向枚举
 * 搜到的话直接取消油田标记 并压入队列
 * 枚举到的油田就是连通块的个数
 * */

const int N = 110;
char a[N][N];
int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

void search(int x, int y)
{
    a[x][y] = '*';
    queue<pair<int, int>> q;
    q.emplace(x, y);

    while (!q.empty())
    {
        int const xx = q.front().first;
        int const yy = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int const nx = xx + dx[i];
            int const ny = yy + dy[i];
            if (a[nx][ny] == '@') q.emplace(nx, ny), a[nx][ny] = '*';
            // 如果搜到了就取消油田标记并压入队列，搜索这个坐标是否还有相邻的
        }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m, n != 0 && m != 0)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];

        /// 开始枚举
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] == '@') search(i, j), ans ++;

        cout << ans << endl;
    }
    return 0;
}


// https://www.luogu.com.cn/problem/UVA572