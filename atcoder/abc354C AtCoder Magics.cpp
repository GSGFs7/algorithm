#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一张卡的两个状态, 强度a和费用c, 删掉强度低且费用高的卡, 求最后剩下的卡

  思路:
    因为有两个状态, 只需要固定下来其中的一个状态
    对于另一个状态而言只需要找到较大值就可以删去较小的值
    按照c从小到大排序, 相同时按照a从大到小排序
    从前往后遍历, 如果小于前面出现过的值也就说明存在交叉, 需要删掉
    复杂度O(nlogn)
*/

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

void solve() {
    int n;
    cin >> n;
    vector<piii> a(n);    // 前面那个数表示编号, 后面的pair表示a和c
    int id = 1;
    for (auto &i : a) {
        cin >> i.second.first >> i.second.second, i.first = id++;
    }

    // 按照c进行排序, 如果花费相同让强度大的在前面
    auto cmp = [&](piii x, piii y) {
        if (x.second.second != y.second.second) return x.second.second < y.second.second;
        else return x.second.first > y.second.first;
    };
    sort(a.begin(), a.end(), cmp);

    // 因为c已经确定了, 直接从小到大遍历a删掉最小的值即可
    int maxn = 0;
    vector<int> ans;
    for (auto i : a) {
        if (i.second.first < maxn) continue;

        ans.push_back(i.first);    // 记录编号
        maxn = max(maxn, i.second.first);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());    // 结果需要排序输出
    for (auto i : ans) cout << i << ' ';
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://atcoder.jp/contests/abc354/tasks/abc354_c
// 2024年5月19日