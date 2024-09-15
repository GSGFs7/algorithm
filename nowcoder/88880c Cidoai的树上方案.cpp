#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个n个节点的有根树，以1为根，求在树外一个点向树上节点连边，使最后的简单图不含三元环
  求这样的方案数，对998244353取模。

  树形DP
  题目要求不含三元环，也就是说，相邻的两个节点之间不能同时被选中
  如果树上的相邻的两个节点同时被选中就会与树外的点形成三元环
  那么原本的问题就转化成了在树上取任意个节点，并且确保节点之间没有直接相连
  很标准的树形DP
  从最下面的叶子节点开始向上递推，计算方案数，使用乘法原理
  如果某个子节点没有被选中，那么就可以选这个点也可以不选这个点（乘上两个可能之和）
  如果被选中了，那就只能不选这个点（乘上不选的那个可能）
*/

#define int long long

const int N = 2e6 + 10;
const int MOD = 998244353;
int dp[N][2];
vector<int> son[N];

void dfs(int u) {
    dp[u][0] = dp[u][1] = 1;
    for (auto v : son[u]) {
        dfs(v);
        dp[u][0] = dp[u][0] * ((dp[v][0] + dp[v][1]) % MOD) % MOD;
        dp[u][1] = dp[u][1] * dp[v][0] % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        son[x].push_back(i);
    }

    dfs(1);

    cout << (dp[1][0] + dp[1][1]) % MOD << '\n';
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


// https://ac.nowcoder.com/acm/contest/88880/C
// 2024-09-14