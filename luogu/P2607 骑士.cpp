#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 基环树 树形DP
 * 每名骑士都有自己痛恨的人，这两个人不能一起出战，每个人都有一定的战斗力，求战斗力的最大值
 *
 * 如果a痛恨b就建立一条b->a的边，那么就会得到一个外向基环森林（因为每个点只有一个出度）
 * 基环树可以通过断环来得到一棵正常的树
 * 得到正常的树后进行树形DP，f[u][1]表示选，f[u][0]表示不选
 * 对于其子节点j而言不可能u和j同时选，得到状态转换方程f[u][0]=max(f[j][0],f[j][1]) f[u][1]+=f[j][0]
 * 如果断掉x->y这条边，那么答案sum关系为sum=sum+max(f[x][0],f[y][0])
 * */

const int N = 1e6 + 10;
int fa[N], val[N], mark;// val表示权重，DP中的价值
bool vis[N];// 是否访问过，经行一次DP就可以不用再次访问
vector<int> G[N];// 邻接矩阵
int dp[N][2];// dp的两种状态，选与不选

// 建立一条相连的边
void addEdge(int from, int to)
{
    G[from].push_back(to);  // 邻接表
    fa[to] = from;          // 建边，排斥关系（to不于from同时存在）
}

void dfs(int u)
{
    dp[u][0] = 0;       // 不参加
    dp[u][1] = val[u];  // 参加
    vis[u] = true;
    for (int v : G[u])  // 遍历邻居，找到下一个点，进行树状DP
    {
        if (v == mark) continue;// mark是DP的终点，需要最后回溯的时候处理

        dfs(v); // 利用DFS的回溯，dp从头开始
        dp[u][1] += dp[v][0];               // 选父节点，子节点不能选
        dp[u][0] += max(dp[v][0], dp[v][1]);// 选子节点，可选可不选
    }
}

// 寻找环基树上出现过两次的一个点，以这个点作为起点
int check(int u)
{
    vis[u] = true;
    int f = fa[u];
    if (vis[f]) return f;   // 如果找到了出现两次的点，返回
    else return check(f);// 这里要加return，传递返回值，不然会报错
}

// 处理基环树
int solve(int u)
{
    int res = 0;

    mark = check(u);    // 找到环上一点，作为搜索的起点
    dfs(mark);      // 搜索
    res = max(res, dp[mark][0]);// mark不参加得到的结果，这里的结果娶不到mark？mark仍是val[mark]？可以取到最后计算的就是mark的u

    // 换成父节点再来一遍？
    mark = fa[mark];
    dfs(mark);
    res = max(res, dp[mark][0]);// mark的父节点不参加得到的结果，以最开始的mark为起点，以他的父节点为终点的树形DP？并不是
    // 如果是这样的话最上面的res=max(...)这行还有什么意义呢？去掉只有30pts了

    return res;
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 1, d; i <= n; i++)
        cin >> val[i] >> d, addEdge(d, i);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) ans += solve(i);   // 逐个点检查是不是环基树

    cout << ans << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P2607
// c++20换成c++17就过了，不理解，负优化？
// 第一道紫题，虽然题解