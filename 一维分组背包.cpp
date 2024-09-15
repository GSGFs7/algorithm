#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
int v[N], w[N], f[N], a[N];
vector<int> c[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> v[i] >> w[i];
        c[a[i]].push_back(i);
    }

    for (int i = 1; i <= 1000; i++)// 枚举每一组
        for (int j = m; j; j--)// 枚举体积
            for (auto k : c[i])// 取的哪一个元素
                if (v[k] <= j)// 当能够放下时再进行考虑
                    f[j] = max(f[j], f[j - v[k]] + w[k]);

    cout << f[m] << endl;
    return 0;
}