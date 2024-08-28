#include <iostream>
using namespace std;

const int N = 110;
int f[N][N][N], v[N], w[N], t[N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> t[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= q; k++)
            {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= v[i] && k >= t[i])
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - v[i]][q - t[i]] + w[i]);
            }

    cout << f[n][m][q] << endl;
    return 0;
}