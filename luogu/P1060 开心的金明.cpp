#include <iostream>
using namespace std;

/*
 * 01背包
 * 价值的组成为重要度乘以物品价格
 * */

const int N = 100010;
int f[N], v[N], w[N];

int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i] * v[i]);

    cout << f[m] << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1060