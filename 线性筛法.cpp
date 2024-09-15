#include <iostream>
using namespace std;

// 求 1~n 中有多少个质数
// 质数筛：列出所有的数，从前开始遍历，删掉这个数的所有的倍数，没有被删掉的数就是质数
// 时间复杂度：
// 2/n+3/n+...+n/n 调和级数
// = n(1/2+1/3+...+1/n)
// = lnn + c   c为欧拉常数
// 约等于nlogn
// 质数定理： 1~n 中有n/lnn个质数

const int N = 1e6 + 10;
int primes[N];
bool st[N];
int cnt = 0;

/// 线性筛法
// 数据范围超1e7时优化会明显大于埃氏筛
// n只会被最小质因子筛掉，也就是每个数只会被筛一次，优化了运行效率
void get_prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) primes[cnt ++] = i;// 保存质数，跳过合数
        for (int j = 0; primes[j] <= n / i; j++)// 从小到大枚举所有的由这些质数，用质数组成合数
        {
            // primes[j]一定是最小质因子
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
            // i % primes[j] == 0时primes[j]一定是i的最小质因子
            // i % primes[j] != 0时primes[j]一定小于i的所有质因子，primes[j]一定也是primes[j]*i的最小值
        }
    }
}

int main()
{
    int n;
    cin >> n;

    get_prime(n);

    cout << cnt << endl;
    return 0;
}