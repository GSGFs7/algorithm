#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>    // iota的头文件
#include <vector>

using namespace std;
#define int long long

void debug() {
#ifdef __LOCAL__

#endif
}

bool cmp(string a, string b) {
    return a + b < b + a;
}

/**
 * @brief 代码写这里!!!
 */
void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &i : s) cin >> i;

    sort(s.begin(), s.end(), cmp);

    for (auto i : s) cout << i;
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}


// https://www.lanqiao.cn/problems/17035/learning/?contest_id=177