#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 基环树
 * */

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    // 标记初始状态
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++)
        if (s[i] == '1') f[i + 1] = 1;

    // 连边
    vector<int> degree(n + 1);
    vector<int> g(n + 1);
    for (int i = 1, v; i <= n; i++)
    {
        cin >> v;
        degree[v] ++;
        g[i] = v;
    }

    // 入度为0的点
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!degree[i]) q.push(i);

    // 拓扑排序
    vector<int> ans;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        int v = g[u];
        degree[v] --;
        if (f[u]) f[v] ^= 1, ans.push_back(u);
        if (!degree[v]) q.push(v);
    }

    // 处理环
    int flag = 0;
    for (int i = 1; i <= n; i++)
        if (degree[i])
        {
            q.push(i);
            vector<int> temp;
            int t = 0, res = 0;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                temp.push_back(u);
                degree[u] = 0;
                int v = g[u];
                if (f[u]) t ^= 1;
                res += t;
                if (degree[v]) q.push(v);
            }

            if (t) { flag = 1; break; }

            int cnt = temp.size();
            t = 0;
            if (res < cnt - res)
                for (auto x : temp)
                {
                    if (f[x]) t ^= 1;
                    if (t) ans.push_back(x);
                }
            else
                for (auto x : temp)
                {
                    if (f[x]) t ^= 1;
                    if (!t) ans.push_back(x);
                }
        }

    if (flag == 0)
    {
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
    else cout << "-1\n";
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1907/problem/G