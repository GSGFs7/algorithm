#include <bits/stdc++.h>
using namespace std;

/*
 * dijkstra算法
 * BFS+优先队列
 *
 * 逐层扩展当前点的邻居，每次扩展后都更新一遍邻居的路程
 * 取最短的那个点，这个点必定是最短的（可以证明，能短距离直达为何还要绕圈子？）
 * 然后再用这个点更新其他点
 *
 * 一句话总结：保持最新并取最短
 * */

const long long INF = 0x3f3f3f3f3f3f3f3fLL; // 数据较大
const int N = 1e5 + 10;

struct edge {       // 存边
    int from, to;   // 起点和终点
    long long w;    // 距离，权值
    edge(int a, int b, long long c) {from = a, to = b, w = c;}  // 构造函数
};
vector<edge> e[N];  // 存图

typedef struct Node {   // 图上的每一个节点
    int id;             // 节点
    long long n_dis;    // 到这个节点的距离
    Node(int a, long long b) {id = a, n_dis = b;}
    bool operator < (const Node & a) const { return n_dis > a.n_dis; }  // 重载操作符
}node;

int n, m;
int pre[N];         // 记录前驱节点
long long dis[N];   // 所有节点到起点的距离
bool done[N];       // 看是否已经找到了最短距离

/// 打印路径
void print_path(int s, int t)
{
    if (s == t) { cout << s << ' '; return ; }
    print_path(s, pre[t]);
    cout << t << ' ';
}

void dijkstra()
{
    int const s = 1;
    for (int i = 1; i <= n; i++) dis[i] = INF, done[i] = false; // 初始化
    dis[s] = 0;
    priority_queue<Node> q;         // 核心操作，在加入的点中取最小值
    q.emplace(s, dis[s]);

    while (!q.empty())
    {
        node const u = q.top();
        q.pop();

        if (done[u.id]) continue;   // 如果已经找到了这个点的最小值
        done[u.id] = true;          // 现在就开始找这个点的最小值

        int const len = e[u.id].size();
        for (int i = 0; i < len; i++)   // 检查节点u的所有邻居
        {
            edge const y = e[u.id][i];  // u的第i个邻居，从u开始走到下一个点
            if (done[y.to]) continue;   // 如果这个点被找过

            if (dis[y.to] > y.w + u.n_dis)  // 最短路算法，下一个点取最小值，更新接下来的数的操作
            {
                dis[y.to] = y.w + u.n_dis;  // 计算距离
                q.emplace(y.to, dis[y.to]);
                pre[y.to] = u.id;           // 记录路径
            }
        }
    }
    // print_path(s, n);   // 打印路径，如果需要的话
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) e[i].clear();

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(u, v, w); // 单向边，只要录一遍即可
    }

    dijkstra();

    for (int i = 1; i <= n; i++)
    {
        if (dis[i] >= INF) cout << "-1 ";
        else cout << dis[i] << ' ';
    }
    return 0;
}


// https://www.lanqiao.cn/problems/1122/learning