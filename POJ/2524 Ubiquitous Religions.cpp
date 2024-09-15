#include <iostream>
using namespace std;

const int N = 5e4 + 10;
int p[N];
int cases = 1;

/// 寻找祖宗节点
int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);// 带路径压缩
    return p[x];
}

/// 初始化
inline void init(int n)
{
    for (int i = 1; i <= n; i++) p[i] = i;
}

/// 统计答案
inline int cnt(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (p[i] == i) cnt ++;
    return cnt;
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    while (cin >> n >> m, n && m)
    {
        init(n);

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            p[find(a)] = find(b);// 合并
        }

        cout << "Case " << cases ++ << ": " << cnt(n) << '\n';
    }
    return 0;
}


// http://poj.org/problem?id=2524