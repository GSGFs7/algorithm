#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  在一条直线上有n个小猫, 位置为p, 速度为v, 当一只速度快的小猫追上前面的小猫时,
  会与他同行, 速度变为一致, 问最多有多少小猫同行

  思路:
    因为是后面追前面的, 那么从后往前看, 速度一定就是单调递减的(非严格)
    合并位置相同的猫后直接从后往前推(从后往前)
    如果速度大于的话就是可以合并的, 如果不大于的话也会被这个不大于的猫拖累
    对于所有追不上后面的猫进行划分, 最大的划分就是最后的结果
    属于是没读懂题面了, 完全没想到这个点
*/

typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    // 根据前后顺序经行排序
    sort(a.begin(), a.end());

    // 合并相同的为置
    vector<pii> pos;
    for (int i = 0; i < n; i++) {
        pos.push_back({1, a[i].second});
        for (int j = i + 1; j < n; j++) {
            if (a[j].first != a[i].first) break;    // 如果到了不同的位置

            pos.back().first++;
            pos.back().second = min(pos.back().second, a[j].second);    // 最小的速度
            i++;    // 跳过这个点
        }
    }

    // for (int i = 0; i < pos.size(); i++) {
    //     cout << pos[i].first << ' ' << pos[i].second << '\n';
    // }

    // 从后往前按照速度划分
    int ans = 0;
    int cnt = 0;
    int last = 1e9;
    for (int i = pos.size() - 1; i >= 0; i--) {
        if (pos[i].second > last) {    // 如果追得上
            cnt += pos[i].first;
            // last = pos[i].second;
            // 最开始的猫的速度一定是最小的, 不需要更新
        } else {    // 如果最不上这只猫, 开新的一组
            cnt = pos[i].first;
            last = pos[i].second;
        }
        ans = max(ans, cnt);
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