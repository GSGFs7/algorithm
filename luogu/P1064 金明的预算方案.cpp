#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 有依赖的背包问题
 * 略微有点类似于分组背包，只不过组内的物品必须取主件才能取配件
 *
 * 直接按照分类进行01背包，在状态转换方程那部分加入配件的转换方程（只适合少量的配件）
 * 转换方程：
 *  1.只有主件  f[j] = max(f[j], f[j - w[i][0]] + v[i][0] * w[i][0]);
 *  2.主件+配件1    f[j] = max(f[j], f[j - w[i][0] - w[i][1]] + v[i][0] * w[i][0] + v[i][1] * w[i][1]);
 *  3.主件+配件2    f[j] = max(f[j], f[j - w[i][0] - w[i][2]] + v[i][0] * w[i][0] + v[i][2] * w[i][2]);
 *  4.主件+配件1+配件2    f[j] = max(f[j], f[j - w[i][0] - w[i][1] - w[i][2]] + v[i][0] * w[i][0] + v[i][1] * w[i][1] + v[i][2] * w[i][2]);
 * 01背包只能进行当个物品的添加，如果要加多个物品需要进行绑定
 * */

const int N = 70, M = 3.2e4 + 10;
int v[N][3], w[N][3];// v重要度（价值），w价格（重量）   价值的计算为 v*w
int f[M];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int vv, ww, g;
        cin >> ww >> vv >> g;
        if (g == 0)
        {
            v[i][0] = vv;
            w[i][0] = ww;
        }
        else if (v[g][1] == 0)// 这里是g表示所属的主件
        {
            v[g][1] = vv;
            w[g][1] = ww;
        }
        else
        {
            v[g][2] = vv;
            w[g][2] = ww;
        }
    }

    for (int i = 1; i <= n; i++)// 枚举主件
        for (int j = m; j >= w[i][0]; j--)// 01背包
        {
            // 捆绑添加，直接暴力枚举主件的每个条件
            if (j >= w[i][0])// 如果只放主件
                f[j] = max(f[j], f[j - w[i][0]] + v[i][0] * w[i][0]);

            if (j >= w[i][0] + w[i][1] && v[i][1])// 如果只放主件和一号配件
                f[j] = max(f[j], f[j - w[i][0] - w[i][1]] + v[i][0] * w[i][0] + v[i][1] * w[i][1]);

            if (j >= w[i][0] + w[i][2] && v[i][2])// 如果只放主件和二号配件
                f[j] = max(f[j], f[j - w[i][0] - w[i][2]] + v[i][0] * w[i][0] + v[i][2] * w[i][2]);

            if (j >= w[i][0] + w[i][1] + w[i][2] && v[i][1] && v[i][2])// 如果放主件和全部两个配件
                f[j] = max(f[j], f[j - w[i][0] - w[i][1] - w[i][2]] + v[i][0] * w[i][0] + v[i][1] * w[i][1] + v[i][2] * w[i][2]);
        }

    // debug
//    for (int i = 1; i <= n; i++) {
//        for (auto j: v[i])
//            cout << j << ' ';
//        cout << '\n';
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (auto j : w[i])
//            cout << j << ' ';
//        cout << '\n';
//    }

    cout << f[m] << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1064