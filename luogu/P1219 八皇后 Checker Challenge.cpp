#include <bits/stdc++.h>
using namespace std;

/*
 * DFS板子
 * 要注意想请对角线的处理方式
 * */

const int N = 20;
int n;
int path[N];
int row[N], dia[N * 2], bDia[N * 2];// 列，对角线，反对角线
int c = 3;
int ans = 0;

void dfs(int u)
{
    if (u == n + 1)
    {
        if (c)
        {
            c --;
            for (int i = 1; i <= n; i++) cout << path[i] << ' ';
            cout << endl;
        }
        ans ++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!row[i] && !dia[i + u - 1] && !bDia[n - i + u - 1])
        {
            path[u] = i;
            row[i] = dia[i + u - 1] = bDia[n - i + u - 1] = true;
            dfs(u + 1);
            row[i] = dia[i + u - 1] = bDia[n - i + u - 1] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1219