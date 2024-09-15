#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出n对(l,r)和n个权值，l之间可以随意排序，r和权值也是，求最小权值
 *
 * 由于l和r的总距离是不变的，权值的变化是由分配引起的，那么只要把大的距离分给小的权值，把小的距离分给大的权值就可以了
 * 为什么我就想得这么复杂
 *
 * 关于的大差值部分，暴力是0(n!)，肯定不能是暴力
 * 可以选一个r，对于这个r而言将会有多个符合条件的值，取最小的那个
 * 因为r可能会抢掉前面数的值如(1,2)和(3,4)，所以r只能从最小的开始向后推
 * 得到差值后相乘就可以了
 * */

void solve()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n), c(n);
    for (auto& i : l) cin >> i;
    for (auto& i : r) cin >> i;
    for (auto& i : c) cin >> i;
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());

    vector<int> num(n);
    stack<int> st;
    int ll = 0;
    for (int i = 0; i < n; i++)// 在允许的条件下得到最大的差值
    {
        while (ll < n && r[i] > l[ll])// 以一个右边界找前面的符合条件的左边界
        {
            st.push(l[ll]);// 压入栈中
            ll ++;
        }

        // 翻转，得到最大差值
        int x = st.top();
        st.pop();
        num[i] = r[i] - x;
    }

    // 得到的差值大小不确定（但能肯定最大），重新再排序
    sort(num.begin(), num.end(), greater());

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += num[i] * c[i];// 大的权值分给小的，小的分给大的，取最小值
    cout << ans << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int start = clock();

    int t;
    cin >> t;
    while (t--)
        solve();

//    cout << clock() - start << '\n';
    return 0;
}


// https://codeforces.com/contest/1909/problem/C