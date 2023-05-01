#include <iostream>
using namespace std;

// 思维题 思路清晰就能过

// a可以向后移动
// c可以向前移动
// b作为中间值不参与过程
// a c相遇则不可能继续下去

void solve()
{
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int b1 = 0, b2 = 0;// 先统计b的个数，
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'b') b1 ++;
        if (s2[i] == 'b') b2 ++;
    }

    if (b1 == b2)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == 'b') continue;
            while (s2[cnt] == 'b') cnt ++;
            // 匹配条件：
            // s2中的数必须向后搜索到a或者c，如果是c退出
            // a只能向后运动
            // c只能向前运动
            if ((s1[i] != s2[cnt]) || (s1[i] == 'a' && i > cnt) || s1[i] == 'c' && i < cnt)
            {
                puts("NO");
                return ;
            }
            cnt ++;
        }
    }
    else { puts("NO"); return ; }
    puts("YES");
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1697/problem/C