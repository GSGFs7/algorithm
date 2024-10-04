#include <bits/stdc++.h>
using namespace std;

/*
 * 给出N，求i从0到N的一个排列，排列中的值s[i]是N/j的倍数（看题都看了好久，半个多小时）
 * s[i]取最小值，j的范围是1到9，如果没有符合条件的值输出-
 * */

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    cin >> n;

    // 先求出10以内的因数
    vector<int> a;
    for (int i = 1; i < 10 && i <= n; i++)
        if (gcd(n, i) == i) a.push_back(i);
    int const len = a.size();

    cout << 1;
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (gcd(i * a[j], n) != n && j < len) j++;// 匹配因数如果i*j可以整除N就是正确答案了

        if (j == len)// 这里没加又WA了两发，j会超出vector的范围
        {
            cout << '-';
            continue;
        }
        if (gcd(i * a[j], n) == n) cout << a[j];
        else cout << '-';
    }
    cout << 1 << '\n';
    return 0;
}

// https://atcoder.jp/contests/abc319/tasks/abc319_b