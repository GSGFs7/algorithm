#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int p[N];

// 寻找根节点，路径压缩
int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        p[find(a)] = find(b);
        // 原本是p[a]=find(b)过不了，因为a可能是另一个并查集的节点，这样的话就只会合并a，正解需要将整个并查集合并
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (p[i] == i) ans ++;

    cout << ans << '\n';
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://acm.hdu.edu.cn/showproblem.php?pid=1213