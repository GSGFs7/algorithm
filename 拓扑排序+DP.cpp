/*
 * 给出一个基础值（每个值都不小于这个值），和图中的大小关系，求图中的顶点的最小值
 * 拓扑排序+DP
 * 先拓扑排序一遍，再根据大小关系求DP
 * */

#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

const int N = 1e4 + 10;
int n, m, d[N], f[N];
vector<int> edge[N];

inline int topoSort()
{
    queue<int> s;
    vector<int> l;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0) s.push(i);

    while (!s.empty())
    {
        int const x = s.front();
        s.pop();
        for (auto i : edge[x])
            if (--d[i] == 0) s.push(i);
        l.push_back(x);
    }

    /// DP
    for (int i = n; i; i--)// 求最小值，倒着求
    {
        int const x = l[i - 1];// l数组是从0开始的
        f[x] = 100;// 基础值为100
        for (auto j : edge[x])
            f[x] = max(f[x], f[j] + 1);// 对于每个点，不能小于题目要求的基础值和他要大于的那个数
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += f[i];
    return ans;
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

    cout << topoSort() << endl;
    return 0;
}