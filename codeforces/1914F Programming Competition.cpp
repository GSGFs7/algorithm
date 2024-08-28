#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 拓扑排序+贪心
 * n个人参加比赛，每个人不能和自己的上司（间接也算）组队（两人队），求最多有多少个队伍
 *
 * 画出这样的一棵树，很容易得到这样的结论：树上的叶子节点相互间都可以自由组合，而其他部分都会受限
 * 首先，对于下面这样一棵树，
 * 如果先取(4,6)这一组，那么2和3依旧受限，如果先取最低的两个点(5,6)，那么3就会解除受限，可以自由组合
 * 1
 * | \
 * 2  4
 * |
 * 3
 * | \
 * 5 6
 * 那么就有这样的一个贪心思路，优先取最低点的值，以保证其他的部分解除受限
 * 可以使用DFS遍历深度，然后把所有叶子节点全部加入大根堆，每次取用优先深度大的值
 * */

const int N = 2e5 + 10;
vector<int> g[N];
int dep[N];// 深度
int d[N];// 入度

void solve()
{
    int n;
    cin >> n;
    memset(&d, 0, sizeof d);
    for (int i = 1; i <= n; i++) g[i].clear();// 初始化

    vector<int> p(n + 1);// 父节点
    for (int i = 2; i <= n; i++)// 读入后面的数
    {
        int a;
        cin >> a;
        g[a].push_back(i);// 建边
        d[a] ++;
        p[i] = a;
    }

//    for (int i = 1; i <= n; i++) cout << i << ":" << d[i] << ' '; cout << '\n';

    // 标记深度
    dep[1] = 1;
    function<void(int)> dfs = [&](int cur)
    {
        for (int nex : g[cur])
        {
            dep[nex] = dep[cur] + 1;
            dfs(nex);
        }
    };
    dfs(1);

    priority_queue<pair<int, int>> q;// 深度优先排序，大根堆
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q.emplace(dep[i], i);

    int ans = 0;
    while (!q.empty())// 把q.empty()改成现在这样就能过了，不然会TLE
    {
        auto [d0, i] = q.top();
        q.pop();
        if (q.empty()) break;// 如果不能取出两个值
        auto [d1, j] = q.top();
        q.pop();

//        cout << i << ' ' << j << '\n';

        ans ++;
        if (!-- d[p[i]])
            q.emplace(dep[p[i]], p[i]);// 删边
        if (!-- d[p[j]])
            q.emplace( dep[p[j]], p[j]);
    }
    cout << ans << '\n';
//    for (int i = 1; i <= n; i++) cout << i << ":" << d[i] << ' '; cout << '\n';
//    cout << "___________________\n";
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://codeforces.com/contest/1914/problem/F
/*
#include <bits/stdc++.h>
#define int long long
using namespace std;

// *
// * 树形DP
// * n个人参加比赛，每个人不能和自己的上司组队（两人队），求最多有多少个队伍
// *
// * 一个大佬的写法有点难理解
// *

const int N = 2e5 + 10;
vector<int> g[N];
int num[N];
int dp[N];// dp[i]表示在i位置能够取得的最多的队伍

void dfs(int root)
{
    num[root] = 0;
    dp[root] = 0;
    int mx = 0;
    for (auto nex : g[root])// 这个点同向的边
    {
        dfs(nex);// 直接搜到底，从最底层开始DP，到最后的根节点1就是最终结果
        num[root] += num[nex];// 这个点的值，包含多少个点
    }
    for (auto nex : g[root])// 找到最大值
        mx = max(mx, 2 * (num[nex] - dp[nex]) - num[root]);// 不能取的个数
    // 原本取得的数现在不能取，分层
    dp[root] = (num[root] - mx) / 2;
    num[root] ++;// 包括进自己这个根节点
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();// 初始化
    for (int i = 2; i <= n; i++)// 读入后面的数
    {
        int a;
        cin >> a;
        g[a].push_back(i);// 建边
    }
    dfs(1);
    cout << dp[1] << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://codeforces.com/contest/1914/problem/F

*/