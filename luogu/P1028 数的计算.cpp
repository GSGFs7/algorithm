#include <iostream>
using namespace std;

// 思维题
// 第i个结果的个数等于1到i/2的所有结果加自己
/*
 * 6        ---1
 * 6 1      ---a[1]
 * 6 2      ---a[2]
 * 6 2 1    ---a[2]
 * 6 3      ---a[3]
 * 6 3 1    ---a[3]
 * ----------------------------------
 * a[n] = 1 + a[1] + a[2] + ... + a[n>>2];
 * */

int a[1010];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            a[i] += a[j];
        }
        a[i]++;
    }
    cout << a[n];
    return 0;
}