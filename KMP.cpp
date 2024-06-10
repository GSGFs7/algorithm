#include <iostream>
#include <vector>

using namespace std;

/*
  KMP算法
  给出一个字符串s, 求另一个字符串t是否出现在字符串s中

  暴力做法: 双指针, 一个从s开头往后, 另一个从t开头往后, 复杂度O(nm)

  KMP:
    主要思想:
        1.取最长的相等前后缀, 保证不漏解
        2.通过模式串(也就是t)的自我匹配长度, 计算next函数, 给t的指针打表, 失配时跳到next的位置继续匹配

    使用最长真子串(也就是next数组)来快速定位匹配失败后的位置(尽量少的回溯)
    next数组, 相等前后缀的最长长度, 如: aabaa, 是2(aa), aabaaba, 是4(aaba)
    利用next数组, 只需要遍历一遍s即可找到所有的匹配值, 复杂度O(n)
    关于next的复杂度, 前两个字符需要枚举1次, 前三个字符需要枚举2次, 前四个字符需要枚举3次...复杂度O(n^2)
    但是, 可以针对next进行优化, 可以利用前面的next值来缩小匹配范围, 可以找到这些规律:
    模式串匹配每次最多增加1
    因为next本身就表示最大的匹配长度, 可以直接对前next[i-1]经行匹配
    后面的字符是不需要用到的, 如果匹配失败就缩小范围
    优化后的时间复杂度: j每轮最多加1, 最多向右走n步, 左跳的步数不会超过n步, 总复杂度为O(n)
    在s字符串匹配的过程中next数组表示跳过的字符数
*/

void solve() {
    string s, t;
    string temp;
    int n, m;
    cin >> temp;
    n = temp.size();
    s = ' ' + temp;
    cin >> temp;
    m = temp.size();
    t = ' ' + temp;

    // 预处理next数组
    vector<int> ne(m + 1);
    for (int i = 2, j = 0; i <= m; i++) {           // i用来扫描模式串, j用来扫描前缀
        while (j && t[i] != t[j + 1]) j = ne[j];    // 如果找不到就经行回跳
        if (t[i] == t[j + 1]) j++;                  // 如果可以进行匹配了, 走到匹配的下一位
        ne[i] = j;
    }
    // 对于j的判断而言都是j+1, 失配后找的就是j的前一位

    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != t[j + 1]) j = ne[j];    // 如果不匹配, t就跳到循环匹配的位置
        if (s[i] == t[j + 1]) j++;
        if (j == m) {    // 找到结果, 输出
            cout << i - m + 1 << '\n';
            j = ne[j];    // 回跳, 重新找后面的数
        }
    }
    for (int i = 1; i <= m; i++) cout << ne[i] << ' ';
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


// https://www.luogu.com.cn/problem/P3375
// update: 2024年5月7日