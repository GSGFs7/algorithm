#include <bits/stdc++.h>

using namespace std;

/*
 * 有n个人排成一列吃面条 在t[i]时刻会出现w[i]个面条 吃完后离开s[i]秒
 * 问最后每个人吃了多少面条
 *
 * 模拟
 * 因为队列里的人肯定都是第一个人能吃到面 使用小根堆来维护在队列中的人
 * 如果一个人吃了面离开队列 需要在回来的话也是按照时间小的顺序插入
 * 存储离开的人也需要使用小根堆
 * 因为t是1e9级 无法枚举
 * 使用t[i]与离场的最小时间进行比较 如果小于t[i]就说明这个人在面条出现之前就回来了
 * 使用两个小根堆循环模拟即可
 * 瞄啊～
 * */

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ans(n + 1, 0);

    // 队列中的人 每次操作只会影响最前面的人
    priority_queue<int> q;
    for (int i = 0; i < n; i++) q.push(-i);

    // 以时间为先后顺序维护事件 看哪些人重新回到队伍
    priority_queue<array<int, 2>> event;
    while (m--) {
        int t, w, s;
        cin >> t >> w >> s;
        // 把回来的人加入队列
        while (!event.empty() && -event.top()[0] <= t) {
            auto [_, u] = event.top();
            event.pop();
            q.push(-u);
        }

        // 吃面之后离开队列
        if (!q.empty()) {
            ans[-q.top()] += w;
            event.push({-(t + s), -q.top()});
            q.pop();
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
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


// https://atcoder.jp/contests/abc320/tasks/abc320_e
// 2024-10-24
