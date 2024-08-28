#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;    // 不开long long泪两行
#define int long long

/*
  给出n个a和b, 选a[i]的条件是先选a[i-1], 选b[i]的条件是先选a[i], 求选x个情况下的最小花费

  思路:
    贪心
    考虑范围的最低限度的话就是直接选前x个
    但是这样选肯定不对, 没有考虑后面的情况
    如果在选x+1的范围里面选的话, 最小的方法就是前x+1个a加上这中间最小的x个b
    以此类推, 范围固定的话, 需要的a的值也是固定的, 直接暴力跑一边就可以枚举出所有情况(O(nq))
    关键就是看b的选取, 快速选取最小的x个b可以使用大根堆, 如果最大值大于新值直接替换
    然后因为q雀食很小, 最大也只有100, 直接暴力, 从所有方案中取最小值
*/

const int MOD = 998244353;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    while (q--) {
        int x;
        cin >> x;
        priority_queue<int> pq;    // 存放当前选中的b

        // 前x个所有a和b相加, 可得到一个初步答案
        int sb = 0;    // 前x个b的和
        for (int i = 1; i <= x; i++) {
            pq.push(b[i]);
            sb += b[i];
        }

        int ans = sum[x] + sb;    // 初步答案
        for (int i = x + 1; i <= n; i++) {
            if (b[i] < pq.top()) {    // 如果找到了一个更小的b, 看是否可以更新ans的最小值
                sb = sb + b[i] - pq.top();
                pq.pop();         // 把这个大的丢掉
                pq.push(b[i]);    // 替换成这个小的, 别忘了
                ans = min(ans, sum[i] + sb);
            }
        }

        cout << ans << '\n';
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://ac.nowcoder.com/acm/contest/78306/E
// 2024年4月5日