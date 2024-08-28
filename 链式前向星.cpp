#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
  链式前向星, 本质就是一个(群)指针模拟的链表

  head[i]表示以点i为起点的所有边(的头节点的位置)(本质就是链表)
  然后由头节点拉出一条链表, 链表上的每个节点都是以i为起点的一条边

  对于这样一个例子 1->2(w=1), 2->3(w=1), 3->1(w=3)
  画图类似于:
    head [to w next]
    1     2  1  -1
    2     3  1  -1
    3     1  3  -1
    4                   (指向空边, 也就是-1)
  如果添加一条路, 1->4(w=2)
  上图就会变成:
    head [to w next] [to w next]
    1     4  2  ->   2  1  -1
    2     3  1  -1
    3     1  3  -1
    4                   (指向空边, 也就是-1)
  这样, 如果想要遍历1的所有边, 直接遍历head[1]所在的链表即可
*/

const int N = 1.5e5 + 10;
/// 链式前向星
struct Edge {
    int to;           // 指向的点
    int w;            // 权值
    int next = -1;    // 当前边的下一条边(是指针), 如果是数组next会和stl重名
} edge[N];
int head[N];    // head[i]表示i号节点的第一条边的位置
int tot = 1;    // tot表示最新的空节点所在的位置

// 链式前向星的加边函数
void add(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].w = w;
    // 不是在最后插入, 而是在最最前面插入新边(头插法)
    edge[tot].next = head[u];    // 下一个数设为原本的头节点
    head[u] = tot++;             // 头节点设为新边
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) head[i] = -1;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    vector<int> dist(n + 1, 1e9);
    vector<bool> vis(n + 1, false);
    dist[1] = 0;
    auto dijkstra = [&]() {    // 堆优dijkstra
        priority_queue<pii> pq;
        pq.push({0, 1});
        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            if (vis[u]) continue;
            vis[u] = true;

            // 遍历这个点的边
            for (int i = head[u]; ~i; i = edge[i].next) {    // -1的二进制全是1
                int v = edge[i].to;
                int w = edge[i].w;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }

        if (dist[n] == 1e9) return -1;
        return dist[n];
    };

    cout << dijkstra() << '\n';
    // for (auto i : dist) cout << i << ' ';
    return 0;
}


// https://www.acwing.com/problem/content/description/852/
// 2024年3月28日