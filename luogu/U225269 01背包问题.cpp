#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N], v[N], w[N];

int main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)// 表示进行到第几个物品
        for (int j = 0; j <= m; j++) {// 表示当容量最大为j时的状态，最大可以放下多少
            if (v[i] <= j)// 如果当前状态能够放下第i个物品，就进行尝试，取最大的结果
                // 以放满的角度来看，能够用之前求出的最大值来继续求当前位置的最大值，保证每个都是最大值
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            else
                f[i][j] = f[i - 1][j];// 如果放不下就依然是之前的放法
        }


    // debug
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= m; j++)
//            cout << f[i][j] << ' ';
//        cout << '\n';
//    }

    cout << f[n][m];
    return 0;
}


// https://www.luogu.com.cn/problem/U225269