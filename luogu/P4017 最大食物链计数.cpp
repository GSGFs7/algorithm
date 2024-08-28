#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

/*
 * 求入度为0的点到出度为0的点的路径的方案数
 * 类似 P3183 食物链
 * */

const int N = 5010;
vector<int> edge[N];
int n, m, d[N], f[N];
long long ans = 0;
int mod = 80112002;

inline void topoSort()
{
    queue<int> s;
    vector<int> l;
    for (int i = 1; i <= n; i++)
        if (!d[i] && edge[i].size())// 入度为0且有出度（不为孤立的点）
            s.push(i), f[i] = 1;

    while (!s.empty())
    {
        int const x = s.front();
        s.pop();
        l.push_back(x);
        if (!edge[x].size()) ans += f[x], ans %= mod;// 统计出度为0的点
        for (auto i : edge[x])
        {
            if (-- d[i] == 0) s.push(i);
            f[i] += f[x];// 传递自身的值到下一个点
            f[i] %= mod;
        }
    }

}

int main ()
{
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++)// 写成了i<n，调了好久...
    {
        cin >> x >> y;
        edge[x].push_back(y);
        d[y] ++;
    }
/*
    cout << "---debug---" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "--" << i << "--" << endl;
        for (auto j : edge[i])
            cout << j << ' ';
        cout << endl;
    }
*/

    topoSort();

    cout << ans << endl;
    return 0;
}