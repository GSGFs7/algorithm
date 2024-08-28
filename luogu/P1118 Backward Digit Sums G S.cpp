#include "iostream"
using namespace std;

/*
 * 杨辉三角形+DFS
 *
 * n个数字相邻的两两相加，得到m，求原数组（由1~n组成）
 *
 * 简单计算可得，当n=4时
 * 序列       3 1 2 4
 * 分别要计算  1 2 2 1   次
 *
 * 杨辉三角形
 * */

const int N = 20;
int n, m;
int p[N];
int path[N];
bool vis[N];

void DFS(int cur, int sum)
{
    // 剪枝，最优性剪枝，如果前面的数已经大于结果那么就不用算下去了
    if (sum > m)
        return ;

    // 如果搜到底
    if (cur == n)
    {
        if (sum == m)
        {
            for (int i = 0; i < cur; i++) cout << path[i] << ' ';
            exit(0);
        }
        return ;
    }

    // DFS字典序枚举
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            path[cur] = i;
            DFS(cur + 1, sum + p[cur] * i);// cur也是从0开始
            vis[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    p[0] = p[n - 1] = 1;

    // 求杨辉三角的某一行
    if (n > 1)
        for (int i = 1; i * 2 < n; i++)
            p[i] = p[n - i - 1] = (n - i) * p[i - 1] / i;

    // debug
//    for (int i = 0; i < n; i++)
//        cout << p[i] << ' ';

    DFS(0, 0);

    return 0;
}


// https://www.luogu.com.cn/problem/P1118