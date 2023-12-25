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


/// 分开版
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, W;
    cin >> n >> W;

    vector<int> w(n + 1), v(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i] >> s[i];

    vector<int> v1(1, 0), w1(1, 0);
    for (int i = 1; i <= n; i++)
    {
        int bin = 1;
        while (s[i] >= bin)
        {
            s[i] -= bin;
            v1.push_back(v[i] * bin);
            w1.push_back(w[i] * bin);
            bin <<= 1;
        }

        if (s[i] > 0)
        {
            v1.push_back(v[i] * s[i]);
            w1.push_back(w[i] * s[i]);
        }
    }
    n = w1.size();

    vector<int> f(W + 1);
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w1[i]; j--)
            f[j] = max(f[j], f[j - w1[i]] + v1[i]);

    cout << f[W] << '\n';
    return 0;
}*/


// https://www.acwing.com/problem/content/description/5/
// https://www.luogu.com.cn/problem/P1776