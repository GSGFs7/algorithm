#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

/*
 * 求连通块
 * 找到一个目标就加入队列
 * 利用队列中的元素进行下一次搜索
 * 如果再找到目标就继续加入队列
 * 直到没有元素可加为止
 * */

const int N = 110;
int a[N][N];// 存图
int n, m;
int ans = 0;
int dx[4] = {1, 0, -1, 0};// 向四个方向
int dy[4] = {0, 1, 0, -1};

/// 判连通块
void search(int x, int y)
{
    ans ++;// 答案数加一
    queue<pair<int, int>> q;
    q.emplace(x, y);

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int const nx = now.first + dx[i];
            int const ny = now.second + dy[i];
            if (a[nx][ny] != 0)
                q.emplace(nx, ny), a[nx][ny] = 0;
            // 加入队列并标记
        }
    }
}

int main()
{
    cin >> n >> m;

    char c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c, a[i][j] = c - '0';

    // 找到没有被判过的连通块
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j]) search(i, j);

    cout << ans << endl;

    return 0;
}