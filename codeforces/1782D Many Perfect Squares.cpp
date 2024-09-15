#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
  给出一个数组, 求一个x, 使a[i]+x是某个数平方的数量最多

  思路:
    math~
    首先, 这题至少存在一个数满足题目要求
    但是存在两个数的情况呢? 未必存在
    直接从两个数的状况开始向后推, 如果连两个数的状况都不存在的话后面也就不用看了
    先可以枚举所有的二元组, 得到他们的x, 然后开始找其他数是否符合这个x
    (思路瞬间就简单起来了)

    对于找数的处理:
        设 a[i]+x=p^2, a[j]+x=q^2
        相减得到 a[j]-a[i]=q^2-p^2=(q+p)(q-p)
        也就是说 q-p 整除 a[j]-a[i]
        只需要找出这个整除的数就能间接得到x
    现在, 任何通过 a[j]-a[i] 的值推出两个p,q这两个数?
        设 q-p 的值为 d (暴力枚举出 q-p 的值)
        列出下面等式:
            q-p=d
            q+p=(a[j]-a[i])/p
        得到两者的关系:
            p=((a[j]-a[i])/d-d)/2
            q=((a[j]-a[i])/d+d)/2

    我讨厌推公式!
*/

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // check里面必须要整数乘, 不然会混进17返回true这样的怪东西
    auto check = [&](int x) { return x == (int)sqrt(x) * sqrt(x); };

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sub = a[j] - a[i];
            for (int d = 1; d * d <= sub; d++) {
                if (sub % d) continue;

                int p = (sub / d - d) / 2;
                int q = (sub / d + d) / 2;
                // x为正数, a[i]和a[j]加上x不可能比p和q的平方小
                if (p * p < a[i] || q * q < a[j]) continue;

                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (check(a[k] + (p * p - a[i]))) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << '\n';
    // cout << check(17) << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1782/problem/D
// 2024年5月27日