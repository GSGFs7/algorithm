#include "bits/stdc++.h"

using namespace std;
#define int long long

/*
 * 暴力
 * */

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    {
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            bool flag = false;
            for (int k = 0; k < m; k++)
                if (a[i][k] >= a[j][k]) flag = true;

            if (flag) continue;
            else
            {
                res = j + 1;
                break;
            }
        }
        cout << res << '\n';
    }
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/description/5418/