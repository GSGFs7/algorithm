#include <iostream>
using namespace std;

/// 前缀和 && 差分
/*
 * 利用前缀和和差分节省计算次数
 * 不必每次都把范围里的数都计算一遍
 * */

const int N = 2e5 + 10;
int a[N];// 原数组，用于标记差分
int sum[N];// 前缀和数组，由原数组还原得到，只需计算一次
int ans[N];// 结果数组，储存答案的前缀和

int main()
{
    int n, m, k;
    cin >> n >> k >> m;
    for (int i = 0, l, r; i < n; i++)
        cin >> l >> r, a[l] ++, a[r + 1] --;

/*    for (int i = 90; i < 100; i++)
        cout << a[i] << ' ';
    cout << endl;*/

    /// 还原前缀和
    // 只需计算一次
    for (int i = 1; i < N; i++)
        sum[i] = sum[i - 1] + a[i];

/*    for (int i = 90; i < 100; i++)
        cout << sum[i] << endl;
    cout << endl;*/

    /// 计算符合条件的前缀和
    // 避免每次都计算一遍
    for (int i = 1; i < N; i++)
        if (sum[i] >= k) ans[i] = ans[i - 1] + 1;
        else ans[i] = ans[i - 1];

/*    for (int i = 90; i < 100; i++)
        cout << ans[i] << ' ';
    cout << endl;*/

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << ans[r] - ans[l - 1] << endl;
    }
    return 0;
}


// https://mirror.codeforces.com/problemset/problem/816/B