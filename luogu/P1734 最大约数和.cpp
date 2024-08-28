#include <iostream>
using namespace std;

const int N = 1010;
int g[N], f[N];

int get_g(int i)
{
    int sum = 0;
    for (int j = 1; j < i; j++)
        if (!(i % j)) sum += j;// 约数和，不是约数个数，最近怎么一直不在状态
    return sum;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        g[i] = get_g(i);

    // 01背包选取最大值
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= i; j--)
            f[j] = max(f[j], f[j - i] + g[i]);

    cout << f[n] << endl;
    //for (int i = 1; i <= n; i++) cout << g[i] << ' ';
    //cout << endl;
    //for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    return 0;
}


// https://www.luogu.com.cn/problem/P1734