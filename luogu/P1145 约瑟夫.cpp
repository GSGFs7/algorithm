#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 约瑟夫环
 * 直接暴力模拟
 * */

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    cin >> n;
    int k = n;// 因为不能沙好人，所以必定是大于n的
    while (++ k)// 依次暴力枚举
    {
        bool flag = true;
        int p = 0;// 初始位置
        for (int i = 0; i < n; i++)
        {
            p = (p + k - 1) % (2 * n - i);// 模拟部分，加上k后取模，模拟成环的效果
            if (p < n) { flag = false; break; }// 如果沙了好人，直接返回重新开始
        }

        if (flag)// 如果找完了所有k个坏人
        {
            cout << k;
            return 0;
        }
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P1145