#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
int v[N], w[N], f[N][N], a[N];
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
        for (int j = 0; j <= m; j++){// 枚举体积
            f[i][j] = f[i - 1][j];
            for (auto k : c[i])// 取的哪一个元素
                if (v[k] <= j)// 当能够放下时再进行考虑
                    f[i][j] = max(f[i][j], f[i - 1][j - v[k]] + w[k]);
        }

    cout << f[1000][m] << endl;// 不知道多少组直接取最大
    return 0;
}