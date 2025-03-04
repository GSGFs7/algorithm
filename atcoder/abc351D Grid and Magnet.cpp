#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

using namespace std;

/*
 * 给出一个只包含*和#的图，在#旁边不可以再移动
 * 任选图中一个点出发，最多能抵达的区域有多少个
 *
 * 枚举起点的复杂度O(nm) 跑bfs的复杂度O(nm)
 * 总复杂度O((nm)^2)级 n和m都是1000量级的 正常写法一定会TLE 被T飞了
 * 优化1：
 *  可以使用时间戳来替代vis中的bool值，这样就不会每次都需要重新写整个vis了
 *  为什么需要重置vis呢，因为两个无法走通的区域可能公用同一个区域
 * 优化2：
 *  使用停止点来代替#，避免重复计算这个点的四周
 * 优化3：
 *  只要这个点被找过就不需要再找了，因为找过的点必定是在同一个连通块中的
 *  同一个连通块间的结果是相同的
 * */

const int N = 1010;
string s[N];
int vis[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] = ' ' + s[i];

    int ans = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    // 寻找停止点
    vector<vector<int>> stop(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                stop[i][j] = 1;
                for (int k = 0; k < 4; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (xx < 1 || xx > n) continue;
                    if (yy < 1 || yy > m) continue;
                    stop[xx][yy] = 1;
                }
            } else {
                ans = 1;
            }
        }
    }

    auto bfs = [&](int x, int y, int times) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = times;

        int res = 0;
        while (!q.empty()) {
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();
            res++;

            // cout << nx << ' ' << ny << '\n';

            // 如果这个点不能走向其他点
            if (stop[nx][ny]) continue;

            for (int i = 0; i < 4; i++) {
                int xx = nx + dx[i];
                int yy = ny + dy[i];

                if (xx < 1 || xx > n) continue;
                if (yy < 1 || yy > m) continue;
                if (vis[xx][yy] == times) continue;

                vis[xx][yy] = times;
                q.push({xx, yy});
            }
        }
        return res;
    };

    int times = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (stop[i][j]) continue;
            if (vis[i][j]) continue;    // 避免访问同一个连通块

            int tmp = bfs(i, j, ++times);
            ans = max(ans, tmp);
            // cout << "tmp: " << tmp << "x, y: " << i << ' ' << j << '\n';
        }
    }
    cout << ans << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
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


// https://atcoder.jp/contests/abc351/tasks/abc351_d
// 2024-10-10
