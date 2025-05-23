#include <functional>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出两个数组, p和a, 进行k步操作, 留在i或是前往p[i], 每次都会获得a[i]的价值, 求最大价值
*/

#define int long long

void solve() {
    int n, k, s1, s2;
    cin >> n >> k >> s1 >> s2;
    s1--, s2--;
    vector<int> p(n), a(n);
    for (auto &i : p) cin >> i, i--;
    for (auto &i : a) cin >> i;

    int ans1 = 0, ans2 = 0;
    vector<bool> vis1(n, false);
    function<void(int, int, int)> dfs1 = [&](int cur, int sum, int step) {
        if (vis1[cur]) return;
        if (k == step) return;

        // cout << cur << '\t';
        vis1[cur] = true;
        ans1 = max(ans1, sum + a[cur] * (k - step));
        dfs1(p[cur], sum + a[cur], step + 1);
    };
    dfs1(s1, 0, 0);

    vector<bool> vis2(n, false);
    function<void(int, int, int)> dfs2 = [&](int cur, int sum, int step) {
        if (vis2[cur]) return;
        if (k == step) return;

        // cout << cur << '\t';
        vis2[cur] = true;
        ans2 = max(ans2, sum + a[cur] * (k - step));
        dfs2(p[cur], sum + a[cur], step + 1);
    };
    dfs2(s2, 0, 0);

    if (ans1 > ans2) cout << "Bodya\n";
    else if (ans1 < ans2) cout << "Sasha\n";
    else cout << "Draw\n";
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