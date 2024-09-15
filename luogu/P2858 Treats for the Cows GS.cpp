/// 记忆化搜索
/*
#include <iostream>
using namespace std;

const int N = 2010;
int v[N], f[N][N];

int dfs(int day, int l, int r)
{
    if (l > r) return 0;
    if (f[l][r]) return f[l][r];

    return f[l][r] = max(dfs(day + 1, l + 1, r) + day * v[l], dfs(day + 1, l, r - 1) + day * v[r]);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    dfs(1, 1, n);
    cout << f[1][n] << endl;

    // debug
    // for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= n; j++)
    //        cout << f[i][j] << ' ';
    //    cout << endl;
    // }

    return 0;
}
*/

// 推出区间dp
#include <iostream>
using namespace std;

/*
 * 有一个队列，每次只能从两端拿出物品
 * 在第j天拿出物品那么它的价值就是 物品价值*j
 * 求最大堆价值和
 * */

const int N = 2010;
int f[N][N], v[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++)// 初始化，f[i][i]表示最后拿的时候的值
        f[i][i] = v[i] * n;

    for (int i = 1; i <= n; i++)// 枚举区间长度
        for (int j = 1; j <= n; j++)// 枚举区间起点，知道长度和起点就可以推出区间终点
        {
            int const k = i + j - 1;// 区间终点
            if (k > n) break;// 可能会越界
            f[j][k] = max(f[j + 1][k] + v[j] * (n - i + 1), f[j][k - 1] + v[k] * (n - i + 1));// 状态转移方程
            // 一个更大的区间由组成他的子区间组成，原子区间l-1或者r+1，再在子区间的基础上加上天数得到的收益
        }

    cout << f[1][n] << endl;// 左端点为1，右端点为n的情况下的最大值，也就是题目要求的最大值
/*
    for (int i = 1; i <= n ;i++)
    {
        for (int j = 1; j <= n; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
    */
    return 0;
}


// https://www.luogu.com.cn/problem/P2858