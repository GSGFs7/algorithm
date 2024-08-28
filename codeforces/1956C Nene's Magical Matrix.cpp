#include <iostream>

/*
  给出一个n, 每次可选择n*n的矩阵中的一行或是一列, 将这列改成任意的1~n的排列
  求使矩阵中的值的和最大的操作

  思路:
    贪心
    想要最大化矩阵中元素的和最后的结果一定是类似于
    n=3:
        1 2 3
        2 2 3
        3 3 3
    上面这样的, 最大只能这样了
    这样的推法可由先排3列123, 再排2行123, 最后再排1列123得到
    但还是这个做法还是有个问题, 就是这个做法并不是最简的
    最简的做法是基于贪心的, 在覆盖的时候尽量减少对于大数的覆盖
    类似于:
        3 2 1
        0 0 0
        0 0 0

        3 2 1
        2 0 0
        1 0 0

        3 3 1
        2 2 0
        1 1 0

        3 3 1
        3 2 1
        1 1 0

        3 3 3
        3 2 2
        1 1 1

        3 3 3
        3 2 2
        3 2 1
    只需要n+n-1步, 原本则需要n^2-1步
*/

using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            sum += max(i, j);    // 矩阵的最大和

    cout << sum << ' ' << n + (n - 1) << '\n';

    int cnt = 1;
    cout << "1 1 ";
    for (int i = n; i; i--) cout << i << ' ';// 第一次操作不是成对的
    cout << '\n';
    while (cnt < n) {
        cnt++;

        // 行操作
        cout << "1 " << cnt << ' ';
        for (int i = n; i; i--) cout << i << ' ';
        cout << '\n';
        // 列操作
        cout << "2 " << cnt << ' ';
        for (int i = n; i; i--) cout << i << ' ';
        cout << '\n';
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


// https://codeforces.com/contest/1956/problem/C