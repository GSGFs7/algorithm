#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

/*
  给出一个数组a 对数组进行q次操作 每次将pos位置上的值改为x 问每次操作后的MEX

  数据范围过大不可能使用暴力的方法处理 
  因为每次都是使用不存在于数组中的最小的那个值作为最后的结果
  可以直接使用小根堆维护最小值 
  如果在一次更改中有新的数出现 直接insert进set中
  如果有数彻底消失 就从set中earse掉
  每次输出堆顶的值即可
  a[i]的范围是1e9 N的范围是2e5 可以使用离散化优化
*/

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 生成所有可能的结果并填入set中
    vector<int> tmp(n + 1);
    iota(tmp.begin(), tmp.end(), 0);
    set<int> mex(tmp.begin(), tmp.end());

    // 统计个数，并从set中删除出现的数
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 1) mex.erase(a[i]);
    }

    while (q--) {
        int idx, x;
        cin >> idx >> x;
        idx--;

        // 如果不存在这个数了加入到mex
        cnt[a[idx]]--;
        if (cnt[a[idx]] == 0) mex.insert(a[idx]);

        a[idx] = x;

        // 如果新加入了一个本来不存在的数 就要从mex中删除
        cnt[a[idx]]++;
        if (cnt[a[idx]] == 1) mex.erase(a[idx]);

        cout << *mex.begin() << '\n';
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


// https://atcoder.jp/contests/abc330/tasks/abc330_e
// 2024-10-06