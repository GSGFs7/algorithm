#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

/*
 * 给出硬币的面额，求至少需要多少仲硬币才可以从1到m所有的钱都可以支付
 * 
 * 贪心
 * */

const int N = 1e6 + 10;
int a[N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

//    ios::sync_with_stdio(false);
//    cout.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    a[n] = m;

    sort(a, a + n);

    if (a[0] != 1)
    {
        cout << "No answer!!!" << '\n';
        exit(0);
    }

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)// 从小到大找到最小的组合拼出m
    {
        while (sum < a[i + 1] - 1)
        {
            sum += a[i];
            ans ++;

            if (sum >= m)
            {
                cout << ans << '\n';
                exit(0);
            }
        }
    }

    cout << ans + 1 << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P2001
// 需要吸氧 全部十个测试点 567ms 1.88MB