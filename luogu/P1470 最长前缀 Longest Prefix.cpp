#include <iostream>
using namespace std;

/// 暴力出奇迹
/*
 * 找S中在s中存在的最长前缀
 * 思路：
 *  枚举S中的每一位，暴力上标记，上完标记在进行统计
 * 要注意某一位上的字符需要后面的字符上标记
 *
 * #6 378ms/860.00KB
 * */

const int N = 210000, M = 210;
string s[M], S;
int cnt = 0;
int ans = 0;
bool b[N];

/// 标记是否可在s中找到
void check(int i)
{
    // 枚举s中的每个值，依次检测是否匹配
    for (int j = 0; j < cnt; j++)
    {
        if (i < s[j].size() - 1) continue;// 长度不够时直接跳过
        // S.substr()取S中的子串，再判断是否匹配
        if (S.substr(i - s[j].size() + 1, s[j].size()) == s[j])
        {
            int l = i - s[j].size() + 1;
            // 如果只给i上标记可能会导致前面某个字符需要后面这个字符匹配的情况漏选
            for (; l <= i && i < N; l++) b[l] = true;// 调了半天，原来是b数组炸了，#6有199049
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    while (cin >> s[cnt], s[cnt ++] != ".");
    while (cin >> s[cnt]) {
        S += s[cnt];// S字符串不止一行
        // debug
        // if (s[cnt] == "!") break;
    }

    /// 上标记
    for (int i = 0; i < S.size(); i++)// 枚举每个位置进行匹配
        check(i);

    // 统计最长前缀
    for (int i = 0; i < S.size(); i++)
    {
        if (b[i]) ans ++;
        else break;
    }
    cout << ans << endl;
    // debug
    // for (int i = 0; i <= S.size(); i++) cout << b[i] << ' ';
    return 0;
}


// https://www.luogu.com.cn/problem/P1470