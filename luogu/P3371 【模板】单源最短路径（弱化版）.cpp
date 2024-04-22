#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define int long long

// 链式前向星
struct Edge {
    int to;
    int w;
    int next;
};

const int N = 1e4 + 10;
const int M = 5e5 + 10;
const int INF = 2147483647;
Edge edge[M];
int head[N];
int tot = 1;

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // 链式前向星的加边
    auto add = [&](int u, int v, int w) {
        edge[tot].to = v;
        edge[tot].w = w;
        edge[tot].next = head[u];
        head[u] = tot++;
    };

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    // spfa, 类似于dijkstra
    vector<int> dist(n + 1, INF);
    auto spfa = [&]() {
        vector<int> vis(n + 1, false);
        dist[k] = 0;
        queue<int> q;
        q.push(k);
        vis[k] = true;    // 与dijkstra唯一的区别就是不能走负环

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            vis[u] = false;

            for (int i = head[u]; i; i = edge[i].next) {
                int v = edge[i].to;

                if (dist[v] > dist[u] + edge[i].w) {
                    dist[v] = dist[u] + edge[i].w;
                    // 每次添加都需要看是否在队列里, 不在才能加
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    };

    spfa();

    cout << dist[n] << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P3371
// 2024年3月28日