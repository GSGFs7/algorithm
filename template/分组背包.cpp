#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 分组背包问题
 * 给出一个能装V容量的背包，若干个分组，每种分组中只能选一个，求最大价值
 *
 * 类似于多重背包的反面
 * 处理的时候需要将背包容量至于上层循环，不然可能会同一组放入多个   重要！
 * 其他部分就类似于01背包，只不过需要倒过来
 * */

const int N = 110;
int v[N], w[N];
int f[N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, V;
    cin >> n >> V;
    while (n--)
    {
        int s;
        cin >> s;
        for (int i = 1; i <= s; i++) cin >> v[i] >> w[i];

        for (int i = V; i >= 0; i--)// 倒过来的01背包
            for (int j = 1; j <= s; j++)
                if (i >= v[j]) f[i] = max(f[i], f[i - v[j]] + w[j]);// 需要判断是否能存下，不然会出错
    }

    cout << f[V] << '\n';
    return 0;
}


// https://www.acwing.com/problem/content/description/9/