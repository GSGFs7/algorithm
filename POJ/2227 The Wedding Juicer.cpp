#include <iostream>
#include <queue>
using namespace std;

/*
 * 求一个不规则的凹陷处最多能蓄的水
 * 连通块，先将从最外层所有最高的排除在外，然后在去计算内部底地势的地方
 *
 * 题解：
 * 如果某个点比当前的点低，那么我就可以多盛（h-h'）单位的水（两个高度差）。
 * 为什么呢？因为我当前堆首已经满足是整个边界中的最小值了；这样一点水不可能从任何其他边界出去。
 * 更新答案后，我们再把拓展出去的点的高度标为当前的高度h并加入优先队列（因为这个点以后可能还能盛水）。
 * 还是没懂
 * */

struct node{
    int x, y, h;
    friend bool operator < (const node &a,const node &b)// 友元函数，让外部能够范围结构体内部元素？
    {
        return  a.h>b.h;
    }
};

const int N = 310;
int g[N][N];
bool st[N][N];
int const dx[4] = {0, 1, 0, -1};
int const dy[4] = {1, 0, -1, 0};
priority_queue<node> q;

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

/*    // debug
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << g[i][j] << ' ';
        cout << '\n';
    }*/

    for (int i = 1; i <= n; i++) {
        node const a = {i, 1, g[i][1]}, b = {i, m, g[i][m]};
        q.push(a), q.push(b);// 不知道为什么q.push((node){i, 1, g[i][1]})后h等于0，所以只好单独写出来
        st[i][1] = st[i][m] = true;
    }
    for (int i = 2; i < m; i++) {
        node const a = {1, i, g[1][i]}, b = {n, i, g[n][i]};
        q.push(a), q.push(b);
        st[1][i] = st[n][i] = true;
    }

    long long ans = 0;
    while (!q.empty())
    {
        node const now = q.top();
        q.pop();
        int const x = now.x;
        int const y = now.y;

        for (int i = 0; i < 4; i++)
        {
            int const xx = x + dx[i];
            int const yy = y + dy[i];

            if (xx < 1 || xx > n || yy < 1 || yy > m || st[xx][yy]) continue;
            st[xx][yy] = true;

            if (g[xx][yy] >= now.h) q.push((node){xx, yy, g[xx][yy]});
            else ans += now.h - g[xx][yy], q.push((node){xx, yy, now.h});// 相减的结果可能为正也可能为负
            // Why？

            //debug
/*            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                    cout << st[i][j] << ' ';
                cout << '\n';
            }
            cout << '\n';*/
        }
    }
    cout << ans << '\n';

    return 0;
}


// http://poj.org/problem?id=2227