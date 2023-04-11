#include <iostream>
using namespace std;

void solve()
{
    int a, b, n;
    cin >> a >> b >> n;
    long long sum = 0;
    if (n <= 2)
    {
        cout << b * n << endl;
        return ;
    }
    if (a > b)
    {
        for (int i = 0; i < n; i++)
            sum += b;
        sum += (long long)((n - 1) / 2) * (a - b);
    }
    else
    {
        for (int i = 0; i < n; i++)
            sum += b;
    }

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


// https://mirror.codeforces.com/gym/104303/problem/B