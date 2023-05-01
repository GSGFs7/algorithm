/*
 * 相较于Bellman-Ford算法
 * 用队列存储更新过的点
 * 只需再次循环更新过的点即可
 * 跟dijkstra很像
 * */

#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;      // 总点数
int m;
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储每个点到1号点的最短距离
bool st[N];     // 存储每个点是否在队列中

// 添加路径
void add(int a, int b, int c)// 从a到b的距离为c
{
    e[idx] = b;// 指向的边
    w[idx] = c;// 距离
    ne[idx] = h[a];//
    h[a] = idx++;
}

// 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // 如果队列中已存在j，则不需要将j重复插入
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = spfa();
    if (t == - 1) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}