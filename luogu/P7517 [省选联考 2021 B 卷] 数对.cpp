#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个数组, 求数组中有多少对数满足a[i]是a[j]的倍数

  暴力:
    数据量2e5无脑暴力肯定过不了
    但是a[i]的数据范围在1~5e5, 显然是一个可行的突破口
    对于第一层循环i, 直接暴力枚举
    对于第二层循环j, 没有必要枚举所有的数, 只需要枚举a[i]的倍数就可以了
    最后的结果就是他们的出现次数相乘
    用这种方法复杂度可以降低到O(n√n)
*/

#define int long long
const int N = 2e5 + 10;
const int M = 5e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(M);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    int ans = 0;
    for (int i = 1; i <= 5e5; i++) {
        ans += a[i] * (a[i] - 1);    // a[i]重复导致的自我匹配
        // 枚举这个数的倍数寻找答案
        for (int j = i + i; j <= 5e5; j += i) ans += a[i] * a[j];
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


// https://www.luogu.com.cn/problem/P7517
// 2024年6月12日