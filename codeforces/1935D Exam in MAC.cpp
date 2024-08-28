#include <iostream>
#include <vector>

using namespace std;
#define int long long

/*
 * 题目描述:
 *  给出n个s和一个c,求不满足x+y=s和y-x=s的{x,y}有多少个(0<=x<=y<=c)
 * 徒手画表:
 *  00 01 02 03 04 05 06 07
 *  __ 11 12 13 14 15 16 17
 *  __ __ 22 23 24 25 26 27
 *  __ __ __ 33 34 35 36 37
 *  __ __ __ __ 44 45 46 47
 *  __ __ __ __ __ 55 56 57
 *  __ __ __ __ __ __ 66 67
 *  __ __ __ __ __ __ __ 77
 *  如果选择s=4的话,就需要划掉22-04这一斜向上的一排(x+y=s)和04-37这斜向下的一排(y-x=s),很明显,这样划会导致一个数的重复
 *  如果再选择s=5的话,正好完全和s=4错开了
 *  如果再选择s=6的话,会发现除了05之外还和s=4相交了一个位置15
 *  ...
 *  先看偶数,对于偶数而言,每再增加一个偶数就会额外增加偶数的数量个交点,也就是从1一直加到偶数的个数为止,奇数同理
 * 小声):
 *  之前图方向画饭了,看半天都看不出来什么
 * */

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    int odd = 0, even = 0;// 奇数和偶数
    int ans = (c + 1) * (c + 2) / 2;// 没有限制时的情况,从1加到c+1
    for (int i = 0; i < n; i++) {
        ans -= (a[i] >> 1) + 1;// y-x=s的情况
        ans -= c - a[i] + 1;// x+y=s的情况

        if (a[i] & 1) odd ++;
        else even ++;
    }

    // x-y=s和y-x=s同时存在的情况,奇偶区分计算
    ans += odd * (odd + 1) / 2;
    ans += even * (even + 1) / 2;

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

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1935/problem/D