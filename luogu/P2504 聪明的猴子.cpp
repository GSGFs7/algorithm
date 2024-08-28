#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 给出猴子最大跳跃距离和几个二维点，求有多少猴子能够抵达每棵树
 * 最小生成树
 *
 * 先将所有的两两点相连，然后最小生成树，看最长边长小于多少猴子
 *
 * 最小生成树算法：Kruskal算法
 * 从小到大排序所有的边，然后依次遍历
 * 如果不属于同一个集合就划为同一个集合
 * 直到最后所有点都在同一个集合中算法结束
 * */

const int N = 1010, M = 1e6 + 10;// M是1000的平方，两两相连大概有M*M/2条边
int l[N];// 猴子的最大距离
int px[N], py[N];
int fa[N];

struct edge
{
    int i, j;// i和j表示px和py中的节点编号，相当于是起点和终点
    double dist;
}e[M];
int cnt = 0;// 用于edge计数

bool cmp(edge a, edge b)
{
    return a.dist < b.dist;
}

// 寻找根节点
int find(int x)
{
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> l[i];

    cin >> m;
    for (int i = 0; i < m; i++) cin >> px[i] >> py[i];

    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
        {
            e[cnt].i = i;// 两条边的端点
            e[cnt].j = j;
            e[cnt].dist = sqrt((px[i] - px[j]) * (px[i] - px[j]) + (py[i] - py[j]) * (py[i] - py[j]));// 距离
            cnt ++;
        }

    sort(e, e + cnt, cmp);
//    cout << e[0].dist << '\n';

    /// 初始化有问题，需要将所有的点全部初始化，卡了一个晚上
    for (int i = 0; i < m; i++) fa[i] = i;// 最大可能有1000个点，需要给每个点上一个不同的记号（标记根节点）

    int cnt1 = 1;
    double len = 0;// 最大距离
    for (int i = 0; i < cnt; i++)
    {
        if (find(e[i].i) != find(e[i].j))
        {
            fa[find(e[i].i)] = find(e[i].j);// 并查集合并
            cnt1 ++;
            len = max(len, e[i].dist);

//            cout << e[i].i << ' ' << e[i].j << '\n';
        }

        if (cnt1 == m) break;// 如果全部加入集合中
    }

//    cout << len << '\n';
    int ans = 0;
    for (int i = 0; i < n; i++) if (l[i] >= len) ans ++;
    cout << ans << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P2504