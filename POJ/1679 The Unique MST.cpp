#include <cstdio>
#include <algorithm>
using namespace std;

/*
 * 问一个图的最小生成树是否是唯一的
 * Kruskal算法
 * 在计算的时候先将所有的相同权值的边预处理一遍，统计有多少个可能的连通分量
 * 在Kruskal算法运行的过程中统计实际的连通分量
 * 在运行完所有的权值后检查连通分量，如果不一样的话就表示重边，在相同的权值下有重边显然不止一个最小生成树
 * 借用这个关系既可以快速判断是否是唯一存在最小生成树
 * */

const int N = 1e5 + 10;
int f[N];

// 边
struct Edge
{
    int x, y, dist;
}a[N];

bool cmp(Edge x, Edge y)
{
    return x.dist < y.dist;
}

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].dist);

    sort(a + 1, a + m + 1, cmp);

    int num = 0;// 最小生成树中的值
    int sum1 = 0;// 预期连通分量
    int sum2 = 0;// 实际连通分量
    int tail = 0;// 相同权值的最大边界
    int ans = 0;// 权值
    int flag = true;// 是否有结果
    for (int i = 1; i <= m + 1; i++)
    {
        if (i > tail)// 如果轮到了一个新的权值，重新计算连通分量
        {
            if (sum1 != sum2)// 如果不同表示加边出现问题，重边？有环？
            {
                flag = false;
                break;
            }

            // 重新计算新的权值下的分量
            sum1 = 0;// 两个sum都需要重置
            for (int j = i; j <= m + 1; j++)// 向后推，m+1为了能够取到最后一个点
            {
                if (a[i].dist != a[j].dist)
                {
                    tail = j - 1;// 更新分界点
                    break;
                }
                if (find(a[j].x) != find(a[j].y)) sum1 ++;// 如果j位置的值不同，就可以预期一个连通分量
            }
            sum2 = 0;
        }

        if (i > m) break;
        // 不能改这里，会WA
        // 在最后计算完所有的数后需要再次检测连通分量是否匹配，在m后还需要一层循环（整这么复杂？）

        int const x = find(a[i].x);
        int const y = find(a[i].y);
        if (x != y && num != n - 1)// 加边
        {
            num ++;
            sum2 ++;// 实际连通分量
            f[x] = f[y];// 合并
            ans += a[i].dist;// 权值
        }
    }

    if (flag)
        printf("%d\n", ans);
    else
        printf("Not Unique!\n");
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    while (t --)
        solve();
    return 0;
}


// http://poj.org/problem?id=1679
// 424K	16MS