#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个只包含o和x的字符串，将这个字符串复制m次，可以将字符串中的k个x变成o
  求复制出来的这个字符串连续的o最长可能是多少
  1<=n<=3e5
  1<=m<=1e9

  数据范围过大，不可能进行模拟
  因为是复制m次这个字符串，每一小段都是相等的，只需要枚举第一小段的情况就可以了
  如果需要使连续的一段o最大话，也就是需要使一段字串中的x全部变成o
  也就是说x需要是完整字符串的连续子串
  因为一个区间中的x的数量是单调递增的
  那么只需要从1～n的范围内枚举一个起点，然后用二分找出k个x，全部替换为o
  二分得到的最远的距离就是连续o串的长度
*/

#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    // 前缀和统计x的数量
    vector<int> cntx(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cntx[i + 1] = cntx[i] + (s[i] == 'x');
    }

    // 查找x这个位置有多少个x
    auto find = [&](int x) {
        int res = (x / n) * cntx[n];    // 完整的包括s几次
        return res + cntx[x % n];       // 再加上没有完整包括的那部分
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {    // 枚举每个起点
        int front = find(i - 1);      // 这个位置前面有多少x
        int l = i, r = n * m;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (find(mid) - front <= k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, r - i + 1);
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://atcoder.jp/contests/abc300/tasks/abc300_f
// 2024-09-21