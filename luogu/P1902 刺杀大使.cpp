#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;

/*
 * 寻找一条路径，使该路径的最大值最小
 * 二分枚举答案
 * 然后通过BFS控制二分
 * 最后得出的答案即为最小值
 * */

const int N = 1010, INF = 0x3f3f3f3f;
int a[N][N];
int n, m;
bool vis[N][N];
int dx[4] = {0, 1, 0, -1};// 向四个方向搜索
int dy[4] = {1, 0, -1, 0};

/// bfs广搜
bool bfs(int mid)
{
    queue<pair<int, int>> q;// 队列存储所有可能的点
    memset(&vis, false, sizeof vis);// 重置
    q.emplace(1, 1);// 起点
    while (!q.empty())
    {
        // 以这个点为起点开始搜索
        int const xx = q.front().first;
        int const yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int const nx = xx + dx[i];
            int const ny = yy + dy[i];
            // 如果不满足条件直接退出
            if (nx <= 0 || nx > n || ny <= 0 || ny > m || vis[nx][ny] || a[nx][ny] > mid)
                continue;
            if (nx == n) return true;// 如果找到最后就返回true
            vis[nx][ny] = true;
            q.emplace(nx, ny);// 如果符合条件直接加入到队列
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int ms = INF, mx = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], ms = min(ms, a[i][j]), mx = max(mx, a[i][j]);// 记录答案范围，直接0~INF会TLE

    /// 二分查找答案
    int l = ms, r = mx;
    while (l < r)
    {
        int const mid = (l + r) >> 1;// mid表示可接受的最大伤害
        if (bfs(mid)) r = mid;// ans记录最终答案
        else l = mid + 1;
    }
    cout << r << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1902