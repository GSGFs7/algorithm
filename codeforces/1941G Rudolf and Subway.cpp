#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <set>
#include <map>

using namespace std;
#define int long long

typedef pair<int, int> pii;

/// div3的G题, 类板子题
/*
 * 题目描述:
 *  给出一个n个点的无向图, 边带有颜色, 同颜色的边权重为0, 不同为1, 求最小花费
 *
 * 思路:
 *  稍有变化的BFS
 *  因为同一个颜色间不花费权重, 在BFS取到下一个点的时候直接把整条相同颜色的路径更新同一个花费, 并加入队尾
 *  从起点0开始向外扩散每扩散一次就会增加1, 因为整条路径的同时操作, 不会出现走迷宫被其他点更新的情况
 *  直接暴力跑一遍就会依次得到每条路上的花费
 *  就是解题方法比较难想, 而且代码也难调
 * */

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> edge[n];// 要开大点, why?
    map<int, set<int> > set;// 单走一个set会炸, 颜色的范围超过了n
    for (int i = 0, u, v, c; i < m; i++) {
        cin >> u >> v >> c;
        u --, v --;
        edge[u].push_back({v, c});// 存边
        edge[v].push_back({u, c});
        set[c].insert(u);// 存颜色
        set[c].insert(v);
    }

    int start, end;// 起点与终点
    cin >> start >> end;
    start --, end --;
    map<int, bool> vis;// 是否造访过这个颜色
    vector<int> cost(n, -1);// 到每个点的最小花费
    queue<int> q;
    q.emplace(start);// 注意这个emplace, 如果出错编译器找不到
    cost[start] = 0;// 初始化, 同一条线上的也需要+1, 也就是说全图只有这一个0
    // vis[start] = true; 这样会出事, 也就是说这条路上的其他点不会被更新
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto [v, c] : edge[now]) {// 可以抵达的下一个点
            if (vis[c]) continue;// 如果这个颜色没有到过(也就是没有更新过这整条路径)
            vis[c] = true;

            for (auto i : set[c]) {// 更新抵达的下一个点的颜色(整条路径)
                if (cost[i] != -1) continue;

                cost[i] = cost[now] + 1;
                q.push(i);
            }
        }
    }

    cout << cost[end] << '\n';
}

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
    cin >> t;
    while (t--)
        solve();
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//    cout << duration.count();
    return 0;
}


// https://codeforces.com/contest/1941/problem/G