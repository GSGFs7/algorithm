#include <bits/stdc++.h>
using namespace std;

/*
 * BFS+双端队列
 * P4667 [BalticOI 2011 Day1] Switch the Lamp On
 * 这题边权只有0和1两种
 * 可以理解为优先级
 * 可以使用双端队列求解
 * 将所有边权为0的点从队头加入，边权为1的点从队尾加入
 * 看队列的翻转次数就可以得到答案
 *
 * 为什么这个方法可以球得最小值？
 *  边权为0的点从队头加入，边权为1的点从队尾加入，从队头取出点，每次取到权值为1的点时从这个点往后的点都需要加上1
 * 为什么不用判重？
 *  如果队列后面权值为1的点被跟新的话，距离必然会小于INF，如果从队列中取出这个值时走到这个点的距离更小就沿这条路继续更新其他点，反之亦然
 * 如何保证所得的结果最小？
 *  利用BFS的方法，所有能够到达的点都会被DFS遍历，多次遍历时记录最小值
 * */

const int dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};// 四个方向
const int ab[4] = {2, 1, 1, 2};     // 四个元件期望方向
// 四个编号的位移，由四个方向得到，用于判断到达这个点是否需要转向
const int cd[4][2] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}};
int graph[505][505], dis[505][505]; // 图和距离，距离表示翻转次数
struct P { int x, y, dis; };        // 双端队列的节点

/// 读入
int readChar()
{
    char c;
    while ((c = getchar()) != '/' && c != '\\');    // 注意转义符
    return c == '/' ? 1 : 2;
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    memset(&dis, 0x3f, sizeof dis);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            graph[i][j] = readChar();

    deque<P>dq;
    dq.push_back((P){1, 1, 0});
    dis[1][1] = 0;

    while (!dq.empty())
    {
        // 队头
        auto u = dq.front();
        dq.pop_front();

        for (int i = 0; i <= 3; i++)
        {
            // 下一个点的坐标
            int const nx = u.x + dir[i][0];
            int const ny = u.y + dir[i][1];

            // 下一个点的状态，是否需要转向
            int const d = graph[u.x + cd[i][0]][u.y + cd[i][1]] != ab[i];           // 如果方向不相等，标记d=1

            if (nx && ny && nx < n + 2 && ny < m + 2)                               // 防止越界
            {
                if (dis[nx][ny] <= dis[u.x][u.y] + d) continue;                     // 保证最短路

                dis[nx][ny] = dis[u.x][u.y] + d;                                    // 如果转向就加1
                if (d == 0) dq.push_front((P){nx, ny, dis[nx][ny]});    // 边权为0，插入队头
                else dq.push_back((P){nx, ny, dis[nx][ny]});            // 边权为1，插入队尾
            }
        }
    }

    if (dis[n + 1][m + 1] != 0x3f3f3f3f) cout << dis[n + 1][m + 1];
    else cout << "NO SOLUTION";
    return 0;
}


// https://www.luogu.com.cn/problem/P4667