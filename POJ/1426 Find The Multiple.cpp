//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stdlib.h>
#define int long long
using namespace std;

/*
 * 求一个由1和0组成的十进制数能够被n整除，随便一个
 * 用BFS将最小值加入，每次都将两种可能加入队尾，求出的即为最小值
 *
 * 用DFS也能做
 * */

int n;

// DFS写法
bool flag = true;// 用于退出
void DFS(int u, int now)
{
    if (u > 18) return ;

    if (now % n) flag = false;

    if (flag)
    {
        DFS(u + 1, now * 10);
        DFS(u + 1, now * 10 + 1);
    }
}

void BFS()
{
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int const now = q.front();
        q.pop();

        if (now % n == 0) { cout << now << endl; break; }

        q.push(now * 10);
        q.push(now * 10 + 1);
    }
}
signed main()
{
    while (true) {
        cin >> n;
        if (!n) exit(0);

        BFS();
    }
}


// http://poj.org/problem?id=1426