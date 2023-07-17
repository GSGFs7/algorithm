#include <bits/stdc++.h>

/*
 * 将前缀降序或者将后缀升序
 *
 * */

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
PII stk[N];
int ans[N];

int main()
{
    int n, m;
    cin >> n >> m;
    int top = 0;
    while (m --)
    {
        int p, q;// 操作和下标
        cin >> p >> q;

        if (p == 0)// 前缀降序操作
        {
            // 如果栈非空，并且也是前缀操作
            while (top && stk[top].first == 0) q = max(q, stk[top --].second);// 配合后方的压栈函数，取最大值
            // 如果这次的操作范围比之前的都要大，那么直接和并小的范围
            while (top >= 2 && stk[top - 1].second <= q) top -= 2;
            stk[++ top] = {0, q};
        }
        else if (top)
        {
            // 取最大范围的后缀操作
            while (top && stk[top].first == 1) q = min(q, stk[top --].second);
            // 看是否比前面的大
            while (top >= 2 && stk[top - 1].second >= q) top -= 2;
            stk[++ top] = {1, q};
        }
    }

    // 从两端缩小范围，倒着填入数字
    int l = 1, r = n, k = n;
    for (int i = 1; i <= top; i++)
    {
        if (stk[i].first == 0)
            while (r > stk[i].second && l <= r) ans[r --] = k --;
        else
            while (l < stk[i].second && l <= r) ans[l ++] = k --;
        if (l > r) break;
    }

    // 如果只填完了一边
    if (top % 2)// 如果是奇数，只填完了右区间
        while (l <= r) ans[l ++] = k --;
    else// 如果是偶数，只填完了左区间
        while (l <= r) ans[r --] = k --;

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}


// 蓝桥杯2021省B
// https://www.acwing.com/problem/content/description/3422/
// https://www.luogu.com.cn/problem/P8747