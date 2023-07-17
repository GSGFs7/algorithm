#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

/*
 * 广搜走迷宫
 * 普通的BFS，注意图的双层结构和题意
 *
 * 注意题意：一到传送门就会被传走，不可取消，所以不可以经过传送门而不进去
 * */

typedef pair<pair<int, int>, int> PIII;
const int N = 20;
char g[2][N][N];// 层数，x轴长度，y轴长度
int a[2][N][N];
int n, m, t;
PIII princess;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs()
{
    queue<PIII> q;
    q.push({{0, 1}, 1});

    while (!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            const int cur = now.first.first;
            const int xx = now.first.second + dx[i];
            const int yy = now.second + dy[i];

            if (xx == 0 || xx == n + 1 || yy == 0 || yy == m + 1 || g[cur][xx][yy] == '*') continue;

            if (g[cur][xx][yy] == '#') {// 一进时空传送机就会被传走，卡了半个下午才看到!!!
                // 只能传空地，传送机传传送机也会卡死
                if (g[!cur][xx][yy] == '.' && a[!cur][xx][yy] > a[cur][now.first.second][now.second] + 1) {
                    a[!cur][xx][yy] = a[cur][now.first.second][now.second] + 1;
                    q.push({{!cur, xx}, yy});
                }
            }
            else {
                if (a[cur][xx][yy] > a[cur][now.first.second][now.second] + 1) {
                    a[cur][xx][yy] = a[cur][now.first.second][now.second] + 1;
                    q.push({{cur, xx}, yy});
                }
            }
        }
    }
}

void debug()
{
    for (int i = 0; i < 2; i++) {
        cout << "___cur___" << endl;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (a[i][j][k] == 0x3f3f3f3f) cout << '-' << ' ';
                else cout << a[i][j][k] << ' ';
            }
            cout << endl;
        }
    }
}

void init()
{
    memset(&a, 0x3f, sizeof a);
    a[0][1][1] = 0;
}

void solve() {
    init();

    cin >> n >> m >> t;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++) {
                cin >> g[i][j][k];
                if (g[i][j][k] == 'P') {
                    princess = {{i, j}, k};
                    g[i][j][k] = '.';// 把公主处也标记为空地，避免影响后续操作
                }
            }

    bfs();
    //debug();

    if (a[princess.first.first][princess.first.second][princess.second] <= t) puts("YES");
    else puts("NO");
}

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}


/*
14
5 5 14
S*#*.
.#...
.....
****.
...#.

..*.P
#.*..
***..
...*.
*.#..

5 5 13
S*#*.
##...
.....
****.
...#.

..*.P
..*..
***..
...*.
*.#..


5 5 10
S*#*.
.#...
....#
****.
...#.

..*.P
#.*.*
***..
...*.
*.#..

1 2 10
SP

*.

1 3 2
S#P

..#


3 3 11
S..
*#.
#..

...
.#.
.*P




5 5 11
S*#*.
.#...
.....
****.
P.*#.

..*..
#.*..
***..
...*.
*#.#.

5 5 12
S*#*.
.#...
.....
****.
P.*#.

..*..
#.*..
***..
...*.
*#.#.

5 5 12
S*#*.
.#...
.....
****.
P.*#.

..*..
#.*..
***..
...*.
*.##.

5 5 3
S*#*.
.#...
.....
****.
..*#.

.P*..
#.*..
***..
...*.
*#.#.

5 5 9
S*#*.
.#...
.....
****.
..*#.

..*..
#.*..
***..
...*.
*#.P.

4 5 7
S*#*.
...**
.#.**
****.

.*.*.
.#*..
#.#..
.#.*P

5 7 12
S*****P
.#.*#*.
**.#.*.
.*****.
.......

*******
*.#*...
***.#*#
*******
*******

3 3 3
S#P
.*.
...

.##
...
...


 YES
NO
YES
YES
YES
NO
NO
NO
NO
YES
YES
NO
YES
NO

 */

// https://acm.hdu.edu.cn/showproblem.php?pid=2102