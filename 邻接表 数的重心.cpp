/* 图：
 * 有向图
 * a -> b
 * 无向图
 * a - b
 * a -> b
 * a <- b
 *
 * 有向图：
 * 邻接矩阵 g[a][b] a->b   空间复杂度O(n^2)
 * 邻接表(单链表，类似拉链法的哈希表) 储存直接指向的点，与次序无关
 * 1: 4 -> 2 -> 3 -> -1
 * 2: 3 -> -1
 * 如图
 *      4
 *      ^
 *      |
 * 2 <- 1 -> 3
 * |---------^
 *
 * */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = N * 2;
int n;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = N;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 以u为根的子数中点的数量
int dfs(int u)
{
    st[u] = true;

    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;
    return 0;
}


// https://www.acwing.com/problem/content/848/

// 模板
/*
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    st[u] = true;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}

int main()
{
    memset(h, -1, sizeof h);

    dfs(1);
}
 */