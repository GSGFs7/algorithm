#include <iostream>
using namespace std;

const int N = 110;
int f[N][N], v[N], w[N], t[N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> t[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j; j--)
            for (int k = q; k; k--)// 在原本的基础上再加上一个条件
                if (j >= v[i] && k >= t[i])
                    f[j][k] = max(f[j][k], f[j - v[i]][q - t[i]] + w[i]);

    cout << f[m][q] << endl;
    return 0;
}