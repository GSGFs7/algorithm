#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 求一个区间内的最大差值
 * 用两个ST表存储同一段区间，一个求最小值一个求最大值，查找时最大减去最小得到答案
 * （当然也有其他方法，线段树，树状数组都可以）
 *
 * 刚学ST表真是什么错误都会犯(1 << i)写成(i << 1)
 * */

const int N = 5e4 + 10;
int tree[N][21], tree1[N][21];
int n, m;

/// logn的复杂度建立ST表
void init()
{
    for (int i = 1; i <= 21; i++)    // 枚举长度
        for (int j = 1; j + (1 << i) - 1 <= n; j ++)  // 枚举起点
        {
            tree[j][i] = max(tree[j][i - 1], tree[j + (1 << (i - 1))][i - 1]);    // 状态转移方程
            tree1[j][i] = min(tree1[j][i - 1], tree1[j + (1 << (i - 1))][i - 1]); // 写成(n-1)了，卡好久
        }
}

/// 区间最大值
int queryMax(int l, int r)
{
    int const k = log2(r - l + 1);
    return max(tree[l][k], tree[r - (1 << k) + 1][k]);
}

/// 区间最小值
int queryMin(int l, int r)
{
    int const k = log2(r - l + 1);
    return min(tree1[l][k], tree1[r - (1 << k) + 1][k]);
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> tree[i][0], tree1[i][0] = tree[i][0];

    init();

    while (m --)
    {
        int l, r;
        cin >> l >> r;
        cout << queryMax(l, r) - queryMin(l, r) << '\n';
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P2880
// 813ms，全部10个检测点