#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个数组, 求最少的k, 使得连续的k个数相或的值相等

  思路:
    要求某个区间的或值相等, 那么他们的值一定与整个数组的或值相等 (不然会有多出来的某一位)
    既然确定好最后的或值后就可以开始求区间的长度了
    对于样例 2 0 4 0 2 明显不能使用贪心的方法, 0会被吃掉
    既然知道结果是确定的, 直接看需要多长的范围才能得到这个区间即可
    至于这个范围的求法, 因为数组中所有数字出现过的每一位1都是最后结果所必须的
    直接看最大的两个1之间的距离, 区间的大小一定是由距离最大的那一位确定的
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a[30];
    for (int i = 0; i < 30; i++) a[i].push_back(0);    // 左边界
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < 30; j++) {
            if (x >> j & 1) a[j].push_back(i + 1);    // 记录每一位出现的位置
        }
    }
    for (int i = 0; i < 30; i++) a[i].push_back(n + 1);    // 右边界

    int maxn = 1;
    for (int i = 0; i < 30; i++) {
        if (a[i].size() == 2) continue;    // 忽略
        for (int j = 1; j < a[i].size(); j++) {
            maxn = max(maxn, a[i][j] - a[i][j - 1]);    // 所有的位置上的最大出现间隔
        }
    }
    cout << maxn << '\n';
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


// https://codeforces.com/contest/1973/problem/B
// 2024年5月18日