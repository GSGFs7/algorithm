#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  二分求最长上升子序列
  时间复杂度 O(nlogn)
  使用DP的方法找最长上升子序列复杂度略高 (O(n^2))
  DP法找最长上升子序列需要一个一个的向前找每个数经行比较
  会在重复的地方浪费大量的时间, 使用二分维护一个
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 二分求最长上升子序列
    /**********************************************************/
    vector<int> used(n + 1);    // 需要加一不然会出问题
    int length = 0;
    auto findAndIns = [&](int x) {
        if (x <= used[1]) return;

        int l = 0, r = length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] > x)
                r = mid;
            else
                l = mid + 1;
        }

        if (l == length) {
            length++;
            used[length] = x;
        }
    };
    /**********************************************************/

    for (int i = 0; i < n; i++) findAndIns(a[i]);
    int ans = length;

    length = 0;
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) used[i] = 0;
    for (int i = 0; i < n; i++) findAndIns(a[i]);
    cout << min(length, ans) << '\n';
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


// 2024年5月28日