#include <iostream>
#include <vector>
using namespace std;

/// 看清题目
// 题目不是求个数，是求总得分数

const int N = 1010;
int a[N][N];
int n;
bool flag = false;

long long search(int x, int y)
{
    int res = 0;
    for (int i = 0; i < n; i++)// 两个循环合在一起
    {
        if (a[x][i]) res += a[x][i];// 总得分数，不是加1，是加上该点的值
        if (a[i][y]) res += a[i][y];
    }
    flag = true;
    return res;
}

int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);

    cin >> n;
    for (int i = 0, x; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> x, a[i][j] = x;

    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0) ans = max(ans, search(i, j));

    if (flag) cout << ans << endl;
    else cout << "Bad Game!";
    return 0;
}


// https://www.luogu.com.cn/problem/P2356