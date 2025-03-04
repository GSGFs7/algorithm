#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个排列 可以任意交换两个数
 * 最少需要几次才可以使数组中所有数满足 p[i]=i 或是 p[p[i]]=i
 *
 * 注意到需要调换位置的数无论如何都会形成一个环
 * 针对这个环进行分析 发现需要 (siz[i]-1)/2 次操作可以全部还原
 * 直接使用并查集判断连通块的大小
 * */

const int N = 1e6 + 10;
int f[N];
int siz[N];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (find(i) != find(x)) {
            siz[find(x)] += siz[find(i)];
            f[find(i)] = find(x);
        }
    }

    // for (int i = 1; i <= n; i++) cout << f[i] << '\t';
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << siz[i] << '\t';
    // cout << endl;

    int ans = 0;
    vector<int> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (vis[find(i)]) continue;
        vis[find(i)] = true;

        if (siz[find(i)] == 2) continue;
        ans += (siz[find(i)] - 1) / 2;
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
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


// https://codeforces.com/contest/2033/problem/E
// 2024-10-25
