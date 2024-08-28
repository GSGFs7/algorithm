#include <functional>
#include <iostream>
#include <vector>

using namespace std;

/*
  求一个n*n的矩阵中有多少个不同的曼哈顿距离, 输出组成这些距离的点

  思路:
    对于2*2的矩阵, 如果两个点相邻的话曼哈顿距离就是1, 如果在对角线上就是2
    在n*n的矩阵的对角线上就是2*i, 如果加入最开始的点旁边那个点就是2*i-1
    明显, 靠这两个点加对角线就可以组合出所有的曼哈顿距离
*/

void solve() {
    int n;
    cin >> n;
    cout << "1 1\n1 2\n";
    for (int i = 3; i <= n; i++) cout << i << ' ' << i << '\n';    // 对角线
    cout << '\n';
}

signed main() {
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1968/problem/E
// 2024年5月3日