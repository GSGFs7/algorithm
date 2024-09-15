#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

/*
 * 最大子段和
 * 动态规划
 * b[i]表示以a[i]结尾的值可取得的最大值
 * 如果b[i-1]为负就重新开一个数，取当前步的最大值
 * 如果b[i-1]为正就加上a[i]，即为以a[i]结尾的最大答案
 * */

const int N = 2e5 + 10;
int a[N], b[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = -1 * INF;
    for (int i = 0; i < n; i++)
    {
        if (b[i - 1] > 0)// 每步取最大值，如果为负就不必继续
            b[i] = b[i - 1] + a[i];
        else
            b[i] = a[i];
        ans = max(ans, b[i]);// 取每步中最大的答案
    }
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1115