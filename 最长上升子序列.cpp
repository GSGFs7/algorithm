#include <iostream>
using namespace std;

/// 最长上升子序列
/*
 * 状态表示：
 *  集合：以第i个数结尾的上升子序列的集合
 *  属性：Max
 * 状态计算：
 *  以上一位数取的值为状态
 *  以j结尾的最大值加上1
 *  f[i] = max(f[j]+1),    j=0,1,2,3,4...i-1
 * */

const int N = 1010;
int a[N], f[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;// 最少都有1个（这个数自己）
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])// 如果小于就加在这个数后面，取一次最大值   a[i]才是后面那个数！
                f[i] = max(f[i], f[j] + 1);// 每次取值不能小于1
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);// 寻找最大值

    cout << res << endl;
    return 0;
}