#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unsigned long int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if (i == j) a += (n - i) * (m - j);
                // 第一个为1*1，第二个为2*2+1，第三个为3*3+5，以此类推，每个正方形都是 上一个边长的正方形 加上 最小正方形的个数
            else b += (n - i) * (m - j);
            // 所有矩形的个数等于正方形加长方形
        }
    }
    cout << a << ' ' << b << endl;
}

// https://www.luogu.com.cn/problem/P2241