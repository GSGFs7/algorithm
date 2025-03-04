#include <bits/stdc++.h>

using namespace std;

/*
 * 给出一个排列 每次操作使p[i]变成p[p[i]] 问操作k次后的排列是什么
 *
 * 因为是整个排列内部交换 最后肯定会成环 也就是每个环的内部相互移动
 * 模拟一下样例
 * 第一次操作移动1格 第二次移动2格 第三次4格...
 * 那么操作k次也就是需要移动2^k格（在长度足够的情况下）
 * 为什么就没有仔细看看呢 Debug了老半天
 * */

#define int long long

// 快速幂计算2的幂次
int fpow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    // 查找每个点的循环
    vector<bool> vis(n);
    vector<int> ans(n);    // 对应表
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        // 找这个位置上相连的环
        int j = i;
        vector<int> cycle;
        while (!vis[j]) {
            vis[j] = 1;
            cycle.push_back(j);
            j = a[j];
        }

        // 看最后落在哪里
        int len = cycle.size();
        for (int i = 0; i < len; i++) {
            int step = (fpow(2, k, len) + len - 1) % len;    // 计算需要移动多少格
            int j = (i + step) % len;
            ans[cycle[i]] = cycle[j];    // 记录答案
        }
    }
    for (auto i : ans) cout << a[i] + 1 << ' ';
    cout << '\n';
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


// https://atcoder.jp/contests/abc377/tasks/abc377_e
// 2024-10-29
