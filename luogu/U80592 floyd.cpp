#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 
 * */

const int N = 510;
const int MOD = 998244354;
int f[N][N];

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    memset(&f, 0x3f, sizeof f);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        f[x][y] = min(f[x][y], z);
        f[y][x] = min(f[y][x], z);
    }
    for (int i = 1; i <= n; i++) f[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << f[i][j] << ' ';
        cout << '\n';
    }
     */

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += f[i][j], sum %= MOD;
        cout << sum << '\n';
    }
    return 0;
}



// https://www.luogu.com.cn/problem/U80592