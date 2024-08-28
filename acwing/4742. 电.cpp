#include <iostream>
#include <cstring>
using namespace std;

/*
 * DP
 * 记忆化搜索
 * 电力只能从电容大的传向电容小的
 * 数据结构为树形拓扑结构，每个子节点互不相连
 * 只要先求出子节点的值就可以推出其父节点的值
 * 通过记忆化完成
 * */

const int N = 2e5 + 10, M = N << 1;
int c[N];
int e[M], ne[M], h[N], idx;
int f[N];
int cases = 0;

/// 建立连接
void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx ++;// 类似单链表
}

/// 记忆化搜索
int dp(int u)
{
    if (f[u] != -1) return f[u];

    int res = 1;
    for (int i = h[u]; ~i; i = ne[i])// 寻找下一个节点
    {
        int const j = e[i];
        if (c[u] > c[j]) res += dp(j);
    }
    f[u] = res;
    return res;
}

void solve()
{
    // 初始化
    memset(&h, -1, sizeof h);
    memset(&f, -1, sizeof f);
    idx = 0;
    cases ++;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 0, x, y; i < n - 1; i++)
        cin >> x >> y, add(x, y), add(y, x);// 双向图

    int res = 0;
    for (int i = 1; i <= n; i++)// 枚举每个节点进行搜索
        res = max(res, dp(i));// 取得最大值

    cout << "Case #" << cases << ": " << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}