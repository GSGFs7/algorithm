#include <iostream>
#include <vector>

using namespace std;

/*
  bellman_fold算法
    直接暴力扩散最短路, 因为直接控制扩散的次数可以精确求出经过k条边的最短路
    同时, 可以通过这个可以可控的特性可以判断负环(再跑一遍, 如果数值变小了就说明存在负环)
*/

struct Edge {
    int u, v, w;
};

const int N = 510;
const int M = 1e4 + 10;
Edge edge[M];

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {u, v, w};
    }

    vector<int> dist(n + 1, 1e9);
    dist[1] = 0;

    // bellman_fold算法, 暴力经行k遍扩撒, 如果不是从起点开始的扩散就不会有任何效果
    // 也就是说, 跑k遍就是算上k条边的最短路
    auto bellman_fold = [&]() {
        vector<int> last;
        for (int i = 0; i < k; i++) {
            last = dist;                     // 存上次的数, 避免相互干扰
            for (int j = 0; j < m; j++) {    // m条边, 每条边都扩散一次
                auto e = edge[j];
                dist[e.v] = min(dist[e.v], last[e.u] + e.w);    // 扩散
            }
        }
    };

    bellman_fold();

    if (dist[n] > 1e9 / 2)    // 可能受到负边权影响, 比最大值少一点
        cout << "impossible" << '\n';
    else
        cout << dist[n];

    // for (auto i : dist) cout << i << '\t';
    return 0;
}


// https://www.acwing.com/problem/content/description/855/
// 2024年3月28日