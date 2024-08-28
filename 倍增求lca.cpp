#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 40000 + 10;// 单纯就是空间太小？
vector<int> v[N], w[N];
int fa[N][32], cost[N][32], dep[N];// fa[i][j] 表示i的第 2^j 个祖先节点

/// 深搜标记深度和倍增的路径关系
void dfs(int root, int fno)
{
    /// 处理父节点
    fa[root][0] = fno;// 2^0 也就是这个点的父节点
    dep[root] = dep[fno] + 1;

    /// 处理祖宗节点
    for (int i = 1; i < 31; i++)// 下往上搜索，最大不会超过 2^31
    {
        // 第 2^i 的祖先节点是第 2^(i-1) 的祖先节点的第 2^(i-1) 的祖先节点。简单说就是 2^i = 2^(i-1) * 2^(i-1)
        fa[root][i] = fa[fa[root][i - 1]][i - 1];// 这个点的第 2^(i-1) 个祖先的第 2^(i-1) 个祖先
        cost[root][i] = cost[root][i - 1] + cost[fa[root][i - 1]][i - 1];// 到祖先的权重 + 祖先到祖先的祖先的权重
    }

    /// 处理这个点连向的其他边
    int sz = v[root].size();
    for (int i = 0; i < sz; i++)
    {
        if (v[root][i] == fno) continue;// 不能自我循环
        cost[v[root][i]][0] = w[root][i];// 到父节点的权重
        dfs(v[root][i], root);// 继续找下一条边
    }
}

/// lca倍增搜索，找到两个点相同的祖先
int lca(int x, int y)
{
    /// 确定一个大小关系
    if (dep[x] > dep[y]) swap(x, y);

    /// 令x，y的深度相同
    int temp = dep[y] - dep[x];// 差值
    int ans = 0;
    for (int i = 0; temp; i++, temp >>= 1)// 直接倍增粗略的找
        if (temp & 1)
            ans += cost[y][i], y = fa[y][i];

    /// 如果刚好可以找到
    if (x == y) return ans;

    /// 如果找不到，就找第一个不是他们祖先的两个点
    for (int i = 30; i >= 0 && y != x; i--)// 从上往下匹配
    {
        if (fa[x][i] != fa[y][i])// 如果找到了一个不是公共祖先的值，继续向上找（可以证明i的值是单调递减的）
        {
            ans += cost[x][i] + cost[y][i];
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    ans += cost[x][0] + cost[y][0];// 最后再加上他们父节点的值
    return ans;
}

void solve()
{
    /// 初始化，千万别忘了
    memset(&fa, 0, sizeof fa);
    memset(&dep, 0, sizeof dep);
    memset(&cost, 0, sizeof cost);
    for (auto i : v) i.clear();
    for (auto i : w) i.clear();

    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(b);// 连向的边
        v[b].push_back(a);
        w[a].push_back(c);// 权重
        w[b].push_back(c);
    }

    // 标记每个点到祖先的路径，用于lca
    dfs(1, 0);

    // m个查询
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int start = clock();

    int t;
    cin >> t;
    while (t--)
        solve();
//    cout << clock() - start << '\n';
    return 0;
}


// https://acm.hdu.edu.cn/showproblem.php?pid=2586