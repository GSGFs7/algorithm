#include <iostream>
#include <queue>
#define int long long
using namespace std;

/*
 * 定义两个大根堆一个存储原数组，另一个存储它们的和
 * 再用他们的和尝试还原原数组，如果可以还原那么结果为真
 * */

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    priority_queue<int> a, b;// 一个用于存放原来的值，另一个用来还原
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        sum += x;
        a.push(x);
    }
    b.push(sum);

    bool flag = true;
    while (!a.empty() && !b.empty() && flag)
    {
        if (a.top() == b.top()) a.pop(), b.pop();// 如果这个值被还原
        else if (a.top() > b.top()) flag  = false;
        else
        {
            int const x = b.top();
            b.pop();
            if (x % 2) b.push(x / 2), b.push(x / 2 + 1);
            else b.push(x / 2), b.push(x / 2);
        }
    }
    if (flag) puts("YES");
    else puts("NO");
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.codeforces.com/problemset/problem/1654/C