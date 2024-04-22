#include <iostream>
#include <vector>
#include <chrono>
#include <map>
#include <set>

using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    map<int, int> mp1, mp2;
    for (auto &i: a) cin >> i, mp1[i]++;// 记录次数
    for (auto &i: b) cin >> i, mp2[i]++;

    // 按照出现的次数加入set
    set<int> s1, s2, s3;
    for (auto i: mp1) {
        if (i.second == 1) s1.insert(i.first);
        if (i.second == 2) s2.insert(i.first);
    }
    for (auto i: mp2) {
        if (i.second == 2) s3.insert(i.first);
    }

    vector<int> ans1, ans2;
    for (int i = 0; i < k; i++) {
        if (s1.size() > 1) {// 出现一次
            int x = *s1.begin();
            s1.erase(s1.begin());
            int y = *s1.begin();
            s1.erase(s1.begin());
            ans1.push_back(x);
            ans1.push_back(y);
            ans2.push_back(x);
            ans2.push_back(y);
        } else {// 如果没了
            int x = *s2.begin();
            s2.erase(s2.begin());
            int y = *s3.begin();
            s3.erase(s3.begin());
            ans1.push_back(x);
            ans1.push_back(x);
            ans2.push_back(y);
            ans2.push_back(y);
        }
    }

    for (auto i: ans1) cout << i << ' ';
    cout << '\n';
    for (auto i: ans2) cout << i << ' ';
    cout << '\n';
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
//    cout << duration.count();
    return 0;
}


// https://codeforces.com/contest/1944/problem/B