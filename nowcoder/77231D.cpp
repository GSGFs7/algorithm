#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <queue>

using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (*s.begin() > *(s.end() - 1)) cout << *s.begin();
    else cout << *(s.end() - 1);
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
//    cout << duration.count();
    return 0;
}


// https://ac.nowcoder.com/acm/contest/77231/D