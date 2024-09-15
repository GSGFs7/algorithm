#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 欧拉图板子
 * 给出n条边，输出欧拉路的任意一种可能的情况
 * 与其他的题目不同的是一条边需要正反走两次，从1号点出发回到1号点
 * 直接vector存边再删掉
 * */

int const N = 1e4 + 10;
vector<int> v[N];// 存边
vector<int> path;
int n, m;

void dfs(int x)
{
    int const len = v[x].size();
    for (int i = 0; i < len; i++)
        if (v[x][i])
        {
            int const next = v[x][i];
            v[x][i] = 0;// 删边
            dfs(next);
        }
    path.push_back(x);// 倒序，需要放在循环的外面才算
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    int const len = path.size();
    for (int i = len - 1; i >= 0; i--)
        cout << path[i] << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P6066