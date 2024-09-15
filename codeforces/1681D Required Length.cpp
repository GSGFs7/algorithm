#include <iostream>
#include <stdint.h>
#include <vector>

using namespace std;

/*
  给出两个数子n和x, 问在x中选出一位数字与x相乘, 需要几次才可以使x达到n位

  思路:
    暴搜+剪枝
    找出x中的每一位, 从大到小尝试x相乘
    需要加上最优性剪枝, 如果当前状态就算取最小值都无法更新已知答案直接抛弃
*/

#define int long long

int ans;
int n;
void dfs(int u, int step) {
    // 标记出现的数字
    vector<int> vis(10, 0);
    int temp = u;
    while (temp) {
        vis[temp % 10]++;
        temp /= 10;
    }

    // cout << u << ' ';
    // cout << n << ' ';
    // cout << step << ' ';
    // cout << to_string(u).size() << ' ';
    // cout << ans << '\n';

    // 如果找到结果
    if (to_string(u).size() >= n) return ans = min(ans, step), void();

    // 当前状态的最优性剪枝
    if (n + step - to_string(u).size() >= ans) return;

    for (int i = 2; i <= 9; i++) {// 从小到大也能过, 并且消耗时间完全一样? 
        if (vis[i]) dfs(u * i, step + 1);
    }
    // cout << "END\n";
}

void solve() {
    int x;
    cin >> n >> x;
    if (x == 1) return cout << -1 << '\n', void();
    if (n <= to_string(x).size()) return cout << 0 << '\n', void();

    ans = 100;// 写成了 int ans 竟然没报错, de了好久
    dfs(x, 0);
    if (ans == 100) return cout << -1 << '\n', void();
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


// https://codeforces.com/contest/1681/problem/D
// 从小到大 77ms  100KB
// 从大到小 77ms  56KB
// 2024年5月25日