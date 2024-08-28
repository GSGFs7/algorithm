#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 每组给出两个颜色，判断现在的颜色是否成环，如果是就输出
 * 因为是同一串项链上的，所以保证连通性，只要判断是否缺少珠子就可以知道是否成环
 * 如果成环，再利用DFS随便从一个位置开始搜索（因为成环），再倒着输出
 * */

const int N = 55;
int d[N];
int g[N][N];
int cases = 0;
int t;

void dfs(int x)
{
    for (int i = 0; i < N; i++)// 输出任意的一种可能（那为什么偏要倒着呢？）
        if (g[x][i]) {
            g[x][i]--;
            g[i][x]--;
            dfs(i);
            cout << i << ' ' << x << '\n';// 倒着输出，why？
        }
}

void solve()
{
    memset(&g, 0, sizeof g);
    memset(&d, 0, sizeof d);

    int n;
    cin >> n;
    bool flag = true;
    int start = 1e8;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] ++;// 标记连通图
        g[y][x] ++;
        d[x] ++;// 度
        d[y] ++;
        start = min(start, max(x, y));// 找到一个点
    }

    // 要形成欧拉回路一定为偶数
    for (long long const i : d) if (i % 2) flag = false;

    cout << "Case #" << ++ cases << '\n';
    if (flag) dfs(start);
    else
        cout << "some beads may be lost\n";
    if (t > 0) cout << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> t;
    while (t --)
        solve();
    return 0;
}


// https://www.luogu.com.cn/problem/UVA10054