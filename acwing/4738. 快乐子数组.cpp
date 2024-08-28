#include <iostream>
using namespace std;

/*
 * 前缀和+单调栈
 * 
 * 不会
 * */

typedef long long LL;
const int N = 4e5 + 10, INF = 1e9;
int stk[N];// 单调栈
LL A[N], B[N];
int cases = 0;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        A[i] = A[i - 1] + x;// 前缀和
        B[i] = B[i - 1] + (LL)x * (n - i);// 预处理前缀和，先处理出这个点要被加的次数在乘上x，等差数组相对高度不变，区间内的值也不会变
    }

    LL res = 0;
    int top = 0;// 栈顶
    A[n + 1] = -INF;// 末尾设置为无穷大
    stk[++ top] = n + 1;

    /// 单调栈
    for (int i = n; i >= 0; i --)
    {
        while (A[stk[top]] >= A[i]) top --;// 大于当前元素，删掉
        int const j = stk[top];// 右边第一个小的数
        stk[++ top] = i;
        res += B[j - 1] - B[i] - (A[j - 1] - A[i]) * (n - j);
    }

    cout << "Case #" << ++ cases << ": " << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/4741/