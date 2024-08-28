#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;
#define int long long

/*
 给出两个数组, 判断前一个是否是后一个的子数组
*/ 

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < n && idx2 < m) {
        while (a[idx1] != b[idx2]) {
            idx2 ++;
            if (idx2 == m) return cout << "No", void();
        }
        idx1 ++;
        idx2 ++;
    }

    if (idx1 == n) cout << "Yes";
    else cout << "No";
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
    // cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/description/2818/
// 2024年3月20日