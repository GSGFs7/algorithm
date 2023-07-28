#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;

// 不能以n的因数作为循环
void solve()
{
    int n;
    cin >> n;
    int k = 2;
    for (int i = 2; i <= n; i++)// 为什么不能i <= n / i
        if (n % i) { k = i;
            break; }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%c", 'a' + cnt ++);
        if (cnt == k) cnt = 0;
    }
    puts("");
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://codeforces.com/problemset/problem/1844/D