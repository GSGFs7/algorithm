#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出一个字符串，对其中最大的递减（非严格）子串（可能不连续）进行循环右移操作，求几次可以得到一个连续递增的字符串
 * 只有这一种操作，如果不能得到就输出-1
 * 最大子串：按照字典序从前往后最大的子串，如：zaaa大于yyyy
 *
 * 字符串从后往前得到一个非递减子串，将子串翻转即是最终的翻转结果
 * 每次选择的字符串其实都是同一个字符串减去最右边那部分得到的结果，这个字符串就是最开始的最大字符串
 * 每进行一次右移就有一个字符被移到前面，那么这个字符将不会继续参与后续的计算了，最大值已经到他后面了
 * 最初的字符串右移的过程中不会继续找到其他的字符，因为后面有个比他大的数，右移后这个数变得更大了，所以只需要对原来的最大字符串进行操作即可
 * 如果移动结束后整个字符串没有归位，就表明整个字符串已经无法被归位了
 * 需要右移的次数，就是最大值到最后一位所需要的移动次数，也就是： 字符串长度 - 1 - 重复个数（两个最大值算重复一次）
 * */

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 从后开始得到一个从小到大的子串的下标（可能不连续）
    vector<int> a;// 从后往前递增的子串
    a.push_back(n - 1);
    for (int i = n - 2; i >= 0; i--)
        if (s[i] >= s[a.back()]) a.push_back(i);

    int k = a.size();
    for (int i = 0; i < k / 2; i++)// 翻转数组，也就是得到了一个从大到小的数组（存的也是下标）
        swap(s[a[i]], s[a[k - 1 - i]]);// ?
    // 上面两段代码将得到的最大子串按照位置翻转
    // 如：adczfe，最大子串efz，翻转后为adcefz，移动了最后两个字符   Why？为什么可以这样翻
    // 因为每次右移后都要归位最后一个字符，a的大小减一，多次右移后就是翻转的结果

    // debug
//    cout << s << '\n';
//    for (auto i : a) cout << i << ' '; cout << '\n';
//    for (auto i : a) cout << s[i] << ' '; cout << '\n';

    // 如果没有被复原就表明无法复原了，因为移动的规则是固定的
    for (int i = 0; i < n - 1; i++)
        if (s[i] > s[i + 1]) return cout << -1 << '\n', void();

    int ans = k - 1;// 正常情况需要操作的次数
    for (int i = 1; i < k; i++)// 到这里s中已经按从小到大移动好了，a数组的意义也只有看那些字符出现过，因为从后开始，s[0]就是最大的
        if (s[a[i]] == s[a[0]]) ans--;// 如果第最后一个字符重复，就不用移动最后的字符了，因为他已经是最大值了，如zzzza，只需移动a
        else break;

    cout << ans << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t --)
        solve();
    return 0;
}


// https://codeforces.com/contest/1905/problem/C
// 15 ms	4368 KB