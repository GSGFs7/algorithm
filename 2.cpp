#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
int f[N];
vector<vector<pair<int, int>>> a(N);

int main()
{
    int n, m;
    cin >> m >> n;
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        int v, w, g;
        cin >> v >> w >> g;
        t = max(t, g);
        a[g].emplace_back(v, w);
    }

    for (int i = 1; i <= t; i++)
        for (auto j : a[i])
            for (int k = m; k >= j.first; k--)
                f[k] = max(f[k], f[k - j.first] + j.second);

    cout << f[m] << endl;
    for (int i = 1; i <= m; i++)
        cout << f[i] << ' ';
    return 0;
}