#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int p[N];

struct Edge {
    int x, y, t;
    Edge(int u, int v, int w) { x = u, y = v, t = w; }
    bool operator < (Edge & a) const { return a.t > t; }
};

int find(int x)
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;

    vector<Edge> a;
    for (int i = 0; i < m; i++)// 多了个等号WA了一发
    {
        int x, y, t;
        cin >> x >> y >> t;
        a.push_back(Edge(x, y, t));
    }

    sort(a.begin(), a.end());
    //cout << a[0].t << '\n';

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (find(a[i].x) == find(a[i].y)) continue;
        p[find(a[i].x)] = find(a[i].y);
        cnt ++, ans = max(ans, a[i].t);
    }

    if (cnt == n - 1) cout << ans << '\n';
    else cout << -1 << '\n';
    return 0;
}


// https://www.luogu.com.cn/problem/P1111