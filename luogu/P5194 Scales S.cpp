#include <iostream>
#define int long long// 数据可能超过int的最大值
//#define _LOCAL
using namespace std;

/*
 * 题目给出数据1000，但是从第3个砝码之后就是大于前两个之和，所以真正的数据范围只有四十多
 * 前面的数据较小，可能计算量过大
 * 所以从后面开始搜索，如果遇到前缀（就算全取都不会大于这个答案）和小于已经得到的答案就直接退出 剪枝
 * 同时从后面开始搜索，分为两种状态，选这个数和不选这个数
 * */

const int N = 1010;
int a[N], b[N];
int n, c;
int ans = 0;

void DFS(int index, int sum)// 倒着搜的下标和已经记录了的值
{
    ans = max(ans, sum);// 记录最大值

    if (index == 0) return ;

    // 剪枝
    if (sum + b[index] < ans) return ;

    // 两种选择，选这个数和不选这个数
    if (sum + a[index] <= c) DFS(index - 1, sum + a[index]);// 选这个数的话不能超过最大值c
    DFS(index - 1, sum);
}

signed main()
{
#ifdef _LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];// 前缀和
    }

    DFS(n, 0);// 倒着搜
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P5194