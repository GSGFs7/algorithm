



// STL作弊解法
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
int a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    nth_element(a, a+k, a+n);
    // nth_element()函数可以将范围内第k小的数放在k的位置上
    cout << a[k];
    return 0;
}
 */