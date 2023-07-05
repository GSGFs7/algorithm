#include <iostream>
using namespace std;

/*
 * 求以某一个点结尾的最长递增子串
 * 四舍五入就是求前缀和
 * */

const int N = 2e5 + 10;
int cases = 0;
int f[N];

void solve()
{
    cases ++;
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) f[i] = 1;
    for (int i = 1; i < n; i++)
        if (s[i - 1] < s[i]) f[i] = f[i - 1] + 1;

    cout << "Case #" << cases << ": ";
    for (int i = 0; i < n; i++)
        cout << f[i] << ' ';
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://www.acwing.com/problem/content/3751/