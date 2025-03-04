#include <bits/stdc++.h>

using namespace std;

/*
 * 求第n个类似于321这样的递减数
 *
 * 最大也只有987654321 直接暴力跑
 * 得到所有的答案之后直接排序得到第n个数
 * */

#define int long long
vector<int> a;
int s = 0;

void dfs(int x) {
    s = s * 10 + x;
    a.push_back(s);
    for (int i = x - 1; i >= 0; i--) {
        dfs(i);
    }
    s /= 10;
    // cout << s << '\t';
}

void solve() {
    int n;
    cin >> n;

    for (int i = 9; i >= 0; i--) {
        s = 0;
        dfs(i);
    }

    sort(a.begin(), a.end());

    cout << a[n] << '\n';
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


// https://atcoder.jp/contests/abc321/tasks/abc321_c
// 2024-10-20
