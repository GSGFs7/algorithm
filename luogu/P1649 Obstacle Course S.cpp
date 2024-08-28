#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
 * 第一眼想到的做法 BFS
 * 先BFS标记到每个点的时间
 * 再DFS出所有的路径，取最短的那个
 * 因为是对b求内所有的可到达点的最短路
 * 那么到B有多条路时b的值必定连续
 * 其实对任意两两相邻的点都连续
 * */
// 不知道抽了什么风竟然还能想到这个

typedef pair<int, int> PII;
const int N = 110;
char a[N][N];
int b[N][N];
PII A, B;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int cnt = -1;
int ans = 0x3f3f3f3f;

/// 常规的BFS
void bfs(int x, int y)
{
    // 记得初始化
    memset(&b, 0x3f, sizeof b);
    b[x][y] = 0;
    queue<PII> q;
    q.emplace(A);

    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int const xx = now.first + dx[i];
            int const yy = now.second + dy[i];

            if (xx == 0 || xx == n + 1 || yy == 0 || yy == n + 1) continue;
            if (a[xx][yy] != 'x' && b[xx][yy] > b[now.first][now.second] + 1)
            {
                b[xx][yy] = b[now.first][now.second] + 1;
                q.emplace(xx, yy);
            }
        }
    }
}

/// dfs回溯
void dfs(int x, int y, int last)// last 0表示y，1表示x
{
    if (B.first == x && B.second == y)
    {
        ans = min(cnt, ans);// 到达终点，更新答案
        return ;
    }

    for (int i = 0; i < 4; i++)
    {
        int const xx = x + dx[i];
        int const yy = y + dy[i];

        if (xx == 0 || xx == n + 1 || yy == 0 || yy == n + 1) continue;
        if (b[xx][yy] == b[x][y] + 1)// 也相当于剪枝吧
        {
            if (last != i % 2) cnt ++;// 如果转向了就加1
            dfs(xx, yy, i % 2);
            if (last != i % 2) cnt --;// 回溯
        }
    }
}

int main()
{
    // debug   这个是真的方便
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A') A = {i, j};
            if (a[i][j] == 'B') B = {i, j};
        }

    /// 先BFS一遍
    bfs(A.first, A.second);

    // debug
    /*
    cout << B.first << '-' << B.second << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << b[i][j] << ' ';
        cout << endl;
    }
*/

    /// 在DFS枚举出最短的路径
    dfs(A.first, A.second, -1);

    if (ans != 0x3f3f3f3f) cout << ans << endl;
    else cout << -1 << endl;// 还有没法到达B的情况，一定要记得
    return 0;
}


// https://www.luogu.com.cn/problem/P1649