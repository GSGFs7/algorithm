#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 二维费用背包
 * 有金钱和时间两个限制条件，直接给dp数组再加上一维就可以实现了
 * 一维表示时间，一维表示金钱，再加上被压缩掉的那一维就可以表示这道题的所有的状态了
 * */

const int N = 210;
int m[N], t[N];
int f[N][N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, M, T;
    cin >> n >> M >> T;
    for (int i = 1; i <= n; i++) cin >> m[i] >> t[i];

    for (int i = 1; i <= n; i++)// 第几个人
        for (int j = M; j >= m[i]; j--)// 多少钱
            for (int k = T; k >= t[i]; k--)// 多久
                f[j][k] = max(f[j][k], f[j - m[i]][k - t[i]] + 1);

    cout << f[M][T] << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1855