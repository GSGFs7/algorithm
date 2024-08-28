#include <bits/stdc++.h>
using namespace std;

/* 概率动态规划 */
/* 计算某点的概率 */

const int N = 110;
long double f[N];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a[n];
    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> x >> y;
        a[x].emplace_back(y);
    }

    f[1] = 1;// 点1为起点，所以经过的概率为100%
    for (int i = 1; i <= n; i++)// 枚举每条边
    {
        int const l = a[i].size();// 统计数组长度，时间复杂度为O(n)，所以不要放在for语句内，可能会使时间复杂度变为O(n^2)
        for (int j = 0; j < l; j++)
            f[a[i][j]] += f[i] / l;// 每个节点均分概率
    }

    printf("%.10Lf", f[n]);
    return 0;
}