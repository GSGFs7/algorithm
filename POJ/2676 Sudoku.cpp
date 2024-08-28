#include <iostream>
using namespace std;

/*
 * 数独游戏
 * 直接从(0,0)开始搜索，遇到0就DFS向下一层（需要判断可行性），如果搜到底就输出结果 （相当暴力）
 *
 * 《算法竞赛》中推荐的优化：优化搜索顺序剪枝。先搜容易确定的行（0最少的行）
 * */

const int N = 10;
int g[N][N];
bool flag = false;

bool check(int x, int y, int n)
{
    // 当前列
    for (int i = 0; i < 9; i++)
        if (g[x][i] == n) return false;

    // 当前行
    for (int i = 0; i < 9; i++)
        if (g[i][y] == n) return false;

    // 当前九宫格
    int x1 = x - (x % 3);
    int y1 = y - (y % 3);
    for (int i = x1; i < x1 + 3; i++)
        for (int j = y1; j < y1 + 3; j++)
            if (g[i][j] == n) return false;

    // 如果都没问题那就可行
    return true;
}

/// 输出答案
void print()
{
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << g[i][j];
        cout << '\n';
    }
}

void DFS(int x, int y)
{
    if (flag || x == 9)// 已经搜到结果或搜到底
    {
        flag = true;
        print();
        return ;
    }

    while (g[x][y])// 向后搜索
    {
        if (y == 8)
            x ++, y = 0;
        else
            y ++;

        if (x == 9)// 搜到底
        {
            flag = true;
            print();
            return ;
        }
    }

    // 找到空位后开始填数字
    for (int i = 1; i <= 9; i++)
    {
        if (check(x, y, i) && !flag)// 这里也要记得判断是否已经搜到答案，不然会继续搜下一层
        {
            g[x][y] = i;
            DFS(x, y);
            g[x][y] = 0;
        }
    }
}

void solve()
{
    flag = false; // 记得初始化！
    char c;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> c, g[i][j] = c - '0';

    DFS(0, 0);
}

int main()
{
#ifdef __LOCAL__
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    // 编译器选项添加 -D__LOCAL__ 即可完美区分本地和OJ

    int t;
    cin >> t;
    while (t --)
        solve();
    return 0;
}


// http://poj.org/problem?id=2676
// 增强版 https://www.luogu.com.cn/problem/P1074