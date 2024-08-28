#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++)
        cin >> a[i];

    // 如果数列中全是负数，取最大值
    bool flag = false;
    for (int i = 0; i < n; i++)
        if (a[i] > 0) flag = true;
    if (!flag)
    {
        sort(a.begin(), a.end());
        cout << a.back() << endl;
        return ;
    }

    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i += 2)
        if (a[i] > 0) sum1 += a[i];
    for (int i = 1; i < n; i += 2)
        if (a[i] > 0)sum2 += a[i];
    cout << max(sum1, sum2) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}