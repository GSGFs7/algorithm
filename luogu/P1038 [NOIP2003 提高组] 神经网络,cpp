#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
  给出n个节点, 这个点的势为所有传入边的权值乘以传入点的势再减去这个点的阈值
  求所有的非传入点中势大于0的点

  思路:
    因为后面节点的势需要前面的点经行推导, 明显需要进行拓扑排序
    求出前面所有点的势后才可以得到后面这个点
    直接合并在拓扑排序的函数里一起处理
    难点是理解题意罢
*/

typedef pair<int, int> pii;
const int N = 110;
vector<pii> g[N];
// vector<int> a; 排序结果, 没有用
int c[N];
int u[N];
int d[N];
int n, p;

void topoSort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto [v, w] : g[u]) {
            d[v]--;
            c[v] += c[u] * w * (c[u] > 0);    // 处理v这个点的权值
            if (d[v] == 0) q.push(v);
        }
    }
}

void solve() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) cin >> c[i] >> u[i];
    for (int i = 1; i <= p; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        d[v]++;
        g[u].push_back({v, x});
    }

    // 减去阈值这个尾随的常数
    for (int i = 1; i <= n; i++) {
        if (d[i]) c[i] -= u[i];
    }

    topoSort();

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (g[i].empty() && c[i] > 0) cout << i << ' ' << c[i] << '\n', flag = false;
    }
    if (flag) cout << "NULL\n";
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


// https://www.luogu.com.cn/problem/P1038