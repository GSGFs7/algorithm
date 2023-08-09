#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 60, INF = 0x3f3f3f3f;
int g[N][N];
int step[N][N];
int n = 30, m = 50;
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