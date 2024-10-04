#include <iostream>
#include <stack>

using namespace std;

/*
  给出一个数组s，每次删除s[0]和s[i-1]!=s[i]中的s[i]
  给出一个pair表示b重复了a次
  输出每个位置上的pair前缀在第多少个单位时间内被完全删除

  2300的单调栈？
  因为只有第一个位置和不同的位置上的后面那个值会被删除
  那么前面的小的数对于后面的大的数是没有效果的，并不会对他有影响
  计算到后面的大数后前面的小数可以直接删掉
  同时，如果中间的数全部删掉后，遇到了一个值和自己相等的数
  那么后面的那个数就不会产生消耗，也就是说值相同的两个pair可以直接合并
  使用单调栈进行维护
*/

#define int long long

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    stack<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int d = 0;    // 单调栈向下的过程中的消耗
        while (!stk.empty()) {
            if (stk.top().second == b) {    // 如果可以合并
                a += stk.top().first - d;
                stk.pop();
            } else {
                if (stk.top().first <= a) {    // 删除小的
                    d = max(d, stk.top().first);
                    stk.pop();
                } else {    // 如果到了一个大于自身的位置
                    break;
                }
            }
        }

        stk.push({a, b});
        ans = max(ans, a);
        cout << ans << ' ';
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


// https://codeforces.com/contest/2002/problem/E
// 2024-09-26