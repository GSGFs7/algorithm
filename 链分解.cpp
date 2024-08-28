#include <iostream>
#include <vector>

using namespace std;

/*
  链分解
  树链剖分的一个必要的操作
  利用dfs搜索的性质, 将一棵树分解为若干条不重叠的链
  dfs搜索只有走到尽头才会返回, 直接用dfs的性质, 每一次连续的dfs都是连续的链
  开始新dfs的时候就是新的链, 并且新开的这个点就是链顶

  普通链分解的顺序依赖数据输入的顺序, 这样随机的分解可能复杂度并不优秀
    如: 毛毛虫形状的图
  需要引入轻重链来进行优化

  对于图论题目, 造数据时存在伸展度t的概念
    表示图中边的最大长度, 小的t就会出现类似毛毛虫图, 大的t就会出现类似菊花图
    大但是又不够大, 小菊花图相连
    1.单链
    2.纯随机
    3.菊花
    4.毛刺单链 
    5.若干菊花相连
  解决方法: 轻重树链剖分
*/

const int N = 1e5 + 10;
vector<int> g[N];
vector<int> chain[N];
int top[N];

// x表示当前节点, tp表示当前点的链顶
void dfs(int x, int tp) {
    top[x] = tp;
    chain[tp].push_back(x);    // 加入到链中, 一般调试用
    for (int i = 0; i < g[x].size(); i++) {
        // 如果是这个点的第子节点就继续, 如果不是的话就表明已经用过这个点了
        dfs(g[x][i], i ? g[x][i] : tp);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    dfs(1, 1);

    cout << "Top:\n";
    for (int i = 1; i <= n; i++) {
        cout << top[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; i++) {
        if (!chain[i].empty()) {
            cout << "Chain: " << i << '\n';
            for (auto j : chain[i]) cout << j << ' ';
            cout << '\n';
        }
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

/*
8
1 2
1 3
2 4
2 5
2 6
5 7
7 8
*/
