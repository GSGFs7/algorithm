#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  Z函sss
  对于一个长度为n的字符串s, z[i]表示s与其后缀s[i,n]的最长公共前缀(LCP)的长度
  如: a a a b a a a b c   的z数组就是
      9 2 1 0 4 2 1 0 0
    因为z[1]表示s[1,n]也就是整个数组
    z[2]表示 aa 这个LCP的长度 (aaab与aab)
    z[4]表示 aaab与b 所以是0
    z[5]表示 aaaba与aaabc 所以是4
  人话: 从当前位置往后截一段, 求这段和原字符串的LCP

  暴力算法需要双指针从前往后依次匹配, 复杂度O(n^2)

  优化:
    Z-box
    对于i, 称区间[i,i+z[i]-1]是i的匹配段, 也被称为Z-box
    算法的运行过程中维护右端点最靠右的匹配段, 记作[l,r], s[l,r]一定是s的前缀
    在计算z[i]的过程中保证l<=i

    利用盒子, 借助之前的状态加速计算新状态
    对于盒子中的字符, 因为是从前面匹配过来的, 直接赋值为对应位置的值即可
        a a a b [a a a b] c
        9 2 1 0 [4 2 1 0] 0
    在z[5]的位置右端点延申到了8的位置, 6~8的值直接从前面复制过来记好了 (类似manacher)
*/

#define int long long    // 会爆int
typedef long long ll;

const int N = 2e7 + 10;
int z[N];
int p[N];

void get_z(string s) {
    z[1] = s.size() - 1;
    for (int i = 2, l, r = 0; i < s.size(); i++) {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);    // 如果在盒子里, 在直接复制
        while (s[1 + z[i]] == s[i + z[i]]) z[i]++;          // 如果匹配, 向后移动
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;      // 如果超出了盒子的范围
    }
}

// 基本还是与上面的求z函数的代码一致, 只需要改一下对应的字符串即可
void get_q(string s, string t) {    // 开始的时候s和t反了, 卡了好久
    int n = s.size();
    int m = t.size();
    for (int i = 1, l, r = 0; i < n; i++) {
        if (i <= r) p[i] = min(z[i - l + 1], r - i + 1);
        while (1 + p[i] < m && i + p[i] < n && t[1 + p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
    }
}

void solve() {
    string s, t;
    string temp;
    cin >> temp;
    s = ' ' + temp;
    cin >> temp;
    t = ' ' + temp;

    get_z(t);
    // for (int i = 1; i < t.size(); i++) cout << z[i] << ' '; cout << '\n';
    get_q(s, t);
    // for (int i = 1; i < s.size(); i++) cout << p[i] << ' '; cout << '\n';

    int ans1 = 0;
    int ans2 = 0;
    for (int i = 1; i < t.size(); i++) ans1 ^= (z[i] + 1) * i;
    for (int i = 1; i < s.size(); i++) ans2 ^= (p[i] + 1) * i;
    cout << ans1 << '\n' << ans2 << '\n';
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


// https://www.luogu.com.cn/problem/P5410
// 2024年5月8日