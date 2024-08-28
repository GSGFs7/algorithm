#include <iostream>
#include <queue>
using namespace std;

/*
 * 顺序不影响结果
 * 2~9和5~11可看成2~5和5~11
 * 只需要在加上一条线段之后在检查一下下一条线段是否重复，如果是就减去重复的部分，让终点为下一条线段的起点然后下一条线段接上，可保证不重不漏
 * */

priority_queue<int, vector<int>, greater<>> s, e;

int main()
{
    int n;
    cin >> n;
    for (int i = 0, l, r; i < n; i++)
        cin >> l >> r, s.push(l), e.push(r);

    int ans = 0;
    while (!s.empty() && !e.empty())
    {
        ans += e.top() - s.top();
        // cout << s.top() << ' ' << e.top() << endl;
        s.pop();
        if (!s.empty() && s.top() < e.top()) ans -= e.top() - s.top();
        e.pop();
    }
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1496