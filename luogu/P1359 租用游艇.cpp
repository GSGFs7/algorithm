#include <iostream>
using namespace std;

/*
 * 根据题目要求用DP模拟
 * 题目给出从i到后面各点的值
 * 用DP更新结果并存储，并且保证结果最小
 * */

const int N = 200;
int f[N];// f[i]表示从起点到i点的最小价格方案

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)// 单段路程的起点
        for (int j = i + 1, x; j <= n; j++)// 单段路程的终点
        {
            cin >> x;
            // 找到比上一个答案更小的值就用那个值替换，保证经过次轮后得到的答案就是最小值
            if (f[i] == 0 || f[i] + x < f[j])// 状态转移方程
                f[j] = f[i] + x;
        }
    cout << f[n] << endl;
    return 0;
}


// https://www.luogu.com.cn/problem/P1359