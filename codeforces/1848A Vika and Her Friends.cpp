#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int g[N][N];

/// 还有反对角线!!!
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    cin >> x >> y;

    bool flag = true;
    int x1, y1;
    for (int i = 1; i <= k; i++)
    {
        cin >> x1 >> y1;
        if (abs(y1 - y) % 2 == abs(x1 - x) % 2) flag = false;
    }
    if (flag) puts("YES");
    else puts("NO");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1848/problem/A