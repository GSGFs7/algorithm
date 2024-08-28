#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出一个数组，求数组中某个连续区间的 奇数位置的数相加 与 偶数位置的数相加 是否相等
 * 如果两者之差是0会导致计算过程中的某个数复现
 * */
// 喵啊

void solve()
{
    int n;
    cin >> n;
    vector<int> a, b;// 奇数和偶数
    map<int, int> mp;// 哈希表
    int sum = 0;
    bool flag = false;
    mp[0] = 1;// 0已经出现过一次了
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i & 1)
        {
            b.push_back(x);
            sum -= x;
        }
        else
        {
            a.push_back(x);
            sum += x;
        }
        if (mp[sum]) flag = true;// 如果一个数重复出现，那就代表中间有个值奇偶之差为0，说明找到了符合的答案
        mp[sum] = 1;
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1915/problem/E