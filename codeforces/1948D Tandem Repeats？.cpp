#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
#define int long long

/*
 * 给出一个字符串s, 求s中存在的两个相同且连续的子串的最大长度
 *
 * 思路:
 *  按照暴力做法, 枚举长度, 枚举起点, 字符串匹配, 各需要O(n)的复杂度, 加起来就是O(n^3), 跑完5000个字符需要36秒(本地)
 *  需要改变思路, 压缩掉其中一维才可以过, 将最后的字符串匹配部分压入其他地方是可行的一个方法
 *
 *  对于 aabaab 这组字符
 *  对于len=3时, 可以直接在当前枚举的位置开始检测, 也就是直接对 a**a** 匹配, 两个a, 匹配成功, 增添一个cnt记录值(初始为0)
 *  枚举指针继续向后, *a**a*, 两个a, 匹配成功, 再次添加一个cnt记录值
 *  第三次, **b**b, 两个b, 添加一个cnt记录值, cnt的长度达到最大长度(len的长度)更新答案
 *  (另外, 如果匹配失败, cnt清零, 也就是表示重新开始一组新的匹配)
 *  用这种方法就可以将字符串匹配的实现压入字符枚举中, 直接减少一维, 复杂度达到O(n^2)级
 *
 * 妙啊~
 * */

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int len = 1; len <= n / 2; len++) {// 枚举长度
        int cnt = 0;// 表示已经匹配成功的长度
        for (int i = 0; i + len < n; i++) {// 枚举指针, 完整走完所有可走的地方
            if (s[i] == '?' || s[i + len] == '?' || s[i] == s[i + len]) {// 对检查部分做特殊优化，整合在枚举起点的过程中
                cnt ++;// 记录长度

                if (cnt == len) {// 这一切都是需要两个子串相连才有意义
                    ans = max(ans, cnt);
                    break;
                }
            } else {// 如果匹配失败, cnt清零
                cnt = 0;
            }
        }
    }
    cout << ans * 2 << '\n';
}


signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//    cout << duration.count();
    return 0;
}


// https://codeforces.com/contest/1948/problem/D