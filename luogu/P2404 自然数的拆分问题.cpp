#include <bits/stdc++.h>
using namespace std;

/* 拆分自然数 */
// dfs板子
// 只需要记录一下上次取的值即可，保证后面的数不大于前面

const int N = 10;
int path[N];
int sum = 0;
int n;

void dfs(int cur, int last)
{
    if (sum == n && cur != 1)
    {
        cout << path[0];
        for (int i = 1; i < cur; i++) cout << '+' << path[i];
        cout << endl;
        return ;
    }

    for (int i = last; i <= n - sum; i++)
    {
        sum += i;
        path[cur] = i;
        dfs(cur + 1, i);
        sum -= i;
    }
}

int main()
{
    cin >> n;

    dfs(0, 1);

    return 0;
}


// https://www.luogu.com.cn/problem/P2404