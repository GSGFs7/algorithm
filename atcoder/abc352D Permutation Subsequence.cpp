#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
  给出一个1~n的数组, 求一个满足元素为 a~a+k-1 的下标集合, 求这组下标的最小极差
  人话: 找1~k的数, 求这些数的最大下标减去最小下标 (依次往后推)

  思路:
    转个反向
    正着做很麻烦, 直接倒过来
    因为数组是1到n的不会重复的数, 直接用数组的值做下标, 数组中存这个值的原本的下标的位置
    然后数组中的数表示的全部都是下标了, 连续的k个数就表示连续k个数的下标, 直接用滑动窗口维护最值即可
    妙啊~
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        p[t] = i;    // 存储下标
    }

    int ans = 0x3f3f3f3f;
    set<int> s;                       // set集合有序存储滑动窗口中的下标
    for (int i = 1; i <= n; i++) {    // 枚举整数a
        s.insert(p[i]);
        if (i > k) s.erase(p[i - k]);                            // 滑动窗口
        if (i >= k) ans = min(ans, *s.rbegin() - *s.begin());    // 维护最大下标
        // cout << *s.rbegin() << ' ' << *s.begin() << '\n';
    }
    cout << ans;
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


// https://atcoder.jp/contests/abc352/tasks/abc352_d
// 2024年5月6日