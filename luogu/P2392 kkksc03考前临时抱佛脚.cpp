#include <iostream>
using namespace std;

// 左右同时运行，找到一个所花时间最小的答案

const int N = 20;
const int MAX = 0x3f3f3f3f;
int s[4];// 四个科目的题目数量
int a[4][N];// 对应的时间
int ans = 0;
int minn;// 每次搜索最小的可取值
int Left = 0, Right = 0;// 左右的运行时间

void search(int n, int k)// n表示第几个科目，k表示第几道题
{
    if (k == s[n])// 如果搜索完毕
    {
        minn = min(minn, max(Left, Right));// 取答案的较小值
        return ;
    }

    /// 暴力枚举
    // 先枚举出左边的所有值
    Left += a[n][k];
    search(n, k + 1);
    Left -= a[n][k];

    // 回溯后在依次枚举右边的值，可以确保每个答案都被枚举到
    Right += a[n][k];
    search(n, k + 1);
    Right -= a[n][k];
}

int main()
{
    for (int & i : s)
        cin >> i;

    for (int i = 0; i < 4; i++)
    {
        minn = MAX;// 初始化

        for (int j = 0; j < s[i]; j++)
            cin >> a[i][j];

        search(i, 0);

        ans += minn;
    }
    cout << ans << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P2392