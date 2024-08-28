#include "bits/stdc++.h"

using namespace std;
#define int long long

/*
 * 给出n组a,b,c，求最多有多少组数相加，出现一边大于其他两边之和
 *
 * 贪心
 * 想要保证两边和不小于第三边，就直接按最最小权值排序，这样依次取到的就是最大取值数
 * */

int n;

int find(vector<int> x, vector<int> y, vector<int> z)
{
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        s[i] = x[i] - y[i] - z[i];

    sort(s.begin(), s.end(), greater<>());

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += s[i];
        if (sum <= 0) return i;// 再往后就会大于他们了
    }
    return n;
}

void solve()
{
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    for (auto& i : c) cin >> i;
    int res = max({find(a, b, c), find(b, a, c), find(c, a, b)});// max初始化列表
    cout << (res ? res : -1);
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/description/4968/