#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个数组 问在数组的空隙中插入+和- 最后组成的式子是否可以是k的倍数
 *
 * 看到这题第一眼就感觉是DFS
 * 每次操作有两种选择 DFS的时间复杂度是O(n^2)
 * 但是每次操作都会产生一个数 直接MLE了 代码：
 *  function<bool(int, int)> dfs = [&](int u, int res) {
 *      if (u > n) return res % k == 0;
 *      return dfs(u + 1, res + a[u]) || dfs(u + 1, res - a[u]);
 *  };
 * 因为只与最后得到的数是否是k的倍数有关 与中间的所有变量无关
 * 使用DP来忽略中间的值 只关心这个值是否可达
 *
 * 可行性DP
 * 从第一个状态开始向后DP 是否可以抵达最后一个点
 * 每次加入一个位置的值之后 都对k范围内的所有的数判断一下是否可达
 * 将这次的关系作为下一次的前置条件 看最后到第n个数的时候是否可达
 * 因为是对k取模的结果 +和-并不影响取模操作
 * 先对输入的数进行取模操作 让他在0~k这个区间中 省去很多不必要的计算
 * 设d[i][j]表示 在i这个位置上j的可达性
 * 那么题目的要求就变成了判断a[n][0]是否可达
 * 使第一个点为1 看能否传递到最后的a[n][0]即可
 * 喵啊～
 * */

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // 需要先取模限制范围 再加k 再模k
        // a[i] = (a[i] + k) % k;
        a[i] = (a[i] % k + k) % k;
    }

    vector<vector<bool>> f(n + 1, vector<bool>(k + 1, false));
    f[0][0] = true;
    f[1][a[1]] = f[1][(-a[1] + k) % k] = true;
    for (int i = 2; i <= n; i++) {       // 枚举到哪个位置了
        for (int j = 0; j < k; j++) {    // 没有顺序关系 直接遍历即可
            f[i][j] = f[i - 1][(j + a[i]) % k] || f[i - 1][(j - a[i] + k) % k];
        }
    }

    // 看最后是否成功传递到n位置下的0这个点
    cout << (f[n][0] == 1 ? "Divisible\n" : "Not divisible\n");
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


// https://www.luogu.com.cn/problem/P1356
// 2024-10-28
