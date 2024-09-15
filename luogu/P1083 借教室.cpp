#include <iostream>
#include <cstring>
#define endl '\n'
#define int long long
using namespace std;

const int N = 1e6 + 10;
int a[N], d[N], s[N], t[N], day[N];
int n, m;

// 判断是否超过房间限制
bool judge(int mid)
{
    memset(day, 0, sizeof day);// day数组作为临时数组存储每次的结果
    // 差分
    for (int i = 1; i <= mid; i++)
    {
        day[s[i]] += d[i];
        day[t[i] + 1] -= d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        day[i] += day[i - 1];// 前缀和，用于还原差分
        if (day[i] > a[i]) return true;
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i] >> s[i] >> t[i];

    // 二分查找答案
    int l = 1, r = m;
    while (l < r)
    {
        int const mid = (l + r) >> 1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }

    if (r != m)
        cout << -1 << endl << r << endl;
    else
        cout << 0 << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1083