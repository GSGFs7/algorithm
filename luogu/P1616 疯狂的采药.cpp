#include <iostream>
using namespace std;

const int N = 10000010;
long long v[N], w[N], f[N];// long long 加1e7，这数据真的大

int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    // debug
    //for (int i = 1; i <= m; i++) cout << f[i] << ' ';
    return 0;
}


// https://www.luogu.com.cn/problem/P1616