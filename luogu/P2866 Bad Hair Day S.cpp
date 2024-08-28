//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#define int long long
using namespace std;

/*
 * 给出一个数组，求从左到右每个位置可以看到比自己低的数的个数和
 *
 * 数据读入后把前面的数据从大到小存入单调栈，如果后面要加入一个大数，将前面所有的要被除外的数全部都计算区间大小，加入答案
 * （有点类似双指针，利用两个点求区间大小）
 * 到最后会有数无法被除外，就加一个无穷大的数，计算后面数的区间
 * */

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    while (scanf("%lld", &n) != EOF && n)
    {
        stack<int> st;
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
        a[n] = 0x3f3f3f3f3f3f3f3f;// 一个无穷大的数作为结尾，相当于前面的一个大数直接看到了结尾

        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            if (st.empty() || a[st.top()] > a[i]) st.push(i);
            else
            {
                // 倒着从后往前扫，类似双指针，得到的是两个点
                while (!st.empty() && a[st.top()] <= a[i]) ans += i - st.top() - 1, st.pop(); // ?
                st.push(i);
            }
        }
        cout << ans << '\n';
    }
}


// http://poj.org/problem?id=3250
// https://www.luogu.com.cn/problem/P2866