#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 * 题意：
 * 从1号点出发，看有几条路线能够到达一个没有出度的点  （搞了好久没明白）
 *
 * 利用拓扑排序，标记1号点的值为1，每个点的值就是从1号点到这个点的路径的方案数
 * 方法参见P1002 过河卒（标数法）
 * 最后统计出度为0的点的值即可
 * */

const int N = 1e5 + 10;
vector<int> edge[N], l;
int n, m, d[N], f[N], ans = 0;

inline void topoSort()
{
    queue<int> s;
    for (int i = 1; i <= n; i++)
        if (!d[i] && edge[i].size())// 单个点不计入答案，即没有入度和出度的点
            s.push(i), f[i] = 1;

    while (!s.empty())
    {
        int const x = s.front();
        s.pop();
        l.push_back(x);// 生成拓扑序列好像没什么用
        if (!edge[x].size()) ans += f[x];// 统计出度为0的点的值
        for (auto i : edge[x])
        {
            if (-- d[i] == 0) s.push(i);
            f[i] += f[x];// 标数法，这个点的值等于所有进入这个点的值之和
            // 必须放在if的外面，以传递自身的值到下一个点，因为一个点想要进入s队列就必须入度减为0，这个时候就统计完成了f的值
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        d[y] ++;
    }

    topoSort();

    cout << ans << endl;
    //for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    return 0;
}


// https://www.luogu.com.cn/problem/P3183