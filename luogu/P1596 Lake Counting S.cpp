#include <iostream>
using namespace std;

// dfs暴搜，判断连通块

char a[120][120];// 会炸数组
int n, m;
int ans = 0;

void dfs(int x, int y)
{
    a[x][y] = '.';
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            int dx = x + i;
            int dy = y + j;
            if (a[dx][dy] == 'W') dfs(dx, dy);// 查找八个方向上的'W'，并消去
        }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%s", a[i]);// 读入一整行，防止换行引起的错误
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'W') dfs(i, j), ans ++;// 遍历数组，找到'W'并计数，dfs消去'W'
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1596