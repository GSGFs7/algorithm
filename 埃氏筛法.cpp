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

/// 埃氏筛法
void get_prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            for (int j = 0; j <= n; j += i) st[j] = true;// 可以放到if里面，只删掉质数的倍数
            // 优化到O(nloglogn)
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