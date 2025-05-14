#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int n = 1e3;    // 数的个数
int m = 1e5;
int mod = 1;    // 数的最大值

void solve() {
    // for (int i = 1; i <= n; i++) {
    cout << rng() % n + 1 << ' ' << rng() % n + 1 << ' ';
    cout << m << '\n';
    // }
    // cout << '\n';
}

void solve1() {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 451; j++) {
            cout << ((rng() % 5) ? 0 : rng() % 1000) << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    FASTIO;
    freopen("1.in", "w", stdout);


    int t = 1;
    while (t--) solve1();
}