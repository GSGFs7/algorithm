#include <iostream>
#include <vector>
using namespace std;

/* 前缀和快速统计距上个点的距离，前后各一遍再取最小值就可得出答案 */

const int MAX_N = 0x3f3f3f3f;
int cases = 0;
bool flag;

void solve()
{
    int n;
    cin >> n;
    getchar();// 吃掉换行
    vector<int> f(n + 1);// 前
    vector<int> b(n + 1);// 后

    /// 前
    flag = true;
    for (int i = 1, c; i <= n; i++)
    {
        c = getchar();
        if (flag && c == '0') { f[i] = MAX_N; continue; }// 不知道前面是多少直接取最大值，交给另一边去算
        else flag = false;

        if (c == '1') f[i] = 0;
        else f[i] = f[i - 1] + 1;
    }

    // debug
    //for (int i = 1; i <= n; i++) cout << f[i] << ' '; cout << endl;

    /// 后
    flag = true;
    for (int i = n; i > 0; i--)
    {
        if (flag && f[i]) { b[i] = MAX_N; continue; }
        else flag = false;

        if (!f[i]) b[i] = 0;
        else b[i] = b[i + 1] + 1;
    }

    // debug
    //for (int i = 1; i <= n; i++) cout << b[i] << ' '; cout << endl;

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(f[i + 1], b[i + 1]);
    printf("Case #%d: %lld\n", ++ cases, ans);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/4117/