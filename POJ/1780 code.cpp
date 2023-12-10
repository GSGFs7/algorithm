//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#define int long long
using namespace std;

/*
 * 欧拉回路
 *
 * 对于长度为n-1的序列，通过加上一个数使其变成一个没出现过的数，前n-1可以看成点，最后一个数可以看成10条边
 * 将所有的点和线相连就可以构成一个欧拉图，需要不重复的输出每条边
 * 将点依次压入栈中，搜索下一个可以取得的值
 *
 * 用num[i]限制在单一起点所连出的边的数量，确保所连出的边不会重复
 * 会炸栈
 * */

const int N = 1e5 + 10;
int num[N];                 // num[v]为点v后加的数字，num[v]=0到9
int st_edge[10 * N], top_s; // 栈，用于存边，top_s表示栈顶
char st_ans[10 * N];        // 栈，用于存储序列结果，top_a表示栈顶
int top_a;                  // 栈顶
int n, m;                   // 点的数量

void no_dfs(int v)  // 模拟递归，递归搜索v后面的10条边（0到9），放入st_edge
{
    int edge;       // 边的值
    while (num[v] < 10) // 在点v(n-1位的序列)后面添加0到9构成10条边
    {
        edge = 10 * v + num[v]; // 边
        num[v] ++;              // 添加一次次数，防止重复
        st_edge[top_s ++] = edge;// 存入栈st_edge中，保证字典序
//        printf("%02lld->", v);
        v = edge % m;           // 更新起点为原来的终点，往下走，值为去掉第一位后的数（掐头）
//        printf("%02lld:edge=%03lld\n", v, edge);
    }
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    while (scanf("%lld", &n), n != 0)
    {
        int edge;
        top_s = top_a = 0;
        m = 1;
        for (int i = 0; i < n - 1; i++) m *= 10;// 点的数量，一共10*(n-1)个点
        for (int i = 0; i < m; i++) num[i] = 0; // 初始化使用状态

        no_dfs(0);                            // 先从起点0开始，递归0的10条边
        while (top_s)                           // 继续走
        {
            edge = st_edge[-- top_s];           // 取出边
            st_ans[top_a ++] = edge % 10 + '0'; // 边值的最后一位
            no_dfs(edge / 10);                // 边值的(n-1)位（去尾）
        }

        // printf会TLE？？
        for (int i = 1; i < n; i++) cout << "0";// 打印第1组数，即n个0
        while (top_a) cout << st_ans[-- top_a];// 打印其他组数，每组打印一位
        cout << '\n';
    }
    return 0;
}


// http://poj.org/problem?id=1780