#pragma GCC optimize(1)
#pragma GCC optimize(2)// 果然是STL导致的TLE
#pragma GCC optimize(3,"Ofast","inline")
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

int cases = 0;

void solve()
{
    cases ++;

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    std::copy(a.begin(), a.end(),s.begin());// s原数组
    sort(a.begin(), a.end());// a排序后的数组

    // dbg
    // for (auto i : a) cout << i << ' '; cout << endl;

    cout << "Case #" << cases << ": ";
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            int const mid = (l + r) >> 1;
            if (a[mid] >= s[i] * 2) r = mid;
            else l = mid + 1;
        }

        if (a[l] > s[i] * 2) l --;// 判断是否大于自身两倍
        if (a[l] == s[i]) l --;// 如果重复的话再减一位也还是这个数字
        if (l < 0) cout << -1 << ' ';// 判断是否无解
        else cout << a[l] << ' ';
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

// https://www.acwing.com/problem/content/4636/