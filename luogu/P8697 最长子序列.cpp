#include <iostream>
using namespace std;

/*
 * 注意看题目
 * 题目要求是逐个匹配，第二个字符串必须前面匹配了后面才能继续
 * 所以直接暴力
 * */

const int N = 1010;
/* 这个数据范围，直接暴力 */

int main()
{
    string a, b;
    cin >> a >> b;
    int len = b.size(), len2 = a.size(), ans = 0;
    for (int i = 0, j = 0; i < len; i++)
    {

        while (a[j] != b[i] && j < len2) j++;
        if (j < len2) ans ++;
    }

    cout << ans << endl;
    return 0;
}

// https://www.luogu.com.cn/problem/P8697