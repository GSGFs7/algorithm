#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N];

int c(int k, int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= k) r = mid;
        else l = mid + 1;
    }
    if (a[l] != k) return -2;
    return l;
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    while (m--)
    {
        int k;
        cin >> k;
        cout << c(k, 0, n - 1) + 1 << " ";
    }
    return 0;
}

// https://www.luogu.com.cn/problem/P2249