#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>    // iota的头文件
#include <set>
#include <vector>

using namespace std;
#define int long long

void debug(vector<int> m) {
#ifdef __LOCAL__
    for (auto i : m) cout << i << '\t';
#endif
}

/**
 * @brief 代码写这里!!!
 */
void solve() {
    int n;
    string s;
    cin >> n >> s;

    // 找出一个循环节中的所有数
    n = n % 10;
    vector<int> m;
    m.push_back(n);
    int k = 1;
    int temp = n;
    for (int i = 0; i < 10; i++) {
        // cout << temp << ' ' << n << '\n';
        temp = temp * n % 10;

        if (temp == m[0]) break;
        m.push_back(temp);
        k++;
    }

    // p消去循环
    int p = 0;
    for (auto i : s) {
        p = (p * 10 + i - '0') % k;
    }

    // 需要减去1，因为是循环的
    if (p)
        cout << m[p - 1] << '\n';
    else
        cout << m[k - 1] << '\n';

    // cout << "K:" << k << '\n';
    debug(m);
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
    cin >> t;
    while (t--)
        solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}


// https://www.lanqiao.cn/problems/17028/learning/?contest_id=177