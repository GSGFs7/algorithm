#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
#define int long long

/*
 * 给出n个区间, 求合并所有可以合并的区间后还剩多少个
 *
 * 思路:
 *  贪心
 *  先把所有的区间按照左边界排序, 这样可以避免后面的区间可能在当前区间左边的情况, 这样只需要处理被覆盖和在右边的情况
 *  对于每个区间, 如果起点在上个区间(可能是合并得到的)的范围内就可以合并, 否则就新建一个区间
 * */

typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    // 以左端点为标准排序
    sort(a.begin(), a.end());

    vector<int> tail;
    tail.push_back(a[0].second);// 区间右端点的个数
    for (int i = 1; i < n; i++) {
        if (a[i].first <= tail.back()) {// 如果没有超过上区间的右端点, 合并
            tail.back() = max(tail.back(), a[i].second);
        } else {
            tail.push_back(a[i].second);// 否则就新建个点
        }
    }

    cout << tail.size() << '\n';
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
    while (t--)
        solve();
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//    cout << duration.count();
    return 0;
}


// https://www.acwing.com/problem/content/805/