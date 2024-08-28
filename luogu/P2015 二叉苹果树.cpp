#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * 树形DP
 * 一棵二叉树，每根枝条上都有苹果，求保留最后几条后剩下的最大数量的苹果
 *
 * 边的DP处理过于复杂，可以边权下放点权，用点来表示这个点到父节点的那条边
 * 对于树上每一个点，处理这个点和他的左右子节点，将左子树和右子树分别进行处理
 * 当这整个子树一共留下j个点时，可以分配j-k-1条边给左子树，给k条边给右子树
 * 这样从二叉树的最底层开始向上处理每个点，取最大值递推到根节点就可以得到整个图中所有点的在每种状态下的最大值
 *
 * update:
 *  结合了树上DFS和DP的特点
 *  在DP之前需要对底部的节点进行处理
 *  可以直接DFS到树的最底部, 从最底部开始DP
 *  此时只有两种状态, 也就是取与不取, 代表是否删掉这条边
 *  最底部的状态最少可以直接写出状态转移方程, 取结果的最大值
 *  下一个点再根据上一个点得到的最大权重来更新这里的权重
 *
 *  一句话概括就是从下往上对树上每个节点跑一次DP
 *  dp[i][j]就表示只考虑前i个"点"(就是以i为根节点的子树), 在保留j条边(也就是j个点)的情况下的最大值
 * */

struct node {
    int v, w;    // v边的另一端，w权重
    explicit node(int v = 0, int w = 0) : v(v), w(w) {}
};

const int N = 210;
vector<node> edge[N];
int f[N][N];    // f[i][j] 以i为根的子树在保留j条边下的最大值
int sum[N];     // sum[i] 以i为根的边的数量
int n, q;

void dfs(int u, int fa) {
    for (int i = 0; i < edge[u].size(); i++) {    // 遍历u的子节点
        int v = edge[u][i].v;                     // 子节点
        int w = edge[u][i].w;                     // 权重

        if (v == fa) continue;    // 避免循环，不能让自己的子节点等于自己的父节点

        dfs(v, u);    // 先到最底层在回溯上来

        sum[u] += sum[v] + 1;                                             // 记录节点的个数
        for (int j = sum[u]; j >= 0; j--)                                 // 保留j条边的情况  倒序防止覆盖？ 因为j压缩了一维
            for (int k = 0; k <= j - 1; k++)                              // 给左右子树各分配多少条边
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[v][k] + w);    // 状态转移方程
        // 上面第二个for中 j-1 为保留根节点需要的一条边，对应的下面代表左边整块的也是 j-k-1
    }
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    cin >> n >> q;
    for (int i = 1; i < n; i++) {    // n-1条边
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].emplace_back(v, w);    // 双向边
        edge[v].emplace_back(u, w);
    }

    dfs(1, 0);    // 以1为根节点开始DP

    cout << f[1][q] << '\n';    // 以1点为子节点，留下q条边时的最大值
    return 0;
}


// https://www.luogu.com.cn/problem/P2015
// update: 2024年3月21日