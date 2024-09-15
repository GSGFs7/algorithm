// 字典序最小拓扑序列
// 很简单，只需要用堆来维护S集合即可  (set或priority_queue)
// 时间复杂度为O(nlogn+m)，堆的时间复杂度为logn，需要插入n次，每条边只需要枚举一次时间复杂度为m

#include <iostream>
#include <set>
#include <queue>
using namespace std;

const int N = 1e4 +10;
priority_queue<int> pq;// 优先队列需要加负号
set<int> s;// set不用
vector<int> edge[N];
vector<int> l;
int n, m, d[N];

inline void topoSort()
{
    for (int i = 1; i <= n; i++)
        if (d[i] == 0) pq.push(-1 * i);

    while (!pq.empty())
    {
        int const x = -1 * pq.top();
        pq.pop();
        for (auto i : edge[x])
            if (-- d[i] == 0) pq.push(-1 * i);
        l.push_back(x);// 其实直接输出即可，不用存下来
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        d[y] ++;
    }

    topoSort();

    for (auto i : l) cout << i << ' ';
    return 0;
}