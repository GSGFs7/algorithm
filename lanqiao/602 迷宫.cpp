#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 60, INF = 0x3f3f3f3f;
int g[N][N];
int step[N][N];
const int n = 30, m = 50;
int const dx[4] = {1, 0, 0, -1};// 对应字典序，调半天原来这里错了，对应的是数组
int const dy[4] = {0, -1, 1, 0};// 不能用上下左右的方式

void BFS() {
    queue<PII> q;
    q.emplace(1, 1);
    step[1][1] = 0;

    while (!q.empty()) {
        PII const now = q.front();
        q.pop();
        int const x = now.first;
        int const y = now.second;

        for (int i = 0; i < 4; i++) {
            int const xx = x + dx[i];
            int const yy = y + dy[i];

            if (xx < 1 || xx > n || yy < 1 || yy > m || g[xx][yy] == 1) continue;

            if (step[x][y] < step[xx][yy] + 1) {
                q.emplace(xx, yy);
                step[xx][yy] = step[x][y] + 1;
            }
        }
    }
}

int ans[200];
string direction = "DLRU";

void DFS(int cur, int x, int y) {
    if (x == n && y == m) {
        for (int i = 0; i < cur; i++)
            cout << direction[ans[i]];
        exit(0);
    }

    // cout << x << ' ' << y << '\n';

    for (int i = 0; i < 4; i++)
        if (cur + 1 == step[x + dx[i]][y + dy[i]])
            ans[cur] = i, DFS(cur + 1, x + dx[i], y + dy[i]);
}

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }

    memset(&step, INF, sizeof step);
    BFS();

    DFS(0, 1, 1);
    return -1;
}


// https://www.lanqiao.cn/problems/602/learning/


/// 二刷，BFS加DFS回溯
/*
#include <bits/stdc++.h>
using namespace std;

*
 * BFS最短路走迷宫
 * 先由BFS找到出口，并记录上一个点
 * 再从终点DFS依次回溯，找到路线
 * *

const int N = 60, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
struct Node{
    int step;// 走到这个点的最小时间
    PII last;// 从那个点走到这个点的
}node[N][N];

const int n = 30, m = 50;
char s[N][N];
const int dy[4] = {0, -1, 1, 0};// 对应字典序D,L,R,U，右为y轴，下为x轴
const int dx[4] = {1, 0, 0, -1};

/// 初始化距离为最大值
void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            node[i][j].step = INF;
}

/// BFS上标记
void BFS()
{
    queue<PII> q;
    q.emplace(1, 1);
    node[1][1].step = 0;

    while (!q.empty())
    {
        int const xx = q.front().first;
        int const yy = q.front().second;
        q.pop();// 没有弹出队头卡了好久=.=

        for (int i = 0; i < 4; i++)
        {
            int const x = xx + dx[i];
            int const y = yy + dy[i];

            if (x < 1 || x > n || y < 1 || y > m) continue;

            if (node[x][y].step > node[xx][yy].step + 1 && s[x][y] == '0')
            {
                node[x][y].step = node[xx][yy].step + 1;
                node[x][y].last = {xx, yy};
                q.emplace(x, y);
            }
        }
    }
}

/// DFS找路径
void findWayBack(int x, int y)
{
    if (x == 1 && y == 1) return ;

    // 先找到底再进行回溯
    findWayBack(node[x][y].last.first, node[x][y].last.second);

    // 对应四个方向
    int const xx = node[x][y].last.first - x;
    int const yy = node[x][y].last.second - y;
    if (xx == 1 && yy == 0) putchar('U');
    if (xx == 0 && yy == 1) putchar('L');
    if (xx == -1 && yy == 0) putchar('D');
    if (xx == 0 && yy == -1) putchar('R');
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    init();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            s[i][j] = c;
        }

    //debug
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << s[i][j];
        cout << endl;
    }*/

    BFS();

    //cout << node[n][m].step << '\n';

    findWayBack(n, m);

    // debug
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++)
//            cout << node[i][j].step << ' ';
//        cout << endl;
//    }
//
//    return 0;
}*/