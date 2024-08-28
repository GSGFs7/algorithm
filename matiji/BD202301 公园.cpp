#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
  两个人分别从两个点出发到n点, a一个人走到下一个点的时间的x, b一个人的时间是y,
  两个人一起的时间是z, 求两个人到n点的最小花费

  思路:
    暴力BFS
    先分别处理两个人单独的BFS最小花费
    再对两个人每个点的分别花费求和后作为一个新图, 在新图上最每个点更新最短路
    最后的结果就是两人的最小花费
*/

#define int long long
typedef pair<int, int> pii;
const int N = 4e4 + 10;
vector<int> g[N];
int d[3][N];    // 分别表示a, b和c到每个点的花费
int f[N];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve() {
    memset(&d, 0x3f, sizeof d);

    int s1, s2, s3;
    int start1, start2;
    int n, m;
    cin >> s1 >> s2 >> s3;
    s3 = s1 + s2 - s3;    // s3就表示两个一起的花费
    cin >> start1 >> start2 >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i;    // 并查集初始化
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        f[find(u)] = find(v);
    }

    // int cnt = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (f[i] == i) cnt++;
    //     if (cnt == 2) return cout << -1 << '\n', void();
    // }
    // 需要写成下面这样, 中间有点没有连通也是没有关系的
    if (find(start1) != find(start2) || find(start1) != find(n)) {
        return cout << -1 << '\n', void();
    }

    // 更新最短路
    auto bfs = [&](int start, int cost, int id) {
        priority_queue<pii> pq;
        pq.push({0, start});
        d[id][start] = 0;

        if (id == 2) {    // 合并花费后再来更新最短路
            for (int i = 1; i <= n; i++) {
                d[2][i] = d[0][i] + d[1][i];
                pq.push({-d[2][i], i});
            }
        }

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto v : g[u]) {
                if (d[id][v] > d[id][u] + cost) {
                    d[id][v] = d[id][u] + cost;
                    pq.push({-d[id][v], v});
                }
            }
        }
    };

    // 更新最短路
    bfs(start1, s1, 0);
    bfs(start2, s2, 1);
    bfs(0, s3, 2);

    if (d[2][n] == 0x3f3f3f3f3f3f3f3f) return cout << -1 << '\n', void();
    cout << d[2][n] << '\n';
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


// https://www.matiji.net/exam/brushquestion/1/4347/179CE77A7B772D15A8C00DD8198AAC74