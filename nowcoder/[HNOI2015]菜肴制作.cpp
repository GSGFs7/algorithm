#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
  给出n道菜, x必须先于y制作, 尽可能的从小到大排序, 求最后的序列

  思路:
    反过来的拓扑排序
    因为是需要从小到大排序, 小的数可能依赖后面大的数
    正向的拓扑排序没办法反向求出依赖的元素, 需要反过来
    从字典序最大的拓扑序开始找, 然后反向输出
    喵啊, 拓扑排序的正反有很大不同
*/

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> ans;
int inDegree[N];    // 入度
int n, m;

void topoSort() {
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.top();
        q.pop();

        ans.push_back(u);
        for (auto v : g[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }
}

void solve() {
    ans.clear();
    memset(&inDegree, 0, sizeof inDegree);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);    // 反向存图, 跑反方向的拓扑排序
        inDegree[u]++;
    }

    topoSort();

    if (ans.size() != n) return cout << "Impossible!\n", void();
    for (auto i = ans.rbegin(); i != ans.rend(); i++) cout << *i << ' ';
    cout << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://ac.nowcoder.com/acm/contest/26077/1003
// 2024年6月19日