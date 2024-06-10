#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/*
  给出一个数组, 可以选择两个异或值小于4的数交换位置, 尽可能由小到大排序

  思路:
    异或值小于4不就表明差值在4以内嘛...
    map存优先队列秒了
*/

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, priority_queue<int>> mp;
    for (int i = 0; i < n; i++) cin >> a[i], mp[a[i] / 4].push(-a[i]);
    for (int i = 0; i < n; i++) {
        cout << -mp[a[i] / 4].top() << ' ';
        mp[a[i] / 4].pop();
    }
    cout << '\n';
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


// https://codeforces.com/contest/1971/problem/G
// 2024年5月14日