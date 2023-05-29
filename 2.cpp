#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int a[N];
int b[N];

void k(int n)
{
    swap(b[n], b[n - 1]);
    if (a[n] + b[n] < a[n - 1] + b[n - 1])
        k(n - 1);
}

void solve()
{
    memset(&b, false, sizeof b);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        b[i] = i;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] + i > a[i + 1] + i + 1)
            k(i - 1);
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << ' ';
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