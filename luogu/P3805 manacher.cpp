#include <bits/stdc++.h>
using namespace std;

/// manacher算法
/*
 * manacher 算法，用于在O(n)的条件下处理最长回文子串的问题
 * 对于abba类的字符串，表示字符串的中心比较困难，所以加入相同的字符来扩充原字符串，计算结果的时候去掉即可
 * manacher算法需要先暴力计算出以前面点为中心的回文串
 * 后面的部分需要根据前面得到的对称条件来计算对称位置，直接给出起始值，加速计算
 * 得到新点后试试暴力扩展，然后更新最右点和中点（如果超出了范围）
 * 前面暴力后，后面就可以快速起步，平均时间复杂度保持在O(n)
 * */

const int N = 1.1e7 + 10;// 小坑，不是1e7是1.1e7
int n, p[N << 1];// n为变化后的数组长度，p[i]为以i为中心的最长回文子串
char a[N], S[N << 1];// 原字符串和变化后的字符串，涉及随机查找，用数组保险一点，不会RE

/// 初始化
void change()
{
    n = strlen(a);
    int k = 0;
    S[k ++] = '$', S[k ++] = '#';// 头尾不同，避免越界
    for (int i = 0; i < n; i++)
    {
        S[k ++] = a[i];
        S[k ++] = '#';
    }
    S[k ++] = '&';
    n = k;
}

void manacher()
{
    int r = 0, mid;// R表示最右边界，C表示回文中心
    for (int i = 1; i < n; i++) {
        // 合并处理两种情况，i一定大于mid，不确定是否大于r
        // 在左边的对称点取一个最大可取的初始值（即p[(mid<<1)-i]部分），限制条件，范围不能超过最右点（即后面那部分）
        if (i < r) p[i] = min(p[(mid << 1) - i], p[mid] + mid - i);// 如果i在范围内，直接回文对称得到答案
        else p[i] = 1;// 如果不在直接为1，等后面暴力扩展

        while (S[i + p[i]] == S[i - p[i]]) p[i]++;  // 暴力，中心扩展法

        if (p[i] + i > r)   // 更新最大右端点和对称点
        {
            r = p[i] + i;
            mid = i;
        }
    }
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> a;
    change();
    manacher();
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, p[i]);// 找到最长的回文串
    cout << ans - 1 << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P3805
// 最慢的测试点 247ms/115.95MB