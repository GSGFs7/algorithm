//#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

/*
 * 并查集
 * 带权并查集
 *
 * 食物链，环形结构，用距离表示的话看模3余几就能够表示两个生物间的三种状态
 * 在路径压缩时顺带处理每条边的权值，需要递归求解
 * */

const int N = 50010;
int p[N], d[N];

int find(int x)
{
    if (x != p[x]) {// 如果还没搜到祖宗节点
        int const t = find(p[x]);// 记录下来祖宗节点
        d[x] += d[p[x]];// 父节点到祖宗节点的距离加上这个点到父节点的距离
        // 递归调用，直到得到最后的结果，所以当程序执行到这一步时，父节点到祖宗节点的距离也已经求出来了
        // 需要先递归得到从祖宗节点开始的答案才能继续，所以要先递归再赋值
        p[x] = t;// 赋值为祖宗节点
    }
    return p[x];
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) p[i] = i;// 初始化，每个值的祖宗节点都是自己

    int ans = 0;
    while (m--)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);// de了好久结果发现根本没有读入
        if (x > n || y > n) { ans ++; continue; }

        int const px = find(x), py = find(y);// 两个点的祖宗节点
        if (op == 1)// 同类
        {
            if (px == py)
            {
                if ((d[x] - d[y]) % 3) ans ++;// d[x]与d[y]可能是正数也可能是负数
            }
            else// 要不属于同一个集合才建立联系
            {
                p[px] = py;// 是p[px]直接表示祖宗节点，不然p[x]表示的是父节点
                d[px] = d[y] - d[x];//
            }
        }
        else// 天敌
        {
            if (px == py)
            {
                if ((d[x] - d[y] - 1) % 3) ans ++;
            }
            else
            {
                p[px] = py;
                d[px] = d[y] - d[x] + 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}


// https://www.acwing.com/problem/content/242/
// http://poj.org/problem?id=1182                   // 在poj会TLE，Y总代码过了，是scanf的原因😎👌😭