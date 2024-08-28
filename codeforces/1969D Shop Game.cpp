#include <bits/stdc++.h>

using namespace std;

/*
  给出两个数组, 从中选择大于k个下标, 获得的价值为a[i]-b[j], 可以删掉其中k个数
  a想使结果最大, b想使结果最小, 求最后的结果
  注意!!! 下标允许不同
*/

#define int long long
typedef pair<int, int> PII;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<PII> a(n + 1);
    // 反过来, first是b, second是a
    for (int i = 1; i <= n; i++) cin >> a[i].second;    // b
    for (int i = 1; i <= n; i++) cin >> a[i].first;     // a

    // 按照b的顺序来排, 因为b想使结果最小, 那么就要选择最大的k个值
    sort(++a.begin(), a.end());

    // 最大利润前缀和
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1] + max(0LL, a[i].first - a[i].second);
    }

    // 跑每个条件下的可能最大值 (因为场面由a主导)
    int ans = 0, sum = 0;
    priority_queue<int> pq;
    for (int i = n; i > 0; i--) {
        if (pq.size() >= k) ans = max(ans, pre[i] - sum);    // 不用处理a?

        pq.push(a[i].second);
        sum += a[i].second;
        if (pq.size() > k) {    // a可以压榨b的空间, 只选择最小的b就可以了
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1969/problem/D
// 2024年5月15日