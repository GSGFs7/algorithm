#include <cstring>
#include <iostream>
#include <queue>

/*
  网络流
    最大流 EK算法

  概念:
    网路, 一个有向图G=(V,E), 有两个特殊的节点: 起点S和汇点T.
    每条边都有一个权值c(x,y), 称为边的容量.
    用f(x,y)表示边(x,y)上的流量, c(x,y)-f(x,y)表示边的剩余流量
  可行流应当满足:
    1.容量限制: f(x,y)<=c(x,y)
    2.流量守恒: ∑f(u,x)=∑f(x,v), x!=S, x!=T  (∑f(S,v)称为整个网路的流量)
  最大流: 从源点流向汇点的最大流量
  增广路: 一条从源点到汇点的所有边的剩余容量>=0的路径
  残留网: 由网路中所有节点和剩余容量大于0的边构成的子图(包括有向边和其反向边)
    关于残留网, 对于每条有向边(x,y)都构建一条反向边(y,x), 初始容量c(y,x)=0.
    构建反向边的目的是提供一个"退流管道", 一旦前面的增广路堵死可行流,
    可以通过"退流管道"退流, 让可行流通过, 提供一种后悔机制

  求最大流:
    显然, 增广路可以给汇点贡献流量, 并且在一条路径扣除增广路后S和T就不再连接
    最大流问题就可以转换为求增广路的问题
    但是, 所有的增广路相加未必就是最大流, 可以通过添加反边的方法来进行补救
    反向边的初始值设为0, 当正向边有流量流过, 给反向边也加上对应的流量上限
    使其可以反向流动, 最大化利用这条路的流量上限, 这样得到的就是最大流了
    所以最大流问题就转换为如何又快又好地寻找增广路

  EK算法:
    利用BFS来寻找每次的最短路, 这样进行增广路的寻找较为高效(与用DFS的ford-fulkerson相比)
    在BFS时记录这个点的前向边是谁, 每次BFS完成后根据前向边来反序修改权值, 直到不能BFS为止
    在修改权值时, 将减去的那部分权值加到对应的反向边上, 让BFS可以沿这条边反向搜索

  复杂度:O(nm^2)
*/

using namespace std;
#define int long long

const int N = 210, M = 1e5 + 10;
int n, m, S, T;

// 前向星
struct Edge {
    int to, next, weight;
} edge[M];
int head[M];
int cnt = 1;    // 下标的记录从2开始, 这样异或上1就可以得到他的反向边

void add(int u, int v, int w) {
    edge[++cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].weight = w;
    head[u] = cnt;
}

int mf[M];     // mf[v]表示从S到v的路径流量上限
int pre[M];    // pre[v]表示v的前驱边

// 找增广路
bool bfs() {
    memset(&mf, 0, sizeof mf);

    queue<int> q;
    q.push(S);
    mf[S] = 1e9;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            int w = edge[i].weight;

            if (mf[v] == 0 && w) {
                mf[v] = min(mf[u], w);    // 能流到这的只能是最小的那个
                pre[v] = i;               // 前驱边
                q.push(v);
                if (v == T) return true;
            }
        }
    }

    return false;
}

// 累加可行流
int EK() {
    int flow = 0;
    while (bfs()) {
        int v = T;
        while (v != S) {    // 更新残留网
            int i = pre[v];
            edge[i].weight -= mf[T];
            edge[i ^ 1].weight += mf[T];
            v = edge[i ^ 1].to;
        }
        flow += mf[T];
    }
    return flow;
}

int flag[N][N];    // 重边
void solve() {
    cin >> n >> m >> S >> T;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (flag[u][v] == 0) {
            add(u, v, w);
            add(v, u, 0);
            flag[u][v] = cnt;
        } else {
            edge[flag[u][v] - 1].weight += w;
        }
    }

    cout << EK() << '\n';
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


// https://www.luogu.com.cn/problem/P3376
// 2024年4月10日