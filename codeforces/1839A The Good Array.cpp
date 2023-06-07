#include <iostream>
using namespace std;

/*
 * 最后一个必须放1
 * 第k必须为1
 * 需要1+(n/k)向上取整
 * */

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << 2 + (n - 2) / k << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// https://codeforces.com/problemset/problem/1839/A