#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个圆，圆上每隔a[i]段距离就有一个点，求有多少对点的距离是m的倍数
    最多有2e5个点

  数据范围过大，使用常规方法肯定行不通
  将整个圆拆开拉直，假想成一条数组，计算两个点的长度也就变成了计算两个点的前缀和之差
  也就是转化成了找 (pre[s]-pre[t]) % m == 0 的个数
  上面的式子也可以转化为 pre[s] % m == pre[t] % m
  也就是说只要找 s的前缀和模上m 与 t的前缀和模上m 相等的个数就可以了
*/

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int presum = 0;
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; i++) {
        ans += cnt[presum % m];
        cnt[presum % m]++;
        presum += a[i];
    }

    int sum = presum;
    presum = 0;
    for (int i = 0; i < n; i++) {
        cnt[presum % m]--;      // 减去会重复的
        ans += cnt[sum % m];    // 只计算顺时针方向上的结果
        sum += a[i];
        presum += a[i];
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://atcoder.jp/contests/abc367/tasks/abc367_d
// 2024-09-01