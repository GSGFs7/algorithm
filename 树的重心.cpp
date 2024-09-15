#include <iostream>
#include <vector>
#include <chrono>
#include <map>
#include <set>

using namespace std;
#define int long long

/// 树的重心, 删掉一个点后剩下的连通块的节点大小最小的那个点
/*
 * 对于一个图直接随便找个点, 从这个点开始向其他的节点开始深搜
 * */

const int N = 1e5 + 10;
vector<int> a[N];// 图
bool vis[N];// 是否搜过这个点
int ans = 1e9;
int n;

int dfs(int cur) {
    vis[cur] = true;

    int sum = 1;// 下方点的数量
    int res = 0;// 连通块最大大小
    for (auto i : a[cur]) {
        if (!vis[i]) {
            int s = dfs(i);// 等回溯, 返回下面有多少个点
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);// 和上面的连通块比较一下, 取最大的

    ans = min(ans, res);// 找到能使最大连通块最小的点
    return sum;
}

void solve() {
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1);

    cout << ans << '\n';
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
    // cin >> t;
    while (t--)
        solve();
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
//    cout << duration.count();
    return 0;
}


// https://www.acwing.com/problem/content/848/