#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*
 * 人的BFS和火的BFS叠加求出是否存在最短路逃出火海
 * 先求出火蔓延到的每个点对应的时间
 * 在BFS人的路程，不能穿过火和围墙
 * 有点类似于连通块
 * */

const int N = 1010, INF = 0x3f3f3f3f;
char a[N][N];
int fire[N][N];// 每个点火焰抵达的时间
bool vis[N][N];// 是否去过
// Q：为什么不能再次以最短路为判断依据  Solved：time可能会被新加入的点(time+1)挤到后面导致答案变大，所以用vis很方便
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node
{
    int x{};
    int y{};
    int time = INF;
}man[N][N], joe;

void solve()
{
    int n, m;// 高与宽
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    memset(&vis, false, sizeof vis);// 这个数组不会被覆盖，需要手动设为false

    queue<Node> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            fire[i][j] = INF;
            if (a[i][j] == '#') fire[i][j] = 0, fire[i][j] = man[i][j].time = 0;
            // 0就表示无论什么时候都不能走，也可以表示障碍物
            if (a[i][j] == 'J') joe = {i, j, 0}, fire[i][j] = man[i][j].time = 0;
            // 走最短路必然不能回到原点
            if (a[i][j] == 'F') q.push(Node {i, j, 0}), fire[i][j] = man[i][j].time = 0;
            // 存入火焰位置
        }
/*
    // debug
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << fire[i][j] << ' ';
        cout << endl;
    }
*/
    /// BFS搜索火焰
    while (!q.empty())
    {
        int const xx = q.front().x;
        int const yy = q.front().y;
        int const time = q.front().time;
        q.pop();

        // 向四个反向搜索
        for (int i = 0; i < 4; i++)
        {
            int const nx = xx + dx[i];
            int const ny = yy + dy[i];
            if (fire[nx][ny] > time + 1)
            {
                fire[nx][ny] = time + 1;
                q.push(Node {nx, ny, time + 1});
            }
        }
    }

/*
    // debug
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << fire[i][j] << ' ';
        cout << endl;
    }
*/

    /// BFS搜索人
    q.push(joe);
    while (!q.empty())
    {
        int const xx = q.front().x;
        int const yy = q.front().y;
        int const time = q.front().time;
        q.pop();

        // debug
        // if (xx == 0 || xx > n || yy == 0 || yy > m) continue;

        // 如果抵达出口
        if (xx == 1 || xx == n || yy == 1 || yy == m) return cout << time + 1 << endl, void();

        for (int i = 0; i < 4; i++)
        {
            int const nx = xx + dx[i];
            int const ny = yy + dy[i];
            if (!vis[nx][ny] && fire[nx][ny] > time + 1)
            {
                vis[nx][ny] = true;
                man[nx][ny].time = time + 1;
                q.push(Node {nx, ny, time + 1});
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
/*
    //debug
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << man[i][j].time << ' ';
        cout << endl;
    }
*/
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.luogu.com.cn/problem/UVA11624

/* 二刷 2023.7.13
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1010;
char g[N][N];// 存图
int n, m;
pair<int, int> J;// joe的位置
queue<pair<int, int>> F;// 火的位置的队列
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int fire[N][N], joe[N][N];// bfs后的抵达时间
bool flag;

/// fire的BFS
void bfs_f(int x, int y)
{
    queue<pair<int, int>> q;
    q.emplace(x, y);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];

            if (xx == 0 || xx == n + 1 || yy == 0 || yy == m + 1) continue;

            if (fire[xx][yy] > fire[now.first][now.second] + 1 && g[xx][yy] != '#') {
                fire[xx][yy] = fire[now.first][now.second] + 1;
                q.emplace(xx, yy);
            }
        }
    }
}

/// joe的BFS
void bfs_j(int x, int y)
{
    queue<pair<int, int>> q;
    q.emplace(x, y);

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];

            if (g[xx][yy] == '#') continue;
            if (xx == 0 || xx == n + 1 || yy == 0 || yy == m + 1)
                return flag = true, cout << joe[now.first][now.second] + 1 << endl, void();

            if (joe[xx][yy] > joe[now.first][now.second] + 1 && joe[now.first][now.second] + 1 < fire[xx][yy]) {
                joe[xx][yy] = joe[now.first][now.second] + 1;
                q.emplace(xx, yy);
            }
        }
    }
}

void debug()
{
    cout << "fire" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << fire[i][j] << ' ';
        cout << endl;
    }
    cout << "joe" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << joe[i][j] << ' ';
        cout << endl;
    }
}

void solve()
{
    flag = false;
    memset(&fire, 0x3f, sizeof fire);
    memset(&joe, 0x3f, sizeof joe);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'J') J = {i, j};
            if (g[i][j] == 'F') F.emplace(i, j);// 题目说只有一个joe，没说只有一个fire
        }

    /// 没问题
for (int i = 1; i <= n; i++)
{
for (int j = 1; j <= m; j++)
cout << g[i][j] << ' ';
cout << endl;
}
//

while (!F.empty())
{
auto now = F.front();
F.pop();
fire[now.first][now.second] = 0;
bfs_f(now.first, now.second);
}

joe[J.first][J.second] = 0;
bfs_j(J.first, J.second);

if (!flag) cout << "IMPOSSIBLE" << endl;
// debug();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
 */