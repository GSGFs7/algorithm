#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
 * 给出数组求数组划分成k份后最小值
 * 每份的最小值为数组间的差值相加
 *
 * 求出每个差值，直接减去最大的即可
 * */

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long sum = 0;
    vector<int> b(n, 0);
    for (int i = 1; i < n; i++)
        b[i] = abs(a[i] - a[i - 1]), sum += b[i];

    sort(b.begin(), b.end(), greater());
    //for (auto i : b) cout << i << ' ';

    for (int i = 0; --k; i++) sum -= b[i];// 划分i-1次，所以是--k
    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/problemset/problem/1847/A