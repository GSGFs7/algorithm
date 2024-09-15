/*
 * 拓扑排序(Topological Sorting, TopoSort)
 * 对一个有向无环图(DAG)的每个顶点进行线性排序，对于u->v排序后u在v前面
 * 每个顶点只会出现一次
 * 一个有向无环图可能有多个拓扑排序的结果
 *
 * 解决：
 *  1.用L记录到目前为止的拓扑序列，用S记录所有不在L中的入度为0的顶点，首先遍历顶点，加入入度为0的点到S
 *  2.当S不为空时：
 *      在S中取一个顶点x加入L的队尾，并从S中删去x   （任取一个）
 *      遍历从x出发的边x->y删掉这条边，如果y的入度变成0就加入y到S中
 *  3.循环结束时，如果所有点都加入L中就表示找到了一个合法的拓扑序列，否则表明存在环   (a->b->c->a，拓扑排序无法入手)
 *
 * L，S一般用同一个队列维护，指针加一S中的元素就加入L中
 * 时间复杂度O(n+m)
 * */
// 入度：所有指向这个点的数量
#include <iostream>
#include <vector>
using namespace std;

const int N = 10010;
vector<int> edge[N];
int n, m, d[N], q[N];

inline bool topoSort()
{
    int hh = 1, tt = 0;// 队头和队尾
    for (int i = 1; i <= n; i++)
        if (d[i] == 0) q[++ tt] = i;// 如果入度本来就是0直接加入集合S

    while (hh <= tt)
    {
        int const x = q[hh ++];// 拿到队头
        for (auto i : edge[x])
            if (--d[i] == 0) q[++ tt] = i;// 删除队头的相连边
    }
    return tt == n;
    /* 更直观的写法
    vector<int> l;
    queue<int> s;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0) s.push(i);

    while (!s.empty())
    {
        int x = s.front();
        s.pop();
        for (auto i : edge[x])
            if (-- d[i] == 0) s.push(i);
        l.push_back(x);
    }
    return l.size() == n;
     */
}

int main()
{
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        d[y] ++;
    }

    if (topoSort()) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}