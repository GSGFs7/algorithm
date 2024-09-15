#include <iostream>
using namespace std;

const int N = 110;
int f[N], v[N], w[N], l[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> l[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= l[i]; j++)// 队第i个数进行限制
            for (int k = m; k >= v[i]; k--)// 01背包一致
                f[k] = max(f[k], f[k - v[i]] + w[i]);
    cout << f[m] << endl;
    return 0;
}