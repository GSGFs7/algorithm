#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

/*
 * 设定空集合C
 * 依次加入新的点
 * 优先处理较小边
 * 再加入新的连向其他点的点
 * 处理完该点所有边
 * 保证每边边长最小
 * 如果没有新边加入算法结束
 * */

struct Node
{
    int y, v;
    Node(int _y, int _v) : y(_y), v(_v){}// 构造函数赋值
};

const int N = 1e4 + 10;
vector<Node> edge[N + 1];
int n, m, dist[N + 1];
bool b[N + 1];

void dijkstra(int s, int t)// 以s为起点
{
    memset(b, false, sizeof b);// 开始时所有元素都不在集合c中
    memset(dist, 127, sizeof dist);
    dist[s] = 0;

    while (true)
    {
        int x = -1;// 没有值时
        for (int i = 1; i <= n; i++)
            if (!b[i] && dist[i] < 1 << 30)// 如果未确定最小，并且存在一条边
                if (x == -1 || dist[i] < dist[x])// 没有时加人一个数，存在时取较小值
                    x = i;

        if (x == t || x == -1)// 取到终点 或者 没有新点加入时循环结束
            break;
        b[x] = true;// 确定这个值

        for (auto i : edge[x])// 更新其他未确定点
            dist[i.y] = min(dist[i.y], dist[x] + i.y);
    }
    if (dist[t] < 1 << 30) cout << dist[t] << endl;
    else cout << -1 << endl;
}

int main()
{
    int k;// 询问次数
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edge[x].emplace_back(y, z);
    }
    for (int i = 0; i < n; i++)
    {
        int s, t;
        cin >> s >> t;
        dijkstra(s, t);
    }
    return 0;
}