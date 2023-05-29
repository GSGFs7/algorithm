#include <iostream>
#include <queue>
#include <cstring>
#include <deque>
#define endl '\n'
using namespace std;

/*
 * 两次BFS求出到每个点的最短路
 * 然后找到两者相加最小的值
 * */

const int N = 210, INF = 0x3f3f3f3f;
int n, m;
char a[N][N];
int pm[N][N], py[N][N];// 到对应位置的最短路
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
pair<int ,int> p_m;
pair<int, int> p_y;

/// 搜索Y的最短路
void bfs_y()
{
    queue<pair<int, int>> q;
    q.push(p_y);
    py[p_y.first][p_y.second] = 0;
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] == '#' || py[xx][yy] != -1)// 如果不符合条件
                continue;
            py[xx][yy] = py[now.first][now.second] + 1;
            q.emplace(xx, yy);
        }
    }
}

/// 搜索M的最短路
void bfs_m()
{
    queue<pair<int, int>> q;
    q.push(p_m);
    pm[p_m.first][p_m.second] = 0;
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m || a[xx][yy] == '#' || pm[xx][yy] != -1)
                continue;
            pm[xx][yy] = pm[now.first][now.second] + 1;
            q.emplace(xx, yy);
        }
    }
}

/// 寻找最小值
int search()
{
    int ans = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '@' && (pm[i][j] != -1 && py[i][j] != -1))/// 要记得判能不能到这个点，卡了两天
                ans = min(ans, pm[i][j] + py[i][j]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    while (cin >> n >> m)
    {
        memset(&py, -1, sizeof py);
        memset(&pm, -1, sizeof pm);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'Y') p_y = {i, j};
                if (a[i][j] == 'M') p_m = {i, j};
            }

        bfs_y();
        bfs_m();
        cout << 11LL * search() << endl;

/*
        // debug
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cout << pm[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << py[i][j] << ' ';
            cout << endl;
        }
*/
    }
    return 0;
}


// https://acm.hdu.edu.cn/showproblem.php?pid=2612