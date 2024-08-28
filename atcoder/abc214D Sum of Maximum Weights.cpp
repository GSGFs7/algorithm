#include <chrono>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;
#define int long long

void solve();

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}

/*****************************************************************************/

/*
  给出一个图, 求每两个点间的最大权值的边相加的结果

  思路:
    对于最大的那条边, 通过这条边的数量是两边连通块大小的积
    对于次大边, 通过这条边的数量是删掉最大边后两边连通块数量积
    对于连通块而言, 拆边比较麻烦
    直接倒着, 从小的一直合并到大的
    突然就觉得自己很蠢...
*/

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

void debug() {
#ifdef __LOCAL__
#endif
}

/**
 * @brief 代码写这里!!!
 */
void solve() {
    int n;
    cin >> n;
    priority_queue<piii> pq;    // 小根堆
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({-w, {u, v}});
    }

    vector<int> size1(n + 1, 1);      // 连通块的大小, 只有祖宗节点有意义
    vector<int> f(n + 1);             // 祖宗节点
    iota(++f.begin(), f.end(), 1);    // 初始化祖宗节点

    // 要用 function 才能递归, lambda不行
    function<int(int)> find = [&](int x) {    // 并查集寻找祖先
        if (f[x] != x) f[x] = find(f[x]);
        return f[x];
    };

    int ans = 0;
    while (!pq.empty()) {
        auto w = pq.top().first;
        auto u = pq.top().second.first;
        auto v = pq.top().second.second;
        pq.pop();

        ans += size1[find(u)] * size1[find(v)] * w;    // 边两边的连通块的积

        // 合并两个连通块
        size1[find(u)] += size1[find(v)];
        f[find(v)] = find(u);
    }

    cout << -ans << '\n';
}


// https://atcoder.jp/contests/abc214/tasks/abc214_d
// 2024年3月26日