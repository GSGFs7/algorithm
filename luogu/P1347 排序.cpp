#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出两个点的关系，求在加入第几个数时可以连成一串，如果冲突直接输出
 * 通过邻接矩阵统计入度，利用入度进行拓扑排序，如果最大长度达到n就表明达到了题目的要求
 * 数据范围 2≤n≤26,1≤m≤600 直接暴力拓扑排序即可
 *
 * 第一种情况：
 *  可以找到稳定的拓扑排序
 * 第二种情况：
 *  图中存在环
 * 第三种情况：
 *  无法连通
 * */

const int N = 30;
int n, m;
int a[N][N];// 邻接矩阵
int r[N];   // 每个点的入度
int f[N];   // 最长链
int q[N];   // 队列
int t, h;   // 队尾,队头
int su;     // 最长链的长度

void tp(int x)
{
    for (int i = 1; i <= n; i++)
        if (a[x][i] == 1 && r[i] > 0)
        {
            r[i] --;// 入度减1
            f[i] = max(f[i], f[x] + 1);// 更新最长长度
            su = max(su, f[i]);// 更新最长链的长度

            if (r[i] == 0)
                q[++t] = i;
        }
}

signed main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        int const x = s[0] - 'A' + 1;
        int const y = s[2] - 'A' + 1;
        a[x][y] = 1;

        // 如果矛盾(自环)
        if (x == y) return printf("Inconsistency found after %lld relations.", i), 0;

        // 统计入度
        memset(&r, 0, sizeof r);
        for (int j = 1; j <= n; j++)
        {
            f[j] = 1;// 初始化最长链长
            for (int k = 1; k <= n; k++)
                r[k] += a[j][k];
        }

        // 找到入度为0的值
        t = 0;
        for (int j = 1; j <= n; j++)
            if (!r[j])// 入度为0，入队
                q[++t] = j;

        // 拓扑排序
        h = 0, su = 0;
        while (h < t)
        {
            h ++;
            tp(q[h]);
        }

        // 如果能够一条链全部连同所有点
        if (su == n)
        {
            printf("Sorted sequence determined after %lld relations: ", i);
            for (int j = 1; j <= n; j++)
                printf("%c", q[j] + 64);
            printf(".\n");
            return 0;
        }

        // 如果连通关系出现问题
        bool flag = true;
        for (int j = 1; j <= n; j++)
            if (r[j]) flag = false;
        if (!flag)
        {
            printf("Inconsistency found after %lld relations.", i);
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.");// 如果连不起来
    return 0;
}


// https://www.luogu.com.cn/problem/P1347