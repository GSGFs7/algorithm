#include <bits/stdc++.h>

using namespace std;

// 优先队列
// 不是前缀和之和(虽然也能过)

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(-x);
    }

    int ans = 0;
    while (pq.size() > 1) {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();
        ans -= a + b;
        pq.push((a + b));
    }
    cout << ans << '\n';
    return 0;
}


// https://www.lanqiao.cn/problems/545/learning/
// 2024年4月8日