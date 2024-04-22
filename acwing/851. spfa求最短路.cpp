#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
  SPFA，队列优化版的bellman-fold算法

  基于bellman-fold算法的思路，每次扩散就会确定一个点的最短路，跑n次就能得到全部的最短路
  类似堆优dijkstra，只不过不能将重复的点再次加入队列
  最好情况根dijkstra差不多，但是最坏情况会被卡到O(nm)
  但是可以判负环
*/

struct Edge {
    int v, w, next;
};

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
Edge edge[N];
int head[N];
int cnt = 1; 

// 前向星
void add(int u, int v, int w) {
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt ++;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) head[i] = -1;  // 不要把这个放后面！！
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    vector<bool> vis(n + 1, false);
    vector<int> dis(n + 1, INF);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        // 带重点判断的dijkstra？
        vis[u] = false;

        for (int i = head[u]; ~i; i = edge[i].next){
            int v = edge[i].v;
            if (dis[v] > dis[u] + edge[i].w) {
                dis[v] = dis[u] + edge[i].w;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    if (dis[n] > INF / 2) cout << "impossible\n";
    else cout << dis[n] << '\n';
} 

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://www.acwing.com/problem/content/description/853/
// 2024年4月2日