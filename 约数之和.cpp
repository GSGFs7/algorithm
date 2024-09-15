#include <iostream>
#include <unordered_map>
using namespace std;

/// 约数之和
/*
 * 从p的零次方加到出现次数的和再相乘
 *
 * 360 = 2^3 * 3^2 * 5^1
 * 只用2：2^0 + 2^1 + 2^3      ->m
 * 用2和3：2^0*3^1 + 2^1*3^1 + 2^2*3^1 + ... + 2^3*3^2      -> m(3^1 + 3^2)    （2的零次就表示没有2参与的情况）
 * 用2，3，5：略
 * 相加得到：m * (3^0 + 3^1 + 3^2) * (5^0 + 5^1)
 *
 * 简单来说就是:(2^0 + 2^1 + 2^2 + 2^3) * (3^0 + 3^1 + 3^2) * (5^0 + 5^1)
 * */

const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> primes;
    while (n--)
    {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i ++)
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++;
            }
        if (x > 1) primes[x] ++;
    }

    long long res = 1;
    for (auto prime : primes)
    {
        int p = prime.first, a = prime.second;
        long long t = 1;
        while (a --) t = (t * p + 1) % mod;// 秦九昭算法
        res = res * t % mod;
    }

    cout << res << endl;
    return 0;
}