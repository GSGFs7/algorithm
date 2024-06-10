#include <iostream>
#include <vector>

using namespace std;

/*
  给出n个房间, 每个房间的人有三种状态: 吵, 安静, 无所谓. 求隔开吵和安静的花费

  思路:
    树上DP
    将无所谓的点分成两个状态, 一个状态表示划分在吵的那边, 一个表示划分在安静的那边
    以1为根节点, 向下递归, 从下往上开始DP
    DP分成两种状态, 一种表示吵状态下的最小值, 一种表示安静状态下的最小值
    每次DP都更新两种状态
*/

const int N = 2e5 + 10;
const int INF = 1e9;
vector<int> e[N];
int dp[2][N];    // dp[i][j]表示以j为根时需要的隔板数, i表示吵闹和安静两种状态
string st;       // 每个点的状态

// 树上DP
void dfs(int u, int fa) {
    if (st[u] == 'P') {           // 吵
        dp[0][u] = 0;             // 初始值, 表示这个位置原先没有墙
        dp[1][u] = INF;           // 不存在这种情况
    } else if (st[u] == 'S') {    // 安静
        dp[1][u] = 0;             // 初始值, 表示原先没有墙
        dp[0][u] = INF;           // 不存在这种情况
    } else {                      // 无所谓
        dp[0][u] = 0;
        dp[1][u] = 0;
    }

    for (auto v : e[u]) {
        if (v == fa) continue;

        dfs(v, u);    // 等回溯

        // 转换成另一个状态的花费为1
        if (st[u] == 'P') {    // 根吵的打成一片, 或是建一堵墙与别人分开
            dp[0][u] += min(dp[0][v], dp[1][v] + 1);
        } else if (st[u] == 'S') {
            dp[1][u] += min(dp[1][v], dp[0][v] + 1);
        } else {    // 两个情况都存在
            dp[0][u] += min(dp[0][v], dp[1][v] + 1);
            dp[1][u] += min(dp[1][v], dp[0][v] + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        e[x].push_back(i);
        e[i].push_back(x);
    }
    cin >> st;
    st = " " + st;

    dfs(1, -1);

    // 两种状态下较小的那个
    cout << min(dp[0][1], dp[1][1]) << '\n';
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


// https://codeforces.com/contest/1926/problem/G
// 2024年5月11日