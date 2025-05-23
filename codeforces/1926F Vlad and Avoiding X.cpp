#include <functional>
#include <iostream>

using namespace std;

/*
  给出一个7*7的矩阵, 有一部分是黑色的, 求最少翻转几个格子可以消除全部的黑色的X
  如:
    BWB
    WBW
    BWB
    这个3*3的矩阵中的B就表示一个X

  思路:
    暴搜+奇偶剪枝
*/

void solve() {
    string s[8];
    for (int i = 1; i <= 7; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    int ans[2] = {1000000000, 1000000000};
    // DFS搜索每个点, 看是否符合要求, (x,y)表示X中心点的坐标
    function<void(int, int, int)> dfs = [&](int x, int y, int cnt) {
        // 如果搜出界了, 搜索结束
        if (x >= 7) {
            ans[y % 2] = min(ans[y % 2], cnt);
            return;
        }

        // 如果只是出了右边界, 换到下面继续搜索
        if (y >= 7) {
            dfs(x + 1, 2 + !(y % 2), cnt);
            return;    // 原本已经出界了, 需要返回
        }

        // 需要找到一个最少的方法删掉一个B
        if (s[x - 1][y - 1] == 'B' && s[x][y] == 'B' && s[x + 1][y - 1] == 'B'
            && s[x + 1][y + 1] == 'B' && s[x - 1][y + 1] == 'B') {
            // 删左上角
            s[x - 1][y - 1] = 'W';
            dfs(x, y + 2, cnt + 1);
            s[x - 1][y - 1] = 'B';

            // 删右上角
            s[x - 1][y + 1] = 'W';
            dfs(x, y + 2, cnt + 1);
            s[x - 1][y + 1] = 'B';

            // 删左下角
            s[x + 1][y - 1] = 'W';
            dfs(x, y + 2, cnt + 1);
            s[x + 1][y - 1] = 'B';

            // 删右下角
            s[x + 1][y + 1] = 'W';
            dfs(x, y + 2, cnt + 1);
            s[x + 1][y + 1] = 'B';

            // 删中心点?
            s[x][y] = 'W';
            dfs(x,y + 2, cnt + 1);
            s[x][y] = 'B';
        } else {    // 必须不能删才到下一个点!!!
            dfs(x, y + 2, cnt);
        }
    };

    dfs(2, 2, 0);
    dfs(2, 3, 0);
    cout << ans[0] + ans[1] << '\n';
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


// https://codeforces.com/contest/1926/problem/F
// 2024年5月12日
// 1078 ms 	16 KB (时限4S)