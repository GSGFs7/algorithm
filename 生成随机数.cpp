#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n = 100;
void solve()
{
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << rng() % 1000000000 + 1 << endl;
    }
}

signed main()
{
    freopen("1.in", "w", stdout);
    FASTIO;
    solve();
    fclose(stdin);
    fclose(stdout);
}