#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
  给出一个树, 最多要改多少个数使树上路径异或和不会出现0?

  思路:
    树上启发式合并
    代码有点类似Tarjan? 都是等回溯
    先走到最低点, 统计这个点连向的所有路径的异或和的值, 带着这些值向上回溯
    如果这个点与自己到父节点通向的其他路径异或和为0, 就删掉这个点以及它的所有状态
    继续向上寻找需要删掉的点
*/

const int N = 2e5 + 10;
vector<int> g[N];
set<int> st[N];    // 这个位置有那些值
int a[N];
int ans = 0;

// x表示异或和
void dfs(int u, int fa, int x) {
    bool flag = false;
    st[u].insert(x);
    for (auto v : g[u]) {
        if (v == fa) continue;

        dfs(v, u, x ^ a[v]);    // 等回溯

        // 重要优化, 不然会T49, 只是对比异或后有没有出现相同的数, 可以直反过来
        if (st[v].size() > st[u].size()) swap(st[v], st[u]);
        for (auto i : st[v]) {              // 检查每条路径
            if (st[u].count(i ^ a[u])) {    // 如果异或和出现0
                flag = true;
                break;
            }
        }

        // 准备下一层的数据
        for (auto i : st[v]) st[u].insert(i);
        st[v].clear();
    }

    // 如果这个点需要被删掉
    if (flag) {
        st[u].clear();
        ans++;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, a[1]);

    cout << ans << '\n';
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


// https://codeforces.com/contest/1709/problem/E
// 541ms
// 2024年5月26日