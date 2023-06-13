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