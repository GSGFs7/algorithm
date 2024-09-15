#include <iostream>
#include <vector>
using namespace std;

/*
 * 分组背包
 * 将01背包分为不同的组
 * 枚举每个组
 * 在每个组下面求01背包
 * 要将背包容量放在枚举背包前面
 * 不然会冲突？
 * */

const int N = 1010;
int f[N];

int main()
{
    int n, m;
    cin >> m >> n;
    int t = 0;
    vector<vector<pair<int, int>>> a(n + 1);// vector嵌套vector，表示分组情况
    for (int i = 1; i <= n; i++)
    {
        int v, w, g;
        cin >> v >> w >> g;
        a[g].emplace_back(v, w);
        t = max(t, g);
    }

    for (int i = 1; i <= t; i++)
        for (int j = m; j >= 0; j--)// 将容量放在前面
            for (auto & k : a[i])
                if (k.first <= j)// 如果放得下
                    f[j] = max(f[j], f[j - k.first] + k.second);

    cout << f[m] << endl;
    // dbg
    // for (int i = 1; i <= m; i++) cout << f[i] << ' ';
    return 0;
}


/// 2023年12月18日 20点34分
// 好像没事么太大区别
/*
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010;
int f[N];
vector<pair<int, int>> G[N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    int t = 0;
    while (n --)
    {
        int w, v, g;
        cin >> w >> v >> g;
        G[g].emplace_back(w, v);
        t = max(t, g);
    }

    for (int i = 1; i <= t; i++)
        for (int j = m; j >= 0; j--)
            for (auto & k : G[i])
                if (j >= k.first) f[j] = max(f[j], f[j - k.first] + k.second);

    cout << f[m] << '\n';
    return 0;
}
*/