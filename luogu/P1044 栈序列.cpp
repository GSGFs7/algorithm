#include <iostream>
using namespace std;

unsigned long long n, f[20][20];// f数组表示已经计算过的数
/*
 * 需要画表格理解
 * 当输入3时
 * 0 1 2 5
 * 1 2 5 _
 * _ 2 _ _
 * _ _ _ _
 * 当a=0时返回1
 * a[0][2]的3返回给a[1][2]，同时a[2][1]从a[1][1]处取得的2返回给a[2][1]，最后返回给起点a[3][0]
 */
unsigned long long dfs(unsigned long long x, unsigned long long y)// x是队列里的数的个数，y是栈里的数的个数
{
    if (f[x][y] != 0) return f[x][y];// 当f里有计算过的数时直接用f里的数值
    if (x == 0) return 1;// 空栈时只有一种方式，取出
    if (y > 0) f[x][y] += dfs(x, y - 1);// 出栈
    f[x][y] += dfs(x - 1, y + 1);// 入栈
    return f[x][y];
}

int main()
{
    cin >> n;
    cout << dfs(n, 0) << endl;
    return 0;
}

// 卡特兰数
// https://www.luogu.com.cn/problem/P1044
// https://leetcode.cn/circle/article/lWYCzv/

/*
#include <iostream>
using namespace std;

int n, f[30];
int main()
{
    cin >> n;
    f[0] = 1, f[1] = 1;

    // 递推
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            f[i] += f[j] * f[i - j - 1];

    cout << f[n];
    return 0;
}
*/

