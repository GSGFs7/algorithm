#include <iostream>
#include <cstring>
using namespace std;

/// 太难辣！
/*
 * 题意分析：
 *  因为最多可取到一个4费，多了浪费钱
 *  取得一个四费时后面所有的2费全部成为一个定值x  交换1和2的位置...42211 变得更加直观
 *  注意：如果百合井要取出的花大于要剩下的，那么一个都取不出来，钱白花了
 *
 * 状态分析：
 *  前面为定值，只分析后半部分
 *  第一种情况，当前位置取1
 *  第二种情况，当前位置取2，这种情况可能无法完全覆盖，因为不知道有多少个2，需要枚举，更新最小值，不够的话再补情况1
 * */

const int N = 100010;
int f[N];// f[i]表示取i朵花的最小花费

int main()
{
    memset(&f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i < N; i++)// 枚举f[i]的最小值
    {
        f[i] = min(f[i], f[i - 1] + 1);// 情况1
        for (int j = 2; j * i < N; j++)// 由f[i/j] + 4 + 2 * (j -1)变形得到，每次取整数倍，减少计算量
            f[i * j] = min(f[i * j], f[i] + 4 + 2 * (j - 1));// 情况2，不断向后枚举
        /* i*j表示4费标记的数量，j表示2的个数 */
    }

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; cases ++)
    {
        int n;
        cin >> n;
        printf("Case #%d: %d\n", cases, f[n]);
    }
    return 0;
}


// https://www.acwing.com/problem/content/4744/