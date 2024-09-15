#include <iostream>
using namespace std;

/// 单调栈
/*
 * 利用单调性
 * 当后面有一个数比栈顶小的时候，那么这个数就永远都不会被用到，直接弹出
 * 再将刚刚那个数插入到栈顶，用这个数继续更新后面的数
 * 因为从栈底到栈顶是严格单调上升的，所以叫单调栈
 * */

const int N = 1e5 + 10;
int stk[N];

int main()
{
    int n;
    cin >> n;
    int tt = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt--;
        stk[++ tt] = x;// 插入x

        // 输出（如果需要的话）
        if (stk[tt - 1]) cout << stk[tt - 1] << ' ';
        else cout << - 1 << ' ';
    }
    return 0;
}


// https://www.acwing.com/problem/content/description/832/