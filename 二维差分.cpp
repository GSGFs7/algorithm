#include "bits/stdc++.h"

using namespace std;
#define int long long

/*
 * 给出一个n*n的矩形，选择两个点，被这两个点划定的矩形框中的值需要翻转
 *
 * 暴力必定炸时间，最好的方法就是差分
 * 这个点解差分后的值就是自身的值加上 左边，上面，左上 这三个方向值
 * 基于一维差分的方法，起点标记为1，终点却不能标记为-1，因为对于(1,1)和(2,2)这对坐标来说(1,2)往后就没有限制了（(2,1)坐标同理）
 * 所以需要换一种方式，那么优先标记右上和左下，这样就框定了整个矩形的范围了
 * 但是又出现了新的问题，终点按照之前的方法加上三个方向的值就会多得到一个-1，需要再加上一个1去抵消带来的影响
 * */

const int N = 2010;
int a[N][N];

void solve() {
    int m, n;
    cin >> m >> n;
//    vector<vector<int> > a(m + 1, vector<int>(m + 1, 0)); 下面标记差分的时候会出现奇怪的bug
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        a[x1][y1] ++;           // 左上角
        a[x1][y2 + 1] --;       // 右上角
        a[x2 + 1][y1] --;       // 左下角
        a[x2 + 1][y2 + 1] ++;   // 右下角
    }

    // debug
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= m; j++)
//            cout << a[i][j];
//        cout << '\n';
//    }
//    cout << '\n';

    /// 差分还原
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] + a[i - 1][j - 1];

    /// 输出，判断翻转次数的奇偶性
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] & 1) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}


// https://www.acwing.com/problem/content/5399/