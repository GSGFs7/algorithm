#include <iostream>
using namespace std;

/// 前缀和 && 双指针
/*
 * 正常处理子矩阵需要依次枚举四条边n^4级
 * 题目数据限制，需要优化到n^3级
 * 上下边界可暴力枚举
 * 左右边界可通过两个指针维护优化到n^3级
 * */

const int N = 510;
int s[N][N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j], s[i][j] += s[i - 1][j];

    long long ans = 0;
    for (int i = 1; i <= n; i ++)// 上边界
        for (int j = i; j <= n; j ++)// 下边界
            for (int l = 1, r = 1, sum = 0; r <= m; r ++)
            {
                sum += s[j][r] - s[i - 1][r];
                while (sum > k)
                {
                    sum -= s[j][l] - s[i - 1][l];
                    l ++;
                }
                ans += r - l + 1;// 避免因为范围扩大而没加入后面几列的组合，因为l并不是每次增加一的
            }
    cout << ans << endl;
    return 0;
}

// https://www.luogu.com.cn/problem/P8783
// https://www.acwing.com/solution/content/110471/