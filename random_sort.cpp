#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

#define sort random_shuffle
using namespace std;
#define int long long

void solve() {
    // ranfom_shuffle()默认使用rand(), 随机效果可能不太好, 需要下面这行
    srand((unsigned)time(NULL));
    vector<int> a(1000000);
    iota(a.begin(), a.end(), 1);
    // sort(a.begin(), a.end());
    for (auto i : a) cout << i << '\n';
}

signed main() {
    freopen("1.in", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}