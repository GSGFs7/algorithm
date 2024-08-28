#include <iostream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;
#define int long long

int c(int a, int b) {
    int res = 1;
    for (int i = a; i > a - b; i--) {
        res *= i;
//        cout << - res << '\n';
    }
    if (b == 2) res /= 2;
    else res /= 6;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for (auto& i : a) cin >> i, cnt[i] ++;

    int ans = 0;
    int last = 0;
    for (int i = 0; i <= n; i++) {// 可以等于...
        if (cnt[i] == 2) {
            ans += c(cnt[i], 2) * (last);
        } else if (cnt[i] > 2) {
            ans += c(cnt[i], 3) + c(cnt[i], 2) * (last);
        }
        last += cnt[i];// 这里，只考虑了从大到小，忘记考虑从小到大了....
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1922/problem/B