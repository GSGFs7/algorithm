#include <iostream>
using namespace std;

const int N = 2010;
int f[N], w[N], v[N], l[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> l[i];

    for (int i = 1; i <= n; i++)
    {
        int res = l[i];
        for (int k = 1; k <= res; res -= k, k *= 2)
            for (int j = m; j >= v[i] * k; j--)
                f[j] = max(f[j], f[j - v[i] * k] + w[i] * k);

        for (int j = m; j >= v[i] * res; j--)
            f[j] = max(f[j], f[j - v[i] * res] + w[i] * res);
    }
    cout << f[m] << endl;
    return 0;
}