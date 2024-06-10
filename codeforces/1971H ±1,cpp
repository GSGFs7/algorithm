#include <bits/stdc++.h>

using namespace std;

/*
  给出一个3*n的矩阵, 可以将其中绝对值相同的数分别替换成1和-1, 求是否存在方案使排序后中间那一行全为1

  思路:
    2-SAT板子
    要求的是中间那一行是否存在一种全部为1的方法, 排序后小的值去全在上面
    也就是说三个值中允许一个值为负, 再同一列中至少需要有两个值符合条件(不能相互冲突)
    扩大到整个数组也就是需要每一列至少满足有两个值不冲突
    直接把所有的冲突的值两两相连看是否会冲突, 如果冲突就表示不存在
*/

const int N = 1e5 + 10;
int a[3][N];
vector<int> g[N];
int dfn[N];
int low[N];
int scc[N];
int cnt = 1;
int id = 1;
stack<int> st;

// 塔扬强连通
void tarjan(int u) {
    dfn[u] = low[u] = id++;
    st.push(u);

    for (auto v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!scc[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        ++cnt;
        while (true) {
            int v = st.top();
            st.pop();
            scc[v] = cnt;
            if (u == v) break;
        }
    }
}

void debug(int n) {
#ifdef __LOCAL__
    for (int i = 1; i <= n * 2; i++) cout << scc[i] << ' ';
#endif
}

void solve() {
    int n;
    cin >> n;
    // 初始化
    for (int i = 0; i <= n * 2; i++) {
        scc[i] = dfn[i] = low[i] = 0;
        g[i].clear();
    }
    cnt = id = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            // 如果是负数就看成相反的条件
            if (a[i][j] < 0) a[i][j] = abs(a[i][j]) + n;
        }
    }

    // 开始建图
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 3; k++) {
                if (i == k) continue;
                // 设置为相反的条件, a[k][j]写成a[i][k]卡了好久...
                if (a[i][j] <= n) g[a[i][j] + n].push_back(a[k][j]);
                else g[a[i][j] - n].push_back(a[k][j]);
            }
        }
    }

    // 求出所有点的强连通
    for (int i = 1; i <= n * 2; i++) {
        if (!dfn[i]) tarjan(i);
    }

    debug(n);

    // 如果和自己的反条件同时出现
    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[i + n]) {
            return cout << "No\n", void();
        }
    }
    cout << "Yes\n";
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


// https://codeforces.com/contest/1971/problem/H
// 2024年5月15日