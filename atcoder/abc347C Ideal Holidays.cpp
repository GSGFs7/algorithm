#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
#define int long long

/*
  前A天是节假日, 后B天是工作日, 有N个计划安排在D[i]天后, 问是否可以把N个计划全安排在节假日内
  注意: 日期是自己安排的! 换句话说自己决定起点! (打完才发现题读错了)

  思路:
    全部对总日期取模, 压到范围内
    然后复制一份贴到数组后面, 当成循环用
    直接暴力枚举起点, 看有没有一种方案在A的范围内
*/

void solve() {
    int n, A, B;
    cin >> n >> A >> B;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
        --i %= (A + B);
    }

    ranges::sort(a);

    // 这样写会WA一个点, 太可恶了
    // if (a.back() - a.front() >= A) cout << "No\n" << a.back() <<' '<< a.front();
    // else cout << "Yes\n";

    // 相当于复制一份到后面
    for (int i = 0; i < n; i++) a.push_back(a[i] + A + B);

    int dis = numeric_limits<int>::max();// 最大值
    for (int i = 0; i < n; i++) {
        dis = min(dis, a[i + n - 1] - a[i] + 1);// 把每个点都当成起点试一下
    }
    if (dis <= A) cout << "Yes" << endl;
    else cout << "No" << endl;

    for (auto i : a) cout << i << ' ';
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


// https://atcoder.jp/contests/abc347/tasks/abc347_c
// 2024年4月16日