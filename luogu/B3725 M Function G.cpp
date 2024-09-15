#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 根据题目给出的式子复刻函数
 * */

const int N = 5e5 + 10;
int a[N];

int func(int l, int r)
{
    if (abs(r - l) > 5)
        return (func(l, (l + r) / 2) % (max(func((l + r) / 2 + 1, r), (int)7)) + a[(l + r) / 2] - 1);
    else {
        int res = 0;
        for (int i = l; i <= r; i++)
            res = max(res, a[i]);
        return res;
    }
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cout << func(1, n) << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/B3725