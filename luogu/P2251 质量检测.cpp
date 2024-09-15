#include <bits/stdc++.h>
#define int long long
using namespace std;

// 单调队列模板题

const int N = 1e6 + 10;
int a[N], q[N]; // a[]存储原数组，q[]存储单调队列中的值

void debug(int head, int tail)
{
    for (int i = head; i <= tail; i ++)
        cout << a[q[i]] << ' ';
    cout << '\n';
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int head = 0, tail = -1;
    for (int i = 1; i < m; i++)
    {
        while (head <= tail && a[q[tail]] >= a[i]) tail --; // 队尾弹出比当前值要大的数，保证队列单调
        q[++ tail] = i; // 加入这个元素，如果前面曾经存在比这个数小的数，也会被上一步弹出，依旧可以保持单调性
    }
    for (int i = m; i <= n; i++)
    {
        while (head <= tail && a[q[tail]] >= a[i]) tail --;
        q[++ tail] = i;
        while (i - q[head] >= m) head ++;   // 如果超过了队列的大小限制，弹出队头
        cout << a[q[head]] << '\n';
//        debug(head, tail);
    }
    return 0;
}


// https://www.luogu.com.cn/problem/P2251