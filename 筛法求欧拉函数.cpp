#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int primes[N], cnt;
int euler[N];
bool st[N];// state状态

long long get_euler(int n)// 线性筛+欧拉函数
{
    euler[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])// 如果没有被筛过，质数
        {
            primes[cnt ++] = i;
            euler[i] = i - 1;// 质数的欧拉函数是p-1
        }
        for (int j = 0; primes[j] <= n / i; j++)// 枚举质数
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                euler[primes[j] * i] = euler[i] * primes[j];// 与质因子的次数无关
                break;
            }
            euler[primes[j] * i] = euler[i] * (primes[j] - 1);
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) res += euler[i];
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << get_euler(n) << endl;
    return 0;
}