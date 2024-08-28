#include <iostream>
#include <iomanip>// setw()的头文件

using namespace std;

const int N = 22;
int path[N];// 存储答案
int n, r;

/// dfs深搜记录层数和最小值
void dfs(int cur, int last)
{
    if (cur == r)// 搜索到答案直接输出
    {
        for (int i = 0; i < r; i++)
            cout << setw(3) << path[i];// 题目要求设置场宽
        cout << endl;
        return ;
    }

    for (int i = last + 1; i <= n; i++)// 此层所有可能的取值
        path[cur] = i, dfs(cur + 1, i);
}

int main()
{
    cin >> n >> r;

    dfs(0, 0);

    return 0;
}


// https://www.luogu.com.cn/problem/P1157