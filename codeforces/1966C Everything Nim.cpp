#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
  给出n堆石子, 每次最多可以从每堆石子中取最小的那堆数量的棋子, 求最佳情况的胜者

  思路:
    对于连续的几堆石子, 如1,2,3,4,5它们的情况是固定的, 也就是说奇数情况下先手必胜
    对于4,5,6,7,8,9只有第一次操作的人才有选择权, 最后一个可以自由选择的人肯定能主宰这场游戏
    如何成为最后一个有选择权的人? 可以先推出倒数第二个有选择权的人, 以此类推
    也就是说第一个有选择权的人是可以操控每轮的操作权落到谁的手上
    那么就只需要求出第一个拥有操作权的人就可以求出最后的胜者
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;    // 去重
    for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]]++;

    int last = 0;
    int sum = 0;
    bool flag = false;
    for (auto i : mp) {    // 从1开始向后查找
        if (i.first == last + 1) {
            sum++;    // 切换必胜和必败态
            last = i.first;
        } else {
            flag = true;    // 到这就可以自由选择了
            break;
        }
    }

    if (flag) {
        if (sum & 1) cout << "Bob\n";
        else cout << "Alice\n";
    } else {
        if (sum & 1) cout << "Alice\n";
        else cout << "Bob\n";
    }
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


// https://codeforces.com/contest/1966/problem/C
// 2024年4月28日