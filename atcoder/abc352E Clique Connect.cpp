#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

/*
  给出一个图, 接下来每次给出k个点, 这些点两两之间有一条权值为c的边, 求这个图的最小生成树

  思路:
    Kruscal板子
    这道题完美符合Kruscal的运行步骤, 妙啊~
    Kruscal 每次添加最短的边, 添加边的点都加入同一个并查集来判断是否相连
    如果有点超过一组并查集也就表示这道题无解(不连通)
    因为每次加入的都是最小的边权的边, 这样所有边权相加得到的值也就是最小生成树的权值
    正好题目给出的也是每个点, 来表示两两间是否有边, 直接按照按照边权从小到大来划分并查集
    并查集最大的操作也只有插入N个点, 完美符合数据范围
    直接在合并的同时累加边权即可
*/

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int N = 2e5 + 10;
int f[N];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) f[i] = i;

    priority_queue<piii> pq;
    while (m--) {
        int k, c;
        cin >> k >> c;
        int s;
        cin >> s;
        for (int i = 1; i < k; i++) {
            int x;
            cin >> x;
            pq.push({-c, {s, x}});
        }
    }

    long long ans = 0;
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        int c = now.first;
        int u = now.second.first;
        int v = now.second.second;
        int fu = find(u);
        int fv = find(v);
        if (fu != fv) {
            f[fu] = fv;    // 折腾了半天, 又是并查集写错了
            ans -= c;
            // cout << c << '\n';
        }
    }
    // cout << ans << '\n';

    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += i == f[i];
    if (cnt == 1) cout << ans << '\n';
    else cout << -1 << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://atcoder.jp/contests/abc352/tasks/abc352_e
// 2024年5月6日