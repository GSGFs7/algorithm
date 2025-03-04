#include <bits/stdc++.h>

using namespace std;

/*
 * 给出两个数组 l[]和r[] 可以选择一个区间 但是这个区间不能包含 l[i]~r[i] 这个区间
 * 问这样的区间有多少个
 *
 * 对于一个没有限制的区间 最大的能够使用的区间数量是 1+...+i （i表示区间长度）
 * 因此 对于一个没有限制的区间 只需要从1到区间末尾累加i即可
 * 但是对于一个有限制的区间的话 最大就只能加到限制区间的末尾
 * 对于这个限制区间末尾后面没有限制的区间 起点就变成了 这个区间的左端点加1
 * 那么对于这个后面这没有限制的一段 就只需要从l+1开始向后累加
 * 最后每一个位置上的贡献就是 i-l+1 直接对于m上的每一个位置累加即可
 * 喵啊～
 * */

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ans(m + 1, 1);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        ans[r] = max(ans[r], l + 1);    // 对于这个右端点的最小的区间
    }

    // 左端点 单调递增
    for (int i = 1; i <= m; i++) {
        ans[i] = max(ans[i], ans[i - 1]);
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        cnt += i - ans[i] + 1;    // 这个没有限制的区间
    }
    cout << cnt << '\n';
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


// https://atcoder.jp/contests/abc377/tasks/abc377_d
// 2024-10-27
