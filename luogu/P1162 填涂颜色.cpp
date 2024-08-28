#include <iostream>
#include <queue>
using namespace std;

// bfs宽搜，标记边界，未被标记的就是2

const int N = 35;
int a[N][N];
bool vis[N][N];// 记录是否为边界点
int n;
queue<int> q;

void bfs(int x, int y)
{
    vis[x][y] = true;// 将当前位置标记为边界
    q.push(x);
    q.push(y);

    // 向周围搜索，用队列代替递归，有效防止死循环
    while (!q.empty())
    {
        int e = q.front();
        q.pop();
        int f = q.front();
        q.pop();

        // 向四周搜索并标记为边界，设定界限，防止越界
        if (!a[e][f-1] && !vis[e][f-1] && f != 1) vis[e][f-1] = true, q.push(e), q.push(f-1);
        if (!a[e-1][f] && !vis[e-1][f] && e != 1) vis[e-1][f] = true, q.push(e-1), q.push(f);
        if (!a[e][f+1] && !vis[e][f+1] && f != n) vis[e][f+1] = true, q.push(e), q.push(f+1);
        if (!a[e+1][f] && !vis[e+1][f] && e != n) vis[e+1][f] = true, q.push(e+1), q.push(f);
    }
}

int main()
{
    cin >> n;
    /// 读图
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j]) vis[i][j] = true;// 同时也视为边界
        }

    // puts("");
    /// 枚举上下边界
    for (int i = 1; i <= n; i += n - 1)// 枚举完一边后直接跳到对面
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j]) continue;
            bfs(i, j);// 找到未被标记的边界点
        }

    /// 枚举左右边界
    for (int i = 1; i <= n; i += n - 1)
        for (int j = 1; j <= n; j++)
        {
            if (vis[j][i]) continue;
            bfs(j, i);
        }

    /// 输出
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j]) cout << a[i][j] << ' ';
            else cout << 2 << ' ';// 非边界点都输出为2
        }
        puts("");
    }

    return 0;
}


// https://www.luogu.com.cn/problem/P1162