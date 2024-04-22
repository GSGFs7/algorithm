#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
#define int long long

/// 单调队列优化DP
// 读的假题, 造的桥要连续...
// 还算是板子题...
/*
 * 题目描述:
 *  给出一个n*m的数组, 表示河的深度, 求桥墩间距不超过d的情况下的最小花费
 *
 * 思路:
 *  看懂了题目之后就确定是DP了, 用f来记录到这个点的最小花费, 然后用一个单调栈来取前面d个位置的最小花费
 *  虽然当时没写单调队列, 只是用暴力来试试思路, but, 题目要求造的k座桥是需要连续的!!!(这不浪费钱嘛)
 *  读题还是太差了, 如果看到了的话说不定就出了
 * */

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    // 如果能直接够到对面
    if (m < d + 2) {
        for (int i = 0; i < n; i++)
            for (int j = 0, x; j < m; j++)
                cin >> x;// 先把所有数读掉
        return cout << 2 * k << '\n', void();
    }

    vector<int> a(m);// 每行独立, 直接一行一行处理
    vector<int> f(m);// DP数组
    vector<int> cost(n);// 每行的最小花费
    for (int i = 0; i < n; i++) {
        deque<int> q;// 单调队列, 这个单调队列是用来记录最小的f的, 不是a, 不然f的值就不是最小的
        q.push_back(0);// 初始值
        f[0] = 0;// 初始值, 不然会出事
        for (int j = 0; j < m; j++) {
            cin >> a[j];
            f[j] = f[q.front()] + a[j] + 1;// 需要先计算DP
            while (!q.empty() && f[q.back()] > f[j]) q.pop_back();// 如果后面有小于这个数, 就表示这个数永远都用不到了
            while (!q.empty() && q.front() < j - d) q.pop_front();// 弹出过时的数据
            q.push_back(j);
        }
        cost[i] = f[m - 1];// 记录答案

        // debug
//        cout << "line" << i << '\n';
//        for (int j = 0; j < m; j++) {
//            cout << a[j] << ' ';
//        } cout << '\n';
//        for (int j = 0; j < m; j++) {
//            cout << f[j] << ' ';
//        } cout << '\n';
    }

    // 找连续的k座桥
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += cost[i];
    }
    int res = ans;
    for (int i = k; i < n; i++) {
        res = res - cost[i - k] + cost[i];
        ans = min(ans, res);
    }
    cout << ans << '\n';
}


signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1941/problem/E