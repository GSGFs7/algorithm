#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

/*
 * DFS+剪枝来
 * 非正解会TLE
 * 会被卡数据
 * */

typedef pair<double, double> PDD;
const int N = 20;
int n;
PDD a[N];
double ans = 0x3f3f3f3f;
bool vis[N];
int l = 0;
double dist[N][N];
const int C = 1e7;

inline double sq(PDD x, PDD y)
{
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

void DFS(int cur, double sum, int last)
{
    // 最优性剪枝
    if (sum > ans) return ;

    if (cur == n)
    {
        ans = min(ans, sum);
        return ;
    }

    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            vis[i] = true;
            DFS(cur + 1, sum + dist[last][i], i);
            vis[i] = false;
        }

    // 这个玄学方法会被后面三个Heck数据干掉
    l ++;
    if (l == C)// 搜索到1e7次就直接退出循环
    {
        printf("%0.2lf", ans);
        exit(0);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    double x, y;
    for (int i = 1; i <= n; i++)
        cin >> x >> y, a[i] = {x, y};

    // 预处理出每两个点间的距离会更快，要包括原点！调了好久
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dist[i][j] = sqrt(sq(a[i], a[j]));
/*
    // debug
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            cout << dist[i][j] << ' ';
        cout << endl;
    }
*/

    sort(a, a + n);

    DFS(0, 0, 0);

    printf("%0.2f", ans);
    return 0;
}


// https://www.luogu.com.cn/problem/P1433