#include <iostream>
#include <vector>

using namespace std;

/// 这道题竟然卡longlong???!!!
/*
  在一个5e5的数组中进行两种操作, 1.给a[x]加上y; 2.查询所有符合 i%x=y 的值之和

  思路:
    根号分治优化
    对于一类前端为根号复杂度的问题, 可以直接分成两段分别处理
    这样前后都可以保持根号的复杂度
    喵啊~
*/

const int N = 5e5 + 10;
const int block = 707;    // sqrt(5e5)大概在707左右
int a[N];
int f[block + 10][block + 10];    // f[i][j]表示∑(x%i=j)a[x]

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            a[x] += y;
            // 对于小范围的值, 用f来计算并存储结果, 前端的结果比较密集
            for (int i = 1; i <= block; i++) f[i][x % i] += y;
        } else {
            if (x <= block) {
                cout << f[x][y] << '\n';
            } else {
                // 对于大范围的点, 用暴力查找找结果, 因为比较分散复杂度并不高
                int res = 0;
                for (int i = y; i < N; i += x) res += a[i];
                cout << res << '\n';
            }
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


// https://codeforces.com/contest/1207/problem/F
// 2024年6月12日