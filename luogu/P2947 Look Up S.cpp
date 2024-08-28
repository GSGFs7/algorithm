#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 单调栈板子
 *
 * 求这个位置向右看，最高是那个位置
 * 从左往右存在单调的特性（取最近的大于自己的数）
 * 可以使用单调栈从右往左依次加入，当前位置的最大值都会被依次记录
 * （好像直接拿个变量存也是一样的？好吧，不行，要选择最近的那个）
 * */

const int N = 1e5 + 10;
int a[N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    stack<int> stack1;          // 记录单调栈
    vector<int> ans(n + 1);
    for (int i = n; i > 0; i--)
    {
        while (!stack1.empty() && a[stack1.top()] <= a[i]) stack1.pop();
        if (stack1.empty()) ans[i] = 0; // 如果前面的数都没有这个大
        else ans[i] = stack1.top();     // 如果找到了一个比自己大的就立刻停止
        stack1.push(i);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P2947