#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出n个点，求删掉第i个点所有的边后有多少对不相连的有序对
 *
 * 删掉i的边后i与其他所有点都不相连也就是 (n-1)*2 个有序对
 * 如果这个点还是割点的话，还会产生几个连通块，连通块之间没有路径相连，那么其中1个连通块与其他点的关系就是相乘
 * 将所有相乘的结果相加乘2就是最终的结果
 *
 * 对于相乘的部分，每个连通块分别相乘过于复杂，可以运用乘法原理的加法原理，每个数逐个相乘等于每个数乘前面数的和的和
 * 3*4+4*5+5*6+3*5+4*6=>3*4+(3+4)*5+(3+4+5)*6
 * 将前面乘过的数也加进sum里继续处理后面的连通块
 * 见debug函数
 * */

const int N = 100000 + 10;
int n, m;
int dfn[N];// 时间戳
int low[N];// 低点
int id = 0;// 不同点的编号（时间戳）
int ans[N];
int child[N];// 这个点的子连通块数量
vector<int> g[N];

void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++ id;
    child[u] = 1;// 当前节点的子节点的数量
    int sum = 0;// 这里的初始状态是0，表示已经遍历的子节点的数量

    for (auto v : g[u])
    {
        if (v == fa) continue;// 不能原路返回

        if (!dfn[v])
        {
            dfs(v, u);// 先遍历自己的子节点

            child[u] += child[v];// 加上子节点的节点数量
            low[u] = min(low[u], low[v]);// 更新低点

            if (low[v] >= dfn[u])
            {
                ans[u] += child[v] * sum;// 已经经过的子节点和
                sum += child[v];// 更新为已经经过的点，继续去找其他的点
            }
        }
        else if (dfn[u] > dfn[v])// 如果找到了自己的祖先节点
            low[u] = min(low[u], dfn[v]);// 更新自己
    }

    ans[u] = (ans[u] + sum * (n - sum - 1) + n - 1) * 2;
    // 最后的结果，由已经得到的部分答案 加上 不能抵达的部分乘以自己包含的部分
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 1);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}

void debug()
{
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            ans1 += a[i] * a[j];
    for (int i = 0, sum = 0; i < a.size(); i++)
        ans2 += sum * a[i], sum += a[i];
    cout << ans1 << ' ' << ans2 << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    solve();

    return 0;
}


// https://www.luogu.com.cn/problem/P3469