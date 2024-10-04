#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个数组，可以将整个数组向右循环位移k个位置，每次将结果与当前值相与
  问需要多少此可以使整个数组全部变成0
*/

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 跑环，由0往后跑，也就是反向推出前面最近的0的位置
    vector<int> step(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            int now = i;
            while (!step[(now + d) % n] && a[(now + d) % n]) {
                step[(now + d) % n] = step[now] + 1;
                now = (now + d) % n;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, step[i]);
        if (a[i] && !step[i]) return cout << -1 << '\n', void();
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1579/problem/F
// 2024-09-19