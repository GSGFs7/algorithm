#include <bits/stdc++.h>

using i64 = long long;
const int nn = 1e6 + 10;

int h[nn];
int e[nn];
int w[nn];// 这个点指向的边（仇人）
int ne[nn];
int idx = 0;
i64 f[nn][2], vis[nn];
i64 sum = 0, n, r1, r2;

int find(int r, int u) {
    vis[u] = 1;// 到过这个点
    for (int i = h[u]; i; i = ne[i]) {
        int j = e[i];
        if (j == r) { r1 = u; return true; }// 如果找到环
        if (!vis[j] && find(r, j))return true;
    }
    return false;
}

i64 dfs(int r, int u) {
    f[u][0] = 0, f[u][1] = w[u];
    for (int i = h[u]; i; i = ne[i]) {
        int j = e[i];
        if (j == r)continue;
        dfs(r, j);
        f[u][0] += std::max(f[j][0], f[j][1]);// 状态转移方程
        f[u][1] += f[j][0];
    }
    return f[u][0];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        std::cin >> x >> y;

        // 链式前向星？
        w[i] = x;
        e[++idx] = i;
        ne[idx] = h[y]; 
        h[y] = idx;
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            r2 = i;
            if (find(i, i)) sum += std::max(dfs(r1, r1), dfs(r2, r2));
        }
    std::cout << sum << std::endl;
    return 0;
}