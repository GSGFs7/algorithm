#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int>> rk(26);
    for (int i = 0; i < 26; i++) rk[i] = {0, i};           // 初始化
    for (int i = 0; i < n; i++) rk[s[i] - 'a'].first++;    // 计数

    sort(rk.begin(), rk.end(), greater());    // 从大到小

    int div = 1;
    int ans = 1e9;
    for (int i = 1; i <= 26; i++) {    // 枚举最后剩下多少个字符
        if (n % i) continue;           // 如果不能这样分

        int x = n / i;    // 每一份的个数
        int delta = 0;
        // Δ之和
        for (int j = 0; j < i; j++) delta += max(0, rk[j].first - x);
        // 如果还有没有算进来的数
        for (int j = i; j < 26; j++) delta += rk[j].first;

        // 最小的花费
        if (delta < ans) {
            ans = delta;
            div = i;
        }
    }

    // 推出目标字符串
    int cnt = n / div;
    vector<pair<int, int>> pos(26);
    for (int i = 0; i < 26; i++) pos[rk[i].second] = {rk[i].first, i};
    for (int i = 0; i < n; i++) {
        if (pos[s[i] - 'a'].first > cnt
            || pos[s[i] - 'a'].second >= div && pos[s[i] - 'a'].first) {
            pos[s[i] - 'a'].first--;
            for (int j = 0; j < 26; j++) {
                if (pos[j].first < cnt && pos[j].second < div) {
                    s[i] = j + 'a';
                    pos[j].first++;
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
    cout << s << '\n';
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


// https://codeforces.com/contest/1782/problem/C
// 2024年5月25日