#include <iostream>
#include <cstring>
using namespace std;

// 选择的数尽量向后靠，让前方留出更多的不减IQ的数

const int N = 1e5 + 10;
int a[N];
bool b[N];

void solve()
{
    int n, q;
    cin >> n >> q;
    memset(b, false, sizeof b);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q1 = 0;// 从后往前的IQ
    int i;
    for (i = n - 1; i >= 0 && q1 < q; i--)
    {
        if (a[i] > q1) q1 ++;
        b[i] = true;
    }

    // 处理前面的
    for (; i >= 0; i--)
        if (a[i] <= q) b[i] = true;

    for (i = 0; i < n; i++)
        cout << b[i];
    puts("");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1707/problem/A