#include <bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_cxx;

/*
 * 给出一个数组，可以进行 (a[i]+a[j])/2 的计算(向下取整)，A使结果最大，b使结果最小，求前i个数的最终结果
 *
 * B要使结果最小，那么就只有一种方法，奇数+偶数，使最后的值减一
 * A要使结果最大，只能组织B减一
 * 因为A先手，最后只有如果存在两个奇数就会被A变成一个整数，所以以3为一个循环，有多少组3就减去多少
 * 如果最后剩下了1个奇数，A操作不了，B再次减一，最后结果就是
 * ans=sum-cnt/3-((cnt%3)&1)
 * */

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;

        if (x & 1) cnt ++;
        int res = sum - cnt / 3;

        if (i > 0)// 第一个奇数不可减一，无法操作
        {
            int k = cnt % 3;
            if (k & 1) res--;
        }

        ans.push_back(res);
    }

    for (auto i : ans) cout << i << ' ';
    cout << '\n';
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


// https://codeforces.com/contest/1916/problem/C