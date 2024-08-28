#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define int long long

/*
 * 给出一个字符串, 可以选择一个区间, 将区间内所有的数翻转, 求有多少个不同的字符串
 *
 * 思路:
 *  经典组合数
 *  对于abcd这个字符串, 以a为起点可行的翻转有三个, b有两个, c有一个
 *  而对于abca这个字符串, 以a为起点的可行翻转也有三个, 但是会和bc的翻转重复, 只记bc的就行了, 相当于选择两个a的方案不可行
 *  对于abaa这个字符串, 对于a而言只有ab这一个可行方案
 *  综上, 直接推出结论, 对于以两个相同的字母的区间而言不能进行翻转, 也就是说需要在所有方案中减去这些不行的方案
 *  也就是减去 这个字符出现的次数选出两个 的方案
 * */

void solve(){
    string s;
    cin >> s;

    map<int, int> cnt;
    int n = s.size();
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (!cnt[s[i] - 'a']) flag ++;
        cnt[s[i] - 'a'] ++;
    }

    int f = 0;
    if (flag == 1) return cout << 1 << '\n', void();
    int ans = n * (n - 1) / 2;// 从n-1加到1
    for (int i = 0; i < 26; i++) {
        ans -= cnt[i] * (cnt[i] - 1) / 2;// 组合数, 从cnt[i]中取两个数的组合
        if (cnt[i] > 1) f = 1;
    }
    cout << ans + f << '\n';// 加f, why? 这个东西WA了一个晚上
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://atcoder.jp/contests/abc345/tasks/abc345_c
// 2024年3月18日