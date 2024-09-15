#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
  给你若干个有两个子节点，一个子节点和没有子节点的点，求生成的图的最小高度

  思路：
    贪心，先填两个子节点的点后填一个子节点的点
*/

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + 1 != c) return cout << -1 << '\n', void();

    if (a + b + c == 1) return cout << 0 << '\n', void();

    int cur = 1;     // 这层还剩多少个没填的，初始为1
    int next = 0;    // 下一层横向有多少
    int ans = 1;
    for (int i = 0; i < a + b; i++) {
        if (!cur) {
            swap(cur, next);
            ans++;
        }

        cur--;
        next++;
        if (i < a) next++;    // 如果添加的是二就需要额外一个
    }
    cout << ans << '\n';
}

int32_t main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}


// https://codeforces.com/contest/1950/problem/F