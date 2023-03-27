/*
 * 最短路
 *  一·单源最短路   求一个点到其他所有点的最小距离
 *      1.所有边权重都是正数
 *          (1).朴素Dijkstra算法   O(n^2)
 *          (2).堆优化版Dijkstra算法   O(mlogn)n为点数 m为边数
 *          (基于贪心)
 *          边数很多，稠密图，用邻接矩阵存（稀疏图可用邻接表存）
 *      2.存在负权重边
 *          (1).Bellman-Ford算法   O(nm)
 *          (2).SPFA算法(Bellman-Ford的优化版)   O(m)(一般情况) 最坏:O(nm)
 *          (基于离散化)
 *  二·多元汇最短路   不确定起点和终点
 *      Floyd算法O(n^3)
 *
 * 源点->起点
 * 汇点->终点
 *
 * 难点：建图，算法实现
 * */

// 朴素Dijkstra
// 单源最短路
/*
 * 步骤：
 *  1.初始化距离dist[1] = 0, dist[i] = 无穷大
 *  2.for i : 0 ~ n  找到不在s中距离最近的点t加入s，并用t更新其他点的距离   s:当前已经确定最短路的点
 * */
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;
int n, m;
int g[N][N];// 图
int dist[N];// 从起点到第i个点的距离
bool st[N];// 最小值是否确定

int dijkstra()
{
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        // 找到没有确定最短路那个点的最小距离
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        st[t] = true;// 确定最短路

        // 利用t重新更新数据
        for (int j = 0; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    // 存储两点间最短距离
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra();
    return 0;
}