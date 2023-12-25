#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
 * 给出初始资产和若干个可以投资的项目，求获得的利息最大的情况下的资产
 * 无限个物品可取，完全背包
 * 完成一年后，本金加上最大的利息(f[s])，成为下一年的本金
 * */

const int N = 1e7 + 10;
int f[N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int s, n, d;
    cin >> s >> n >> d;

    vector<int> w(d + 1), v(d + 1);
    for (int i = 1; i <= d; i++) cin >> w[i] >> v[i];

    // 优化：题目说债券的投资额是1000的倍数，把债券的投资额都除以1000，结果不变
    while (n --)
    {
        memset(&f, 0, sizeof f);
        for (int i = 1; i <= d; i++)
            for (int j = w[i] / 1000; j <= s / 1000; j++)// 完全背包，无限个物品，从前到后
                f[j] = max(f[j], f[j - w[i] / 1000] + v[i]);

        s += f[s / 1000];// 进入下一年
    }

    cout << s << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1853