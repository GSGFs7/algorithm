#include <chrono>
#include <iostream>
#include <numeric>    // iota的头文件
#include <vector>

using namespace std;
#define int long long

/*
  给出一个图, 删掉k条边, 最大化剩下的连通块的节点最小值

  思路:
    贪心+二分
    从最下面开始向上划分, 满足要求就直接给一个计数, 并且不给上方的节点返回值
    这样能经可能多的划分出连通块
    but, 从头开始枚举肯定会炸, 需要二分来辅助枚举答案(赛时就差一个二分就出来了...)
*/

const int N = 1e5 + 10;
vector<int> edge[N];
int si[N];     // 这个点的权重
int cnt;       // 统计能划出多少个连通块
int target;    // target表示剩下部分的大小

void debug() {
#ifdef __LOCAL__
    for (int i = 1; i <= 8; i++)
        cout << si[i] << '\t';
    cout << '\n';
#endif
}

void dfs(int u, int fa) {
    debug();
    // cout << '\n';

    // 先遍历自己的子节点, 等子节点划分完了后再来划分这个点
    for (auto v : edge[u]) {
        if (v == fa) continue;

        dfs(v, u);

        si[u] += si[v];
    }
    si[u]++;    // 以这个点为根的权重

    if (si[u] >= target) {    // 如果能划分就立马划分, 下一个点得到的值就是0
        si[u] = 0;
        cnt++;    // 增加一个连通块
    }
}

/**
 * @brief 代码写这里!!!
 */
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) edge[i].clear(), si[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    // 一个一个试肯定会炸, 需要二分答案
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;

        // 初始化
        target = mid;
        cnt = 0;
        for (int i = 1; i <= n; i++) si[i] = 0;    // 搞半天这里没有初始化

        dfs(1, 0);

        if (cnt >= k + 1)    // 如果满足了这个条件就是说还有上升空间
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto start = chrono::system_clock::now();

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cout << duration.count();
    return 0;
}


// https://codeforces.com/contest/1946/problem/C
// 2024年3月23日