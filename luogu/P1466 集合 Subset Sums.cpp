#include <iostream>
using namespace std;

/*
 * DP
 * 选与不选，状态表示
 * 根据题意，将f[i][j]定义为在前i个数中背包容量为j时的最大值
 * 列出状态转移方程
 * 因为存储的时方案数，所以需要继承上一个不取就已经满足的数f[i-1][j]的同时再加上新取的数f[i-1][j-a[i]]
 * */

const int N = 50, M = 10000;
int f[N][M], a[N];

int main()
{
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2) cout << 0 << endl, exit(0);// 必须为偶数
    for (int i = 1; i <= n; i++) a[i] = i;

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= a[i]) f[i][j] += f[i - 1][j - a[i]];
        }
    cout << f[n][sum / 2] << endl;
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum / 2; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
     */
    return 0;
}


// https://www.luogu.com.cn/problem/P1466