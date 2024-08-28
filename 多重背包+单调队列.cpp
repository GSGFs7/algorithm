#include <iostream>
using namespace std;

const int N = 10010;
int f[N], c[N][2];
int v, w, t;// t为可使用次数

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> t;
        for (int j = 0; j < v; j++)
        {
            int k = 0, l = 1;
            for (int p = j, x = 1; p <= m; p += v, x++)
            {
                int const e = f[p] - x * w, r = x + t;
                for (; k >= l && c[k][0] <= e; k--);
                c[++k][0] = e;
                c[k][1] = r;
                f[p] = c[l][0] + x * w;
                for (; k >= l && c[l][1] == x; l++);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}