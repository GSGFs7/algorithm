#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
pair<string, int> a[N];
pair<int, int> b[N];
int cnt = 0;

void solve()
{
    cnt ++;
    int n;
    cin >> n;
    string colour;
    int durability;
    int uid;
    for (int i = 0; i < n; i++)
    {
        cin >> colour >> durability >> uid;
        a[i] = {colour, uid};
        b[i] = {durability, uid};
    }

    // sort()可以直接根据前后的值进行排序
    sort(a, a + n);
    sort(b, b + n);

    int ans = 0;
    cout << "Case #" << cnt << ": ";
    for (int i = 0; i < n; i++) if (a[i].second == b[i].second) ans ++;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/4675/