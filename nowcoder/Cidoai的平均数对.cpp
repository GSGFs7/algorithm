#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
  给出n对数(a,b)和k，选出几对数，在满足b的平均值不超过k的同时a的和最大，求这个最大的a

  因为是要求b的平均数，也就是说如果一个b没有超过k，那么就可以多出来k-b的背包空间
  换句话说就是所有不超过k的b都会贡献a，并且还会增加背包空间，所以所有的小于k的b都应该选上
  （简单说就是往里面加小的数，拉低大的数）
  那么超过k的就相应的会占用k-b的背包空间，然后直接进行01背包即可
*/

const int N = 1e6 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int V = 0;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (y <= k) {
            V += k - y;
            sum += x;
        } else {
            a.push_back({x, y - k});
        }
    }

    vector<int> dp(V + 1);
    for (auto [v, w] : a) {
        for (int i = V; i >= w; i--) {
            dp[i] = max(dp[i], dp[i - w] + v);
        }
    }
    cout << dp[V] + sum << '\n';
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


// https://ac.nowcoder.com/acm/contest/88880/B
// 2024-09-13