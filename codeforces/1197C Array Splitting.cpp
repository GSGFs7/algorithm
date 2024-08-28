#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 当k=3时sum最小为a[n-1]-a[j+1]+a[j]-a[i+1]+a[i]+a[0]
 * a[n-1]和a[0]固定，要使sum最小只能使切点两端数值差最大
 * */

const int N = 3e5 + 10;
int a[N];
int s[N];

int main()
{
    int n, k;
    cin >> n >> k;
    cin >> a[0];
    for (int i = 1; i < n; i++)
        cin >> a[i], s[i] = a[i] - a[i - 1];

    sort(s, s + n);

    long long ans = a[n-1] - a[0];
    for (int i = n - 1, cnt = k - 1; cnt > 0 && i >= 0; i--, cnt --)
        ans -= s[i];

    cout << ans << endl;
    return 0;
}


// https://www.codeforces.com/contest/1197/problem/C