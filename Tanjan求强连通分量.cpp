#include <bits/stdc++.h>
#define int long long
using namespace std;

/// Tarjan
/*
 * Tarjan(塔扬)算法
 * 使用并查集来统计每个点所属的强连通分量
 *
 * 强连通
 * 有向图节点两两相互可达
 * 强连通分量(SCC)
 * 极大的强连通子图
 *
 * 使用DFS向下搜索，到一个点就打上dfn(时间戳)和low(低点)
 * 并根据low来更新相连的其他节点，类似回溯的方法向上寻找，如果能找到的就说明是相互可达的，也就是强连通
 * 妙啊~
 *
 * DFS搜索产生一棵搜索树
 * 搜索树的四类边
 *  1.树边: DFS访问节点经过的边
 *  2.返祖边: 指向祖先节点的边
 *  3.横叉边: 右子树指向左子树的边
 *  4.前向边: 指向子树中节点的边
 * 返祖边与树边必构成环, 横向边可能与树边构成环, 前向边无用
 *
 * 处理子节点的时候可能出现两种情况
 *  1.下一个节点没有被访问这个时候就只能靠回溯来更新这个点了
 *  2.下一个节点是已经访问过的，那么这个点就可以直接更新自己的low，更新完直接返回
 *  （需要注意的是，这个点不能是已经划分了强连通分量的，如果是划分了的就表明他也不会与另一边发生关联）
 *  如: x--x  x--x
 *     |  |  |  |
 *     x--x--x--x
 *  最下面那个路径是没有用处的(当然，要将上图看成有向图，因为有向图不好画)
 * 
 * 栈的用处，相同批次的强连通分量会一起出栈，也就是这些出栈的值属于同一个强连通分量
 * */

const int N = 10000 + 10;
int n, m;
vector<int> g[N];       // 邻接表
int dfn[N], low[N];     // 时间戳和低点
int id;                 // 节点编号
int st[N], top;         // 栈
int scc_num[N], cnt;    // 所属的强连通分量

void dfs(int u) {
    // low值表示当前点能抵达的最DFS序最小的点
    dfn[u] = low[u] = ++id;    // 最开始每个点的dfn和low都是编号
    st[++top] = u;             // 入栈

    // 强连通的搜索
    for (auto i : g[u]) {
        if (!dfn[i]) {    // 找到一个没有被访问过的字节点(找返祖边)
            dfs(i);
            low[u] = min(low[u], low[i]);
            // 回溯，这个点的值是不会大于自己的子节点的
            // 如果下一个点小于自己就表示找到了一个强连通分量，更新(也就是返祖边)
        } else if (!scc_num[i]) {    // 如果这个点已经被搜索过了，但不是已知的强连通分量
            // 那这个点可能是横叉边，更新low进行回溯
            low[u] = min(low[u], dfn[i]);
            // 这里貌似可以用是否处在在栈中的状态来优化(好像也优化不了多少)
        }
    }

    // 记录强连通分量
    // 如果这个点是的强连通分量的起点 或是 单独的强连通分量
    if (dfn[u] == low[u]) {
        cnt++;            // 强连通分量的计数
        while (true) {    // 出栈，如果是同一批次出栈的就说明是同一个强连通分量
            int i = st[top--];
            scc_num[i] = cnt;
            // 可以再加一个siz数组记录大小
            // siz[cnt]++;
            if (u == i) break;    // 如果回到了起点
        }
    }
}

void solve() {
    // 初始化
    memset(&dfn, 0, sizeof dfn);
    memset(&low, 0, sizeof low);
    memset(&scc_num, 0, sizeof scc_num);
    for (int i = 1; i <= n; i++) g[i].clear();
    id = top = cnt = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);

        //        cout << a << ':'; for (auto j : g[a]) cout << j << ' '; cout << '\n';
        //        for (auto i : g) i.clear();   这个东西有问题，清不掉原来的数据，改成上面那样就可以了
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i);

    // 这个忘记屏蔽了...
    //    for (int i = 1; i <= n; i++) cout << dfn[i] << ' '; cout << '\n';
    //    for (int i = 1; i <= n; i++) cout << low[i] << ' '; cout << '\n';

    if (cnt > 1)
        cout << "No\n";
    else
        cout << "Yes\n";
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    while (cin >> n >> m && (n || m)) solve();
    return 0;
}


// https://acm.hdu.edu.cn/showproblem.php?pid=1269