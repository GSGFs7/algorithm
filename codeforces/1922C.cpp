#include <iostream>
#include <vector>

using namespace std;
#define int long long

const int N = 1e5 + 10;
int a[N], d[N], sum1[N], sum2[N];

void solve() {
    int n;
    cin >> n;
//    vector<int> a(n + 1);
//    vector<int> d(n + 1);// 方向，0向左，1向右
//    vector<int> sum1(n + 1);// 前缀和，向右
//    vector<int> sum2(n + 1);// 前缀和，向左
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 方向
    d[1] = 1, d[n] = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] - a[i - 1] < a[i + 1] - a[i]) d[i] = 0;
        else d[i] = 1;
    }

    // 前缀和
    sum1[1] = 0;
    for (int i = 1; i <= n; i++) {
        sum1[i + 1] = sum1[i] + (d[i] ? 1 : a[i + 1] - a[i]);
//        cout << i << '_' << sum1[i] << " \t";
    }
//    cout << '\n';
    sum2[n] = 0;
    for (int i = n - 1; i >= 1; i--) {
        sum2[i] = sum2[i + 1] + (d[i + 1] ? a[i + 1] - a[i] : 1);
//        cout << i << '_' << sum2[i] << " \t";
    }
//    cout << '\n';

    int m;
    cin >> m;
    while (m --) {
        int x, y;
        cin >> x >> y;
        int ans;
        if (x < y) {
            ans = sum1[y] - sum1[x];
        } else {
            ans = sum2[y] - sum2[x];
        }
        cout << ans << '\n';
    }
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


// https://codeforces.com/contest/1922/problem/C