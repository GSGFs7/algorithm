#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>    // iota的头文件
#include <set>
#include <vector>

using namespace std;
#define int long long

void debug() {
#ifdef __LOCAL__
#endif
}

/*
  给出一个01串, 可以花费c[i]的代价对串中的字符取反, 求变成只存在一个00或者11的串的最小花费

  思路:
    前缀和与后缀和拼接, 取最小代价
    前缀和与后缀和要区分奇偶, 相错凭借, 这样才会出现一个00或是11
*/

/**
 * @brief 代码写这里!!!
 */
void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++) cin >> cost[i];

    // 花费的前缀和
    vector<int> f1(n + 1, 0);    // 奇数为1的情况
    vector<int> f2(n + 1, 0);    // 偶数为1的情况
    for (int i = 1; i <= n; i++) {
        f1[i] = f1[i - 1];
        f2[i] = f2[i - 1];

        if (i & 1) {
            if (s[i] == '0')
                f1[i] += cost[i];
            else
                f2[i] += cost[i];
        } else {
            if (s[i] == '1')
                f1[i] += cost[i];
            else
                f2[i] += cost[i];
        }
    }

    // 后缀和
    vector<int> b1(n + 2, 0);    // 奇数的情况
    vector<int> b2(n + 2, 0);    // 偶数的情况
    for (int i = n; i > 0; i--) {
        b1[i] = b1[i + 1];
        b2[i] = b2[i + 1];

        if (i & 1) {
            if (s[i] == '0')
                b1[i] += cost[i];
            else
                b2[i] += cost[i];
        } else {
            if (s[i] == '1')
                b1[i] += cost[i];
            else
                b2[i] += cost[i];
        }
    }

    // 认真读题，要求恰好有一个连续的0或者1
    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i < n; i++) {    // 循环也要留个缺口, 不能让一个数组占满
        // ans = min(ans, f1[i] + b1[i + 1]);
        ans = min(ans, f1[i] + b2[i + 1]);    // 相错拼接
        ans = min(ans, f2[i] + b1[i + 1]);
        // ans = min(ans, f2[i] + b2[i + 1]);
    }
    cout << ans << '\n';

    // for (int i = 1; i <= n; i++) {
    //     cout << f1[i] << '\t';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++) {
    //     cout << f2[i] << '\t';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++) {
    //     cout << b1[i] << '\t';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++) {
    //     cout << b2[i] << '\t';
    // }
    // cout << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}


// https://atcoder.jp/contests/abc346/tasks/abc346_d
// 2024年3月26日