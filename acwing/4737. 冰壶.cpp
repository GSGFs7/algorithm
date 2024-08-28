#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/* 一道入门题卡了一个晚上 */

const int N = 20;
int a[N], b[N];
int Case = 0, cnt1 = 0, cnt2 = 0;

void solve()
{
    Case ++;
    memset(&a, 0, sizeof a);
    memset(&b, 0, sizeof b);
    cnt1 = cnt2 = 0;

    int n, m, h, s;
    cin >> h >> s;
    int r = a[0] = b[0] = (h + s) * (h + s);// 顺带初始化a,b不然等于0

    int x, y;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x >> y, a[i] = x*x + y*y;
    cin >> m;
    for (int i = 0; i < m; i++) cin >> x >> y, b[i] = x*x + y*y;

    sort(a, a + n);
    sort(b, b + m);

    int res1 = 0, res2 = 0;
    while (a[res1] <= b[0] && res1 < n && a[res1] <= r) res1 ++;// 因为a和b不相等所以不用担心另一个值为1
    while (b[res2] <= a[0] && res2 < m && b[res2] <= r) res2 ++;

    cout << "Case #" << Case << ": " << res1 << ' ' << res2 << endl;
/*    for (auto i : a) if (i) cout << i << ' ';
    cout << endl;
    for (auto i : b) if (i) cout << i << ' ';
    cout << endl;*/
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/description/4740/