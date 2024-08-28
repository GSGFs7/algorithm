#include <iostream>
using namespace std;

/*
 * 在一个环中找一个断点向左右枚举，求最大可取到的值
 * 模拟每次搜索
 * 取断点并求出每个断点对应的最大值
 *
 * 此方法可能时间复杂度略高
 * */

int n;
string s;

/// 选定断点开始搜索
int search(int i)
{
    int l = i, r = i + 1;
    char const L = s[l], R = s[r];
    while (s[l] == L || s[l] == 'w') l --;// 向左枚举边界
    while (s[r] == R || s[r] == 'w') r ++;// 向右枚举边界
    return r - l - 1;
}

int main()
{
    cin >> n >> s;
    s = s + s + s;// 为左右各复制一份，相当于成环

    /// 枚举断点
    int ans = -1;
    for (int i = n; i < 2 * n; i++)// 从中间开始搜索
    {
        if (s[i] != 'w')
            ans = max(ans, search(i));
        else
        {
            s[i] = 'r';// 如果为白色，先使其变成任意一种颜色
            ans = max(ans, search(i));

            s[i] = 'b';
            ans = max(ans, search(i));

            s[i] = 'w';// 变回白色
        }
    }
    ans = min(ans, n);// 最长也比总长长
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1203