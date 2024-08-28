#include <iostream>
using namespace std;

/*
 * 求一个素数可以又哪些素数组成，输出方案数
 * 每个素数都可以无限次取，是一个完全背包问题
 * 每次加入一个素数（可以重复）时
 * */

const int N = 1010;
bool isNotPrimes[N];
int primes[N];
long long f[N];
int cnt = 0;

/// 线性筛
void getPrimes()
{
    for (int i = 2; i < N; i++)
    {
        if (!isNotPrimes[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= N / i; j++)
        {
            isNotPrimes[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    getPrimes();

    f[0] = 1;
    for (int i = 2; i <= n; i++)
        if (!isNotPrimes[i])// 如果是质数就可以取这个值
            for (int j = i; j <= n; j++)
                f[j] += f[j -i];// 取这个素数，结果为减去这个素数的方案数加上其他方案的个数

    cout << f[n] << endl;

    // debug
    // for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    return 0;
}