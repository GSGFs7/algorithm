#include <cstring>
#include <iostream>
#include <queue>

/*
  最大流 Dinic算法
    一次可以累加多条增广路的流量
    Dinic算法是对EK算法的进一步改进, EK算法每次都会大费周章的把一个点所有的后代都入队
    在找到汇点后又立马返回, 在返回的时候可能还存在其他增广路通向汇点
    dinic算法的一个重要优化就是找到汇点后不立刻返回, 而是继续找其他的增广路
    也就是尽量减少BFS的次数

  实现:
    dinic算法为了保证所找到的增广路是最短的, 需要用BFS把所有点按照到源点的距离分层
    然后用dfs跑图, 跑图时只允许走深度更深的点, 复杂度是O(EV^2)
    但是, 单纯的DFS肯定是错误的, 因为同层边和高层的边是无法访问的, 需要再次BFS重新建图

  优化:
    1.搜索顺序优化(分层限制搜索深度)
    2.当前弧优化(剪枝)
    3.剩余流量优化(剪枝)
    4.残枝优化(剪枝)
    (前两个优化力度很大, dinic的核心操作, 此外还有迭代加深,双向广搜,估价函数)

  解释一下当前弧优化,
    当前弧优化每次进入一个点后记录下这个点, 下次在BFS分层的时候就不需要在访问这个点了
    因为DFS进入这个点后, 就说明前面的点(同起点,不同终点)已经被榨干了, 再搜索这些点没有意义
    下次访问从u出发的边的时候直接跳过前面的(在重新进入起点时有效)
    妙啊~

  复杂度估计: dinic: O(mn^2)   BFS:O(n) bfs的次数最多:O(n) DFS:O(m) 
            EK: O(nm^2)
*/

using namespace std;
#define int long long

const int N = 210, M = 1e5 + 10;
int n, m, S, T;

struct Edge {
    int to, next, weight;
} edge[M];
int head[M];
int cnt = 1;    // 从2,3开始

void add(int u, int v, int w) {
    edge[++cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].weight = w;
    head[u] = cnt;
}

int d[M];      // d[u]表示点u所在的图层, 深度
int cur[M];    // cur[u]存u点的当前出边

bool bfs() {    // 对点分层, 找增广路
    memset(&d, 0, sizeof d);

    queue<int> q;// 队列
    q.push(S);
    d[S] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].weight;
            if (d[v] == 0 && w) {
                d[v] = d[u] + 1;
                q.push(v);
                if (v == T) return true;
            }
        }
    }

    return false;
}

int dfs(int u, int mf) {    // 多路增广
    if (u == T) return mf;

    int sum = 0;    // 流量之和
    for (int i = cur[u]; i; i = edge[i].next) {
        cur[u] = i;    // 当前弧优化, 记录当前走的是哪条边
        int v = edge[i].to;
        int w = edge[i].weight;

        if (d[v] == d[u] + 1 && w) {       // 走入下一层
            int f = dfs(v, min(mf, w));    // 只能走最小值

            edge[i].weight -= f;
            edge[i ^ 1].weight += f;    // 更新残留网
            sum += f;                   // 累加这个点的流出流量
            mf -= f;                    // 减少剩余流量
            if (mf == 0) break;         // 余量优化
        }
    }

    if (sum == 0) d[u] = 0;    // 残枝优化, 如果走不到汇点, 踢出图层, 下次就不会访问
    return sum;
}

int dinic() {    // 累加可行流
    int flow = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof head);    // 还原cur
        flow += dfs(S, 1e9);
    }
    return flow;
}

void solve() {
    cin >> n >> m >> S >> T;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, 0);
    }

    cout << dinic() << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://www.luogu.com.cn/record/list?pid=P3376&user=915241
// EK: 366ms
// dinic: 90ms
// 2024年4月11日