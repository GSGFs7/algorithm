#include <bits/stdc++.h>
#define int long long
using namespace std;

/// 单调队列，注意读题
/*
 * 给出每个人的高度，问有多少对人可以相互看见
 * 高的人会挡住矮的人，存在单调性
 * 利用单调性，因为是一对一对计算的，只需要计算一个方向就可以了
 *
 * 注意读题：
 * 原文：队列中任意两个人a和b，如果他们是相邻或他们之间没有人比a或b高，那么他们是可以互相看得见的。
 * 依旧是说8 7 5中，因为7比5大，8和5就不算，之前我的理解因为是要比他们两个都要高
 * 因此，简单的单调栈就可以解决
 *  在非空的栈内添加就加一，弹出就表示比两个都矮，弹出后加一，如果相等合并后加一
 *
 * 从前到后依次将所有人压入栈中
 * 1.如果为空直接压入，没有任何一对人可以相互看见
 * 2.如果加入一个比栈顶小的数，直接入栈，增加一个次数
 * 3.如果加入一个和栈顶相等的数，为了维护栈的单调性，合并为一个，下次处理时多计算一次
 * 4.如果加入一个比栈顶大的数，先弹出所有大的数，每弹出一个数就增加一次计数
 * */

typedef pair<int, int> PII;

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n;
    cin >> n;

    stack<PII> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        PII p = {h, 1}; // 初始化
        while (!st.empty() && st.top().first <= h)  // 不是小于栈顶就会破坏单调性，需要处理
        {
            ans += st.top().second;

            if (st.top().first == h) p.second += st.top().second;// 等于的情况也合并到里面来

            st.pop();
        }

        if (!st.empty()) ans ++;// 如果前面有人，加进来的这个人就可以和他说话
        st.push(p);
    }

    cout << ans << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1823
// 全部23个测试点  1.29s /  808.00KB