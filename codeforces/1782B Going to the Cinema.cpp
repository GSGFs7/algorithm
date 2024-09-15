#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出n个0~n-1之间的数, 求有多少种方法使选中的数字大于等于选中的数量
  并且使所有未选中的数大于选中数的数量

  思路:
    排序
    排序后枚举选中的数量, 看是否可以完整的从这个位置将数组划成两半
    如果能够划分成两半就表明可以这样经行划分
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int cnt = 0;
    if (a[0] != 0) cnt++;
    for (int i = 0; i < n; i++) {
        if (a[i] <= i) {
            while (i < n && a[i] <= i) i++;
            cnt++;
        }
    }
    cout << cnt << '\n';
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


// https://codeforces.com/contest/1782/problem/B
// 2024年5月24日