#include <iostream>
#include <vector>
#define int long long
using namespace std;

/*
 * 多重背包 + 二进制优化
 *
 * 多重背包的优化，初步优化为一维数组，最后一个点刚好卡在1.00s
 * 需要二进制优化，拆分单个数组为2的n次方
 * 根据动态规划的基本原理，在得到大值时由小值填满最大空间得到，基本可以视为相加
 * 后面的大值挤掉前面的小值，由二进制的性质，任何一个数都可以拆成若干个二进制相加
 *
 * 借助二进制优化，将O(n^3)的复杂度优化为O(n^2)，n虽然会增大，但可以降一个次方级
 * */

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, W;
    cin >> n >> W;
    vector<int> w(n + 1), v(n + 1), s(n + 1);// 可以不用存这个数， 直接二进制拆分
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];

    vector<int> w1, v1;
    w1.push_back(0), v1.push_back(0);// 0 位置没有值
    for (int i = 1; i <= n; i++)// 把一整个种类拆散为二进制，因为全是一样的数，先后顺序没有意义，直接捆绑在一起
    {
        int bin = 1;
        while (s[i] >= bin)// 2的几次方
        {
            s[i] -= bin;// 拆出
            v1.push_back(v[i] * bin);// 拆散后的数组
            w1.push_back(w[i] * bin);
            bin <<= 1;
        }

        if (s[i] > 0)// 剩下的值
        {
            v1.push_back(v[i] * s[i]);// 一起删掉，不必再次拆分
            w1.push_back(w[i] * s[i]);
        }
    }
    n = w1.size();// 最后有一个废值？

    // 动态规划
    vector<int> f(W + 1, 0);
    for (int i = 1; i <= n - 1; i++)// n-1 删掉最后一个废值
        for (int j = W; j >= w1[i]; j--)// 有限个数，从后往前
            f[j] = max(f[j], f[j - w1[i]] + v1[i]);// 状态转移方程
    // y总的方法貌似时直接把两个代码段(for循环)整合在了一起

    cout << f[W];

    // debug
//    for (int i = 0; i <= W; i++) cout << f[i] << ' ';
    return 0;
}


// https://www.luogu.com.cn/problem/P1776