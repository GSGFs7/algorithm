#include <bits/stdc++.h>
using namespace std;

/*
 * 给出n个点，有s次机会将两个点不花费权值相连，求全连后权值至少要多大（求最大权值）
 * 瓶颈生成树，这个我也不知道是什么
 * 难度：普及/提高−
 * 直接暴力Kruskal算法，再求最大的权值可解
 * 注意合并时是 f[find(e[i].x)]=find(e[i].y);  需要先找到根节点
 * */

const int N = 510;
int f[N];
int siz[N];

struct Edge
{
    int x, y;
    double z;
}a[N], e[N * N];
int cnt = 0;// e[]数组的计数变量

inline double getDist(Edge x, Edge y)
{
    return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}

bool cmp(Edge x, Edge y)
{
    return x.z < y.z;
}

int find(int x)
{
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

// 按秩合并？ 改了这个就AC了
void Union_Set(int x, int y){
    x = find(x), y = find(y);
    if (x == y) return;

    if (siz[x] < siz[y]) f[x] = y;
    else if (siz[x] > siz[y]) f[y] = x;
    else {
        f[x] = y;
        siz[y] ++;
    }
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int s, n;
    cin >> s >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            e[cnt].x = i;
            e[cnt].y = j;
            e[cnt].z = getDist(a[i], a[j]);
            cnt ++;
        }

    sort(e, e + cnt, cmp);
//    cout << e[0].z << '\n';

    double ans = 0;
    int t = 0;
    for (int i = 0; i < N; i++) f[i] = i;
    for (int i = 0; i < cnt; i++)
    {
        if (t == n - s) break;

        if (find(e[i].x) != find(e[i].y))
        {
            Union_Set(e[i].x, e[i].y);
//            f[e[i].x] = find(f[e[i].y]);// 这个会WA，不知道为什么
            // 明白了，应该是f[find(e[i].x)] = find(f[e[i].y);需要直接改根节点，这里错了N次了
            t ++;

            ans = max(ans,e[i].z);
            cout << e[i].z << " " <<  i << '\n';
        }
    }

    printf("%.2lf", ans);
    return 0;
}


// https://www.luogu.com.cn/problem/P1991