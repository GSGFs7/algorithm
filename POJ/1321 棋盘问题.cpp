#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 10;
char g[N][N];
int n, m;
int ans;
int st[N];

void dfs(int cur, int cnt)
{
    if (cnt == m)
    {
        ans ++;
        return ;
    }

    if (cur > n) return ;

    // 不需要cur再次循环，不然会和dfs重复
    for (int i = 1; i <= n; i++)
        if (g[cur][i] == '#' && !st[i])
        {
            st[i] = true;
            dfs(cur + 1, cnt + 1);
            st[i] = false;
        }

    /// 还有不取这个点的情况
    dfs(cur + 1, cnt);
}

void init()
{
    ans = 0;
    memset(&st, false, sizeof st);
}

int main()
{
    while (true) {
        init();

        cin >> n >> m;
        if (n == -1 || m == -1) exit(0);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];

        dfs(1, 0);

        cout << ans << endl;
    }
}


// http://poj.org/problem?id=1321