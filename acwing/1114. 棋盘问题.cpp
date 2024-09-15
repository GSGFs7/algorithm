#include <iostream>
using namespace std;

// 在一个棋盘的几个点上放棋子
// 类似八皇后问题的改版

const int N = 10;
int n, k;
char g[N][N];
int ans = 0;
bool line[N];
int m = 0;// 棋子数

void dfs(int u)
{
    if (m == k) { ans++; return ; }// 当棋子成功放完时记录

    if (u == n) return;// 防止越界

    /// 当这一行放棋子时的情况
    for (int i = 0; i < n; i++)// 扫描每列，看是否可以放棋子
    {
        if (!line[i] && g[u][i] == '#')// 这一列不能有棋子，并且这个点可以放棋子
        {
            line[i] = true;
            m ++;// 记录已经放了的棋子的个数
            dfs(u + 1);
            line[i] = false;
            m --;
        }
    }

    /// 这行不放棋子时的情况
    dfs(u + 1);// 可能也有这行不放的情况
}

int main()
{
    while (true)
    {
        cin >> n >> k;
        if (n == -1 && k == -1) break;

        // 读图
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> g[i][j];

        dfs(0);

        cout << ans << endl;
        ans = 0;
    }
    return 0;
}


//