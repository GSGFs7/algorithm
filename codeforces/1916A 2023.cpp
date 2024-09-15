#include <bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_cxx;

/*
 * 有一个乘积为2023的数组，给出其中一部分，求剩下的那部分
 *
 * 如果存在这样一个数组的话，必须符合下面两个条件
 * 1.给出的所有数相乘不会超过2023，如果超过必定无解
 * 2.2023/mul不会存在小数（整除）
 * */

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int mul = 1;
    bool flag = false;
    for (auto i : a)
    {
        cin >> i;
        mul *= i;
        if (mul > 2023) flag = true;
    }

    if (flag) return cout << "NO\n", void();

    if (2023 % mul == 0)// 如果能被整除
    {
        cout << "YES\n";
        cout << 2023 / mul << ' ';
        for (int i = 1; i < k; i++) cout << 1 << ' ';
        cout << '\n';
    }
    else cout << "NO\n";// 如果存在小数点
}

signed main(){
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1916/problem/A