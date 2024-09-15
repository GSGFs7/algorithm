#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
// #define int long long

/*
 给出两块连通块, 求连通这两个连通块的最小花费

 思路:
    很简单的BFS
    先随便选中一个连通块, 然后标记连通块中的所有点
    标记完成后开始进行BFS, 每扩散一个点直接cost+1
    看最后接触到的第一个没有标记的另一个连通块的cost值
*/ 

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int N = 60;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char a[N][N];
bool vis[N][N];
int cost1[N][N];

void debug() {
#ifdef __LOCAL__
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << cost1[i][j] << '\t';
        }
        cout << '\n';
    }
#endif
}

void BFS() {
    queue<pii> q1;// 标记当前连通块所有点
    queue<piii> q;// 扩散搜索另一个连通块
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'X') {
                q1.push({i, j});
                q.push({i, {j, 0}});// 一定要加, 如果连通块只有一个点的话会出0
                vis[i][j] = true;
                break;
            }
        }
        if (!q1.empty()) break;
    }

    // 标记当前连通块内所有的点
    while (!q1.empty()) {
        int x = q1.front().first;
        int y = q1.front().second;
        q1.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (vis[xx][yy]) continue;

            if (a[xx][yy] == 'X') {
                q1.push({xx, yy});
                vis[xx][yy] = true;
                q.push({xx, {yy, 0}});// 顺带也加入到BFS搜索的队列里
            }
        }
    }    

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (vis[xx][yy]) continue;
            if (xx == 0 || xx == n + 1) continue;
            if (yy == 0 || yy == m + 1) continue;

            if (a[xx][yy] == 'X') cout << cost << '\n', debug(), exit(0);
            else {
                q.push({xx, {yy, cost + 1}});
                vis[xx][yy] = true;// 竟然能忘记加这个..
                // debug
                cost1[xx][yy] = cost + 1;
            }
        }
    }
}

void solve() {
    memset(&vis, false, sizeof vis);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> a[i][j];

    BFS();

    cout << 0 << '\n';// 如果没有找到结果
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}


// https://www.acwing.com/problem/content/2062/
// 2024年3月21日