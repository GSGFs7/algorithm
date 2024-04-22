#include <iostream>
#include <unordered_map>
using namespace std;

/// 约数的个数
/*
 * 约数个数定理
 * 分解出每个质数的个数加一再相乘
 *
 * 72 = 2^3 * 3^2
 * 通过 p = 2^x * 3^y造合数
 * 排列组合的乘法原理
 * x可以从0取到3，y可以从0取到2
 * 妙啊！
 * */

typedef long long LL;
const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> primes;    // 哈希表
    while (n--) {
        int x;
        cin >> x;

        // 分解质因数
        for (int i = 2; i <= x / i; i++)
            while (x % i == 0) {
                x /= i;
                primes[i]++;    // 统计次数
            }

        if (x > 1) primes[x]++;    // 他本身也是一个约数
    }

    LL res = 1;
    for (auto p : primes) res = res * (p.second + 1) % mod;

    cout << res << endl;
    return 0;
}