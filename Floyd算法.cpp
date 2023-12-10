#include <bits/stdc++.h>
using namespace std;

/*
 * Floyd
 * 多源最短路，可以求得任意两点间的最短路
 * 时间复杂度O(n^3)
 *
 * 核心思想：动态规划
 * 定义三维数组 f[k][x][y]
 * f[k][x][y] 为考虑前k个点时x到y的最短路 （从x经过k到y是否会使距离缩短）
 * f[k][x][y]=min(f[k-1][x][y],f[k-1][x][k]+f[k-1][k][y]);
 *  f[k-1][x][y] 表示前一次的路径（也就是不包括k的情况）
 *  f[k-1][x][k]+f[k-1][k][y] 表示加入k后的路径（也就是经过k的情况）
 * 只会出现取与不取的情况，所以直接从这两个情况下取最佳结果即可（较小值）
 * 两点间的可达性：如果x到k或者k到y存在一条路不可达的情况，就会超过INF，所以小于INF的距离一定是可达的
 *
 * 其中k这一维是可以省略的，并不会参与最短路计算，单纯用于计数
 * */

const int N = 110;
int f[N][N][N];

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    memset(&f, 0x3f, sizeof f);// 初始化，0x3f避免溢出
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x < y) swap(x, y);
        f[0][x][y] = min(f[0][x][y], z);// 下面那部分，不然只有一半的图像
        f[0][y][x] = min(f[0][y][x], z);// 上面那部分
    }
    for (int i = 0; i <= n; i++) f[0][i][i] = 0;// 对角线就是到自己的长度，一定是0

    // Floyd
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                f[i][j][k] = min(f[i - 1][j][k], f[i - 1][j][i] + f[i - 1][i][k]);

    // 输出
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << f[n][i][j] << ' ';
        cout << '\n';
    }
    return 0;
}


// https://www.luogu.com.cn/problem/B3647