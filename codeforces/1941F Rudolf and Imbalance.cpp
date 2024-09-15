#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>// iota

using namespace std;
#define int long long

/// 二分
// 求得最接近的二分中点, 取最接近的几个位置来填补间隔

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), c(k);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (auto &i : c) cin >> i;

    // 找到最大值和次大值
    int max1 = -1, max2 = -1, L, R;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > max1) {
            max2 = max1;
            max1 = a[i] - a[i - 1];
            L = a[i - 1];
            R = a[i];
        } else {
            max2 = max(max2, a[i] - a[i - 1]);
        }
    }

    // 如果最大的间隔的个数超过1个
    if (max1 == max2) return cout << max1 << '\n', void();

    // sort(b.begin(), b.end());// 对b排序好像没什么意义
    sort(c.begin(), c.end());

    int ans = max1;
    for (int i = 0; i < m; i++) {
        if (b[i] + c.front() > R) continue;// 如果加上最小的数都超过最大间隔的右边界
        if (b[i] + c.back() < L) continue;// 如果加上最大的数都无法达到最大间隔的左边界

        // 尽量找到一个中间值, 别忘了减去b[i], 再减去c.begin()获得下标
        int mid = lower_bound(c.begin(), c.end(), ((L + R) >> 1) - b[i]) - c.begin();
        // 需要手动设为longlong, 不然cf会编译报错

        for (int j = max(0LL, mid - 5); j < min(k, mid + 5); j++) {// 取附近的十个点
            ans = min(ans, max(max2, max(abs(c[j] + b[i] - L), abs(b[i] + c[j] - R))));// 最大间隔就是最后的结果
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


// https://codeforces.com/contest/1941/problem/F