#include <iostream>
#include <deque>
#include <queue>
#define endl '\n'
using namespace std;

const int N = 1e5 + 10;
int primes[N], cnt = 0;
bool st[N];

void get_primes()
{
    for (int i = 2; i <= N - 1; i++)
    {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= (N - 1) / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

bool check(int x)
{
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) return false;
    return true;
}

// 怎样排序使得 MEX(l,r)为质数的个数 最大
void solve()
{
/*
    5 2 1 4 3


    5 2 1 6 4 3
    4 4 4 0 0 0 = 12;
    5 2 1 4 3
    2 3 3 0 0 = 8;
    2 1 4 3
    3 3 0 0 = 6;
    2 1 3
    1 2 0 = 3;
    */

    int n;
    cin >> n;
    vector<int> a, b, c, d;
    c.push_back(1);
    bool flag = true, flag2 = false;
    for (int i = 2; i <= n; i++)
    {
        if (check(i))
        {
            if (flag) a.push_back(i), flag = false;
            else b.push_back(i), flag = true;
        }
        else
        {
            if (flag2) c.push_back(i), flag2 = false;
            else d.push_back(i), flag2 = true;
        }
    }

    int len = a.size();
    for (int i = len - 1; i >= 0; i--) cout << a[i] << ' ';
    len = c.size();
    for (int i = len - 1; i >= 0; i--) cout << c[i] << ' ';
    for (auto i : d) cout << i << ' ';
    for (auto i : b) cout << i << ' ';
    cout << endl;
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