#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一棵树, 每次使树上一个白色点变成黑色, 求每次改变后的最近的两个黑点的距离

  思路:
    爬树, 两个黑色的点总会存在最近公共祖先
    因为ans总是单调递减的
    直接用dis的来标记这个点到最近黑色点的距离
    每次都需要爬树到根节点 或是 到已知ans后返回 (剪枝)
    然后更新这个点的dis, 也就是dis和dis+已经走过的距离
    这种计算方式即使是最差情况下也能拥有O(nlogn)的复杂度
    因为dis是朝一个方向单调的, 先头尾, 再中间, 复杂度在O(logn)级
*/

const int N = 2e5 + 10;
vector<int> g[N];
int a[N];
int f[N];
int dis[N];
int ans;

// 寻找父节点
void dfs(int u, int fa) {
    f[u] = fa;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}

// 使u点变成黑色
void black(int u) {
    int d = 0;
    while (u) {    // 原本写的f[u], 结果导致根节点一直不对
        // cout << u << ' ' << dis[u] << '\n';
        ans = min(ans, dis[u] + d);
        dis[u] = min(dis[u], d);
        d++;
        u = f[u];

        if (d >= ans) break;
    }
}

// void debug(int u) {
//     while (f[u]) {
//         cout << u << ' ' << dis[u] << '\n';
//         u = f[u];
//     }
// }

void solve() {
    int n, s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(&dis, 0x3f, sizeof dis);
    ans = n;
    dfs(1, 0);

    black(s);
    // cout << dis[1] << '\n';
    // cout << '\n';
    for (int i = 1; i < n; i++) {
        ans = min(ans, dis[a[i]]);
        black(a[i]);
        // debug(a[i]);
        // cout << '\n';
        cout << ans << ' ';
    }
    cout << '\n';
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


// https://codeforces.com/contest/1790/problem/F
// 2024年6月12日