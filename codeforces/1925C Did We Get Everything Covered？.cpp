#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define int long long

/*
 * 题目描述:
 *  给出一个字符串s, 求是否存在一个长度为n的子串, 在s中删掉若干字符后不会出现
 * 输入:
 *  第一行三个整数n, k, m, 分别表示子串长度, 字符范围(前k个字符), 原字符串长度
 * 输出:
 *  如果没有不会出现的子串, 输出"YES", 否则输出"NO", 并给出一个例子
 *
 * 思路:
 *  这道题根这场的A很像
 *  对于一个原字符串, 例如:abab
 *  我们可以看成是ab+ab, 这样就会发现对于两个位置[]+[], 都可以从原串对应的位置拿出字符来组成全部的四个组合
 *  而对于aabb这样的原串, 就无法划分, 因为要分给第一个位置就需要前三个字符, 这样最后一个位置就只剩下一个b了
 *  妙啊! 可惜没想到...
 * */

void solve() {
    int n, k, m;
    string s;
    cin >> n >> k >> m >> s;

    set<char> set;// 去重
    vector<bool> ext(26, false);// 是否出现过
    int res = 0;// 完整出现的次数
    string ans;
    for (auto i : s) {
        set.insert(i);
        if (set.size() == k) {// 如果出现完整的一组
            res++;
            set.clear();
            ans += i;
        }
        ext[i - 'a'] = true;
    }

    // 如果子串的每个位置都都能取到所有字符, YES
    if (res >= n) return cout << "YES\n", void();

    cout << "NO\n";
    for (int i = 0; i < k; i++) {
        if (ext[i]) {
            if (!set.count('a' + i)) {
                cout << ans << string (n - res, 'a' + i) << '\n';// 补齐位数
                return ;
            }
        } else {
            cout << string (n, 'a' + i) << '\n';
            return ;
        }
    }
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1925/problem/C