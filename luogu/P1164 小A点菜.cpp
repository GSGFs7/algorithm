#include <iostream>
using namespace std;

/*
 * DP
 * 点菜
 * 点菜必须点满m元
 * 一共有n种菜，每种只能点一次
 * 
 * f[i][j]设为前i种菜中价格为j的种类
 * 每次枚举一种菜
 * 针对每种菜枚举所有可能的价格，因为价格可能会由中间值得到，所以中间值也需要算出来
 * 当v[i]==j时直接加1
 * 当v[i]<j时继承上一个值在加上中间值
 * 当v[i]>j时不能加上这道菜
 * 最后的f[n][m]即为答案
 * */

const int N = 1100;
int v[N], f[N][N];// f[i][j]表示在前i种菜中价格等于j的种类

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (v[i] == j) f[i][j] = f[i - 1][j] + 1;// 如果第i道菜的价格等于j，那么价格等于j的方案发直接加上1
            if (v[i] < j) f[i][j] = f[i - 1][j - v[i]] + f[i - 1][j];// 如果第i道菜的价格小于m，
            // 继承上一个j的同时加上可以凑出j的方案
            if (v[i] > j) f[i][j] = f[i - 1][j];// 如果大于j就不能凑出j，直接继承
        }

    cout << f[n][m] << endl;
    // dbg
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
     */
    return 0;
}


// https://www.luogu.com.cn/problem/P1164