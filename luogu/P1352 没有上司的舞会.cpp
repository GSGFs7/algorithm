#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 树形DP
 *
 * 没有上司的舞会
 * 下级不能和直接上级出席同一场舞会，求最大欢乐值
 * 建立图，关联父子节点，利用DP，从根节点开始，如果取了父节点就不能取子节点，如果没取就随便取不取父节点，父节点找最大值即可
 * 在最后的f[root][0]和f[root][1]中取最大值即可
 * */

const int N = 6e3 + 10;
int w[N];// 权重，每个人的快乐指数
vector<int> a[N];
int fa[N];
int dp[N][2];

// 从最底层开始
void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = w[u];

    for (int i : a[u])
    {
        dfs(i);//

        // 状态转移方程
        dp[u][1] += dp[i][0];// 如果选这个点，那么就不能选父节点
        dp[u][0] += max(dp[i][0], dp[i][1]);// 如果不选这个点，那么随便选不选父节点
    }
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];

    for (int i = 1; i < n; i++)
    {
        int l, k;
        cin >> l >> k;// k是l的直接上司
        a[k].push_back(l);// l是k的子节点，外向基环树
        fa[l] = k;// 标记这个点的父节点，外向树，只能有一个父节点（也就是这个人唯一的仇人）
    }

    int t = 1;
    while (fa[t]) t = fa[t];// 找到根节点
    dfs(t);
    cout << max(dp[t][0], dp[t][1]) << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1352