#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
#define int long long

/*
 * 给出n头牛, 求其中三个及以上的牛中只存在一头H牛或是G牛的情况有多少个
 *
 * 思路:
 *  枚举区间会达到O(n^2)的复杂度, 数据量再5e5, 必须优化到O(nlogn)级
 *  在一张孤独的照片中必定只会存在一个H牛或是一个G牛
 *  对于这头孤独的牛, 只需要从它下手, 统计出左边有多少个连续的其他牛, 右边有多少个连续的其他牛, 就可以推出这个区间内有多少种情况
 *  例如: HHHGHHHH 这组数据
 *  如果左右两边都有其他牛的话, 那么左边就会存在三种不同的情况, 右边就会存在四种不同的情况, 也就是一共存在12种不同的情况, 可以写成 L*R
 *  如果只有左边有其他牛的话, 那么就只会有两种情况, 可以写成 L-1
 *  如果只有右边有其他牛的话, 那么就只会有三种情况, 可以写成 R-1
 *  三种情况合起来就是 L*R+L-1+R-1
 * */

using LL = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    LL res = 0;
    for (int i = 0; i < n; i++) {// 遍历每头牛
        char x = s[i];
        int l = i - 1, r = i + 1;
        while (l >= 0 && x != s[l]) l--;// 左边的连续的牛
        while (r < n && x != s[r]) r++;// 右边的连续的牛
        // 按照这样写竟然不会超时？

        int L = i - l - 1, R = r - i - 1;
        res += (LL) L * R;// 两边都有牛的情况
        if (L > 0) res += L - 1;// 只有左边有牛的情况
        if (R > 0) res += R - 1;// 只有右边有牛的情况
    }

    cout << res << '\n';
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
//    cin >> t;
    while (t--)
        solve();
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//    cout << duration.count();
    return 0;
}


// https://www.acwing.com/problem/content/description/4264/
// 2024年3月16日