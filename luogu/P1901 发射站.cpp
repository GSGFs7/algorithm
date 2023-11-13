#include <bits/stdc++.h>
using namespace std;

/*
 * 一个低的位置可以向高的位置发送能量
 * 可以传左右两边最近的高于自己的位置
 * 求最大获得的能量
 *
 * 利用单调队列，维护高度的单调性
 * 从栈底到栈顶依次从大到小
 * 1.如果加入的是一个较小的数：给栈顶传送能量，入栈
 * 2.如果相等：因为栈不可以随机访问，先弹出相同的，然后再给栈顶传能量，入栈，然后能量乘以2
 * 3.如果大于：前面的小的数被后面高的数遮挡，永远不可能访问直接弹出，然后给要入栈的数传入能量，入栈
 * */

const int N = 1e6 + 10;
int a[N], b[N];// a高度，b能量
int ans[N];

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty()) st.push(i); // 开始状态
        else if (a[st.top()] > a[i])    // 如果小于，直接入栈
        {
            ans[st.top()] += b[i];
            st.push(i);
        }
        else if (a[st.top()] == a[i])   // 如果相等，合并
        {
            st.pop();
            ans[st.top()] += b[i];
            st.push(i);
            b[i] *= 2;
        }
        else                            // 如果大于，弹出再入栈
        {
            while (!st.empty() && a[st.top()] < a[i]) ans[i] += b[st.top()], st.pop();
            if (!st.empty()) ans[st.top()] += b[i];// 别忘了这个，WA了一发还DEBUG了好久
            st.push(i);
        }
    }

    int m = 0;
    for (int i = 0; i < n; i++) m = max(m, ans[i]);
    cout << m << '\n';

    // debug
//    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    return 0;
}


// https://www.luogu.com.cn/problem/P1901