#include <stdio.h>

/*
 * DP
 * 求最大可放下的容量
 * 对于每个容量j
 * 每个物品i都遍历一次最大容量m
 * 试试能够放下第i个物品的最大位置
 * 将找到的值加上第i的值
 * 直接给这个位置赋值
 * 这样每个步骤取最大值
 * 如果减去后小于0就继承上一个值
 * */

/*
 * 对于样例
 * 24
 * 6
 * 8
 * 3
 * 12
 * 7
 * 9
 * 7
 *
 * NO:           1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
 * 第一次，加入8： 0  0  0  0  0  0  0  8  8  8  8  8  8  8  8  8  8  8  8  8  8  8  8  8
 * 第二次，加入3： 0  0  3  3  3  3  3  8  8  8  11 11 11 11 11 11 11 11 11 11 11 11 11 11
 * 第三次，加入12：0  0  3  3  3  3  3  8  8  8  11 12 12 12 15 15 15 15 15 20 20 20 23 23
 * 第四次，加入7： 0  0  3  3  3  3  7  8  8  10 11 12 12 12 15 15 15 18 19 20 20 22 23 23
 * 第五次，加入9： 0  0  3  3  3  3  7  8  9  10 11 12 12 12 15 16 17 18 19 20 21 22 23 24
 * 第六次，加入7： 0  0  3  3  3  3  7  8  9  10 11 12 12 14 15 16 17 18 19 20 21 22 23 24
 * */


/// 二维写法
/*
const int N = 20010, M = 50;
int f[N][N], w[N];

int max(int a, int b)
{ return a > b ? a : b; }

int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)// 二维从前开始向后枚举，与一维相反
        {
            if (j < w[i]) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + w[i]);
        }
    printf("%d\n", m - f[n][m]);

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++)
//            printf("%-3d", f[i][j]);
//        puts("\n");
//    }

    return 0;
}
*/


const int N = 20010, M = 50;
int f[N], w[M];

int max(int a, int b)
{ return a > b ? a : b; }

int main()
{
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + w[i]);

        // debug
        //for (int j = 1; j <= m; j++)
        //    printf("%d", f[i]);
        //puts("");

        // 因为每次判断都只会影响到w[i]后面的数
        // 所以只需要判断后面的数即可
        // 又因为从前开始可能会导致覆盖，后面需要未更新的值会发生错误
        // 所以从后面开始
    }
    printf("%d", m - f[m]);
    return 0;
}


// https://www.luogu.com.cn/problem/P1049