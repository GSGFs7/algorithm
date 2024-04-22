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
    unsigned int rdm = rng();
    string s;
    while (s.size() < n) {
        s.push_back('0' + (rdm & 1));
        rdm >>= 1;
        if (!rdm) rdm = rng();
    }
    while (s.size() > n) s.pop_back();
    cout << s << '\n';
}

int cnt = 0;
void solve2() {
    while (cnt < 1e5) {
        for (int i = 1; i < 1000; i++) {
            cnt ++;
            if (cnt >= 1e5) return ;
            cout << i << ' ' << i + 1 << ' ' << 100000 << '\n';
        }
    }
}

signed main() {
    FASTIO;
    freopen("1.in", "w", stdout);


    int t = 1e5;
    while (t--) solve2();
}