#include <iostream>
#include <stack>
#include <vector>

/*
  2-SAT
  给出n个集合, 每个集合都有两个元素, 给出若干个限制条件<a,b>, 使a与b相互矛盾
  然后从每个集合中选择一个元素, 判断是否能选择n个两两不矛盾的元素

  解法:
    给所有不能同时出现的情况连一条边, 用边的关系来表示两者的关系
    然后跑tarjan来查找强连通分量, 同一个强连通图中的元素都是相互可达的
    也就是说同一个强连通图中的元素都是不能同时出现的
    如果一个集合中的所有元素都在同一个强连通图出现, 就说明这个集合不可能有共存的情况
*/

using namespace std;
const int N = 4e6 + 10;
struct Edge {
    int to, next;
} e[N];
int head[N];
int tot = 1;

void add(int u, int v) {
    e[++tot] = {v, head[u]};
    head[u] = tot;
}

int dfn[N];
int low[N];
int scc[N];
int cnt = 1;
int id = 1;
stack<int> st;

void tarjan(int u) {
    dfn[u] = low[u] = id++;
    st.push(u);

    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
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

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;    // 第a个数为x,第b个数为y 或是 第a个数为y,第b个数为x
        cin >> a >> x >> b >> y;
        // 前n个数表示1, 后n个数表示0
        if (x == 0 && y == 0) {    // 如果第a个数为0或第b个数为0
            add(a + n, b);         // a=1则b=0
            add(b + n, a);         // b=1则a=0
        } else if (x == 0 && y == 1) {
            add(a + n, b + n);    // 如果a=1则b=1
            add(b, a);            // 如果a=0则b=0
        } else if (x == 1 && y == 0) {
            add(a, b);            // 如果a=0则b=0
            add(b + n, a + n);    // 如果b=1则a=1
        } else if (x == 1 && y == 1) {
            add(a, b + n);    // 如果a=0则b=1
            add(b, a + n);    // 如果b=0则a=1
        }
    }

    // 给每个点都跑一遍tarjan算法求强连通
    for (int i = 1; i <= n * 2; i++) {
        if (!dfn[i]) tarjan(i);
    }

    // 如果两个元素同时出现在强连通图中
    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[i + n]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    // 反之就有方案
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; i++) {
        if (scc[i] > scc[i + n]) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
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


// https://www.luogu.com.cn/problem/P4782
// 2024年4月17日