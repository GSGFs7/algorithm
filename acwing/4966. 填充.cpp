#include "bits/stdc++.h"

using namespace std;
#define int long long

/*
 * 给出长度为n的01串，求不重复的00和11的个数
 *
 * 样例 1110?0 中存在两个00或者11对，?的匹配与前后顺序应该是以前面的数为主，如果不行再匹配后面的数
 * 如0?11应该先与0匹配，如果是0?1的话前后就没有什么关系了
 * 综上两点，匹配方法应该是依次遍历，如果匹配成功直接向后跳一位避免重叠，如果没有匹配就继续到下一位
 * 很简单，但是想不到
 * */

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1]) cnt ++, i++;  // 如果能够直接匹配
        if (s[i] == '?') cnt ++, i++;       // 如果前一位是?，就只能向后匹配（可能是前面匹配成功导致的后移）
        if (s[i + 1] == '?') cnt ++, i++;   // 如果后一位是?，优先先前匹配
    }
    cout << cnt << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/description/4969/