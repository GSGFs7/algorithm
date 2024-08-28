#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define int long long

/*
 * 给出n个点, 从i号到i+1号需要花费a[i]的时间, 到x[i]号需要花费b[i]的时间, 求最短的时间
 *
 * 思路:
 *  相当于每个点建两条边到其他点, 直接暴力最短路
 *  用优先队列进行辅助优化, 可以优化到62ms
 */

void debug(int x, vector<int> &cost) {
#ifdef __LOCAL__
    cout << x << '\t' << cost[x] << '\n';
#endif
}

typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> jump(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> jump[i];
    }

    // cost需要包括1~n, 并且最大值要非常大
    vector<int> cost(n + 1, 0x3f3f3f3f3f3f3f3f);
    cost[1] = 0;
    priority_queue<pii> q;    // 优先队列对花费排序, 较小的值先更新
    q.push({0, 1});           // 从1号点一直搜到n号点
    while (!q.empty()) {
        auto [co, now] = q.top();
        q.pop();

        // debug(now, cost);
        if (now == n) break;    // 如果n成为了最小值, 也就表示最后的答案无法被再次更新变小

        // 走到下一个数
        if (cost[now + 1] > cost[now] + a[now]) {
            cost[now + 1] = cost[now] + a[now];
            q.push({-cost[now + 1], now + 1});    // 对花费从小到大排序
        }

        // 跳到指定的数
        if (cost[jump[now]] > cost[now] + b[now]) {
            cost[jump[now]] = cost[now] + b[now];
            q.push({-cost[jump[now]], jump[now]});
        }

        if (now == n) debug(now, cost);
    }

    cout << cost[n];    // 到第n号点的总花费
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
    // cin >> t;
    while (t--)
        solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}


// https://atcoder.jp/contests/abc340/tasks/abc340_d
// 2024年3月21日