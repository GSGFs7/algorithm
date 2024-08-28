#include "bits/stdc++.h"
#define int long long
using namespace std;

/*
 * 给出n个城市和m条路，每个城市都可以买一辆速度为s[i]自行车，求1到n花费的最小时间（也就是说可能存在绕路买更快的自行车的情况）
 *
 * 1~n，单源最短路，dijkstra时间复杂度O(nlogn)
 * 可能会有n中不同的速度到达n点，那么，对每一种速度经行一次dijkstra
 * dis[i][j]距离用二维数组表示，i表示1到这个点花费的时间，j表示是在s[j]的速度下的
 * 1000个点，时间复杂度为O(n*n*logn)属于10^6级(好像是10^7了)
 * 在进行dijkstra时因为要使时间花费最小，直接用小根堆，优先处理最小的时间花费，最后的结果也是最小的（可以证明）
 * 这样，直接计算完成后打上标记，下次就不需要再用相同的速度访问这个点了，反正不会比他快
 * */

typedef pair<int, int> PII;
const int INF = 1e18;
const int N = 1010;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<PII> g[n];
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x --, y --;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }
    vector<int> s(n);
    for (auto& i : s) cin >> i;

    // dis[i][j]的i表示第几个点，j表示在哪种速度下达到的（有DP那味了）
    vector<vector<int>> dis(N, vector<int>(N, INF));// 花费的时间
    vector<vector<bool>> st(N, vector<bool>(N, false));// 是否以这个速度得到最优解
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q;// 第一个数表示优先级，第二个数表示点，第三个数表示速度
    q.push({0, 0, s[0]});
    dis[0][s[0]] = 0;
    while (!q.empty())
    {
        int u = q.top()[1];// 当前边
        int speed = q.top()[2];// 速度
        q.pop();

        // debug
//        cout << u << ' ' << speed << '\n';

        if (st[u][speed]) continue;// 如果已经有最优解了
        st[u][speed] = true;

        for (auto i : g[u])
        {
            int ne = i.first;// 下一个点
            int d = i.second;// 到下一个点的距离
            int fast = min(speed, s[ne]);// 如果可以拿较小的速度肯定拿较小的
            if (dis[ne][fast] > dis[u][speed] + d * speed)// 基础花费+距离*原来的速度（新的速度要抵达下一个点才能使用）
            {
                dis[ne][fast] = dis[u][speed] + d * speed;
                q.push({dis[ne][fast], ne, fast});// 用时间花费来排序
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= 1000; i++)
        ans = min(ans, dis[n - 1][i]);
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://codeforces.com/contest/1915/problem/G