#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

/*
  给出一个01串, 从头到尾取两个数视为十进制, 可以选择两个相邻的字符进行交换
  操作次数限制为k, 求把所有的十进制结果相加的最小值

  思路:
    很明显, 不在左右端点的1无论如何都会给出11的贡献
    右端点的贡献为1, 左端点的贡献为10
    尽量移动1到最右端, 然后考虑最左端
    注意: 移动左端点的时候不能动右端点!!!
*/

typedef pair<int, int> pii;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (s.back() == '0') {// 先检查右端点
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1' && n - 1 - i <= k) {
                swap(s[i], s[n - 1]);
                k -= n - 1 - i;
                break;
            }
            if (n - 1 - i > k) break;
        }
    }
    if (s.front() == '0') {// 再检查左端点
        for (int i = 0; i < n - 1; i++) {// 不包括右端点
            if (s[i] == '1' && i <= k) {
                swap(s[0], s[i]);
                k -= i;
                break;
            }
            if (i > k) break;
        }
    }

    // 计算结果
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int temp = (s[i - 1] == '1');
        temp *= 10;
        temp += (s[i] == '1');
        ans += temp;
    }
    cout << ans << '\n';
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


// https://codeforces.com/contest/1691/problem/C
// 2024年5月23日