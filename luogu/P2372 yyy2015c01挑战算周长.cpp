#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

/*
 * 求连通块
 * 再根据连通块上的每个块计算边长
 * 四边每相邻一个边长就加上4-cnt
 * */

const int N = 30;
char a[N][N];
bool vis[N][N];
int n, m, X, Y;
int ans = 0;
int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

void search()
{
    queue<pair<int, int>> q;
    q.emplace(X, Y);
    vis[X][Y] = true;

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];

            if (xx == 0 || xx == m + 1 || yy == 0 || yy == n + 1)
                continue;

            if (a[xx][yy] == 'X' && !vis[xx][yy]) {
                q.emplace(xx, yy);
                vis[xx][yy] = true;
            }
        }

        // 每一个入队的元素都是连通块里的成员，都要求一次边长
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int const nx = now.first + dx[j];
            int const ny = now.second + dy[j];
            if (a[nx][ny] == 'X') cnt ++;
        }
        ans += 4 - cnt;
    }
}

int main()
{
    cin >> m >> n >> X >> Y;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    search();

    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P2372